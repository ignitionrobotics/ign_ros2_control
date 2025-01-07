:github_url: https://github.com/ros-controls/gz_ros2_control/blob/{REPOS_FILE_BRANCH}/doc/index.rst

.. _gz_ros2_control:

=====================
gz_ros2_control
=====================

This is a ROS 2 package for integrating the *ros2_control* controller architecture with the `Gazebo <https://gazebosim.org/home>`__ simulator.

This package provides a Gazebo-Sim system plugin which instantiates a *ros2_control* controller manager and connects it to a Gazebo model.

Usage
======


Modifying or building your own
---------------------------------

.. code-block:: shell

  cd Dockerfile
  docker build -t gz_ros2_control .

To run the demo
---------------------------------

1. Using Docker

  Docker allows us to run the demo without the GUI if configured properly. The following command runs the demo without the GUI:

  .. code-block:: shell

    docker run -it --rm --name gz_ros2_control_demo --net host gz_ros2_control ros2 launch gz_ros2_control_demos cart_example_position.launch.py gui:=false

  Then on your local machine, you can run the Gazebo client:

  .. code-block:: shell

    gz sim -g


2. Using Rocker

  To run the demo with GUI we are going to use `rocker <https://github.com/osrf/rocker/>`__ which is a tool to run docker
  images with customized local support injected for things like nvidia support. Rocker also supports user id specific files for cleaner
  mounting file permissions. You can install this tool with the following `instructions <https://github.com/osrf/rocker/#installation>`__. (make sure you meet all of the `prerequisites <https://github.com/osrf/rocker/#prerequisites>`__.

  The following command will launch Gazebo:

  .. code-block:: xml

    rocker --x11 --nvidia --name gz_ros2_control_demo gz_ros2_control:latest

  The following commands allow the cart to be moved along the rail:

  .. code-block:: xml

    docker exec -it gz_ros2_control_demo bash
    source /home/ros2_ws/install/setup.bash
    ros2 run gz_ros2_control_demos example_position


Add ros2_control tag to a URDF or SDF
==========================================

Simple setup
-----------------------------------------------------------

To use *ros2_control* with your robot, you need to add some additional elements to your URDF or SDF.
You should include the tag ``<ros2_control>`` to access and control the robot interfaces. We should
include:

* a specific ``<plugin>`` for our robot
* ``<joint>`` tag including the robot controllers: commands and states.

.. code-block:: xml

  <ros2_control name="GazeboSimSystem" type="system">
    <hardware>
      <plugin>gz_ros2_control/GazeboSimSystem</plugin>
    </hardware>
    <joint name="slider_to_cart">
      <command_interface name="effort">
        <param name="min">-1000</param>
        <param name="max">1000</param>
      </command_interface>
      <state_interface name="position">
        <param name="initial_value">1.0</param>
      </state_interface>
      <state_interface name="velocity"/>
      <state_interface name="effort"/>
    </joint>
  </ros2_control>

Using mimic joints in simulation
-----------------------------------------------------------

To use ``mimic`` joints in *gz_ros2_control* you should define its parameters in your URDF or SDF, i.e, set the ``<mimic>`` tag to the mimicked joint (see the `URDF specification <https://wiki.ros.org/urdf/XML/joint>`__ or the `SDF specification <http://sdformat.org/spec?ver=1.11&elem=joint#axis_mimic>`__)

.. code-block:: xml

  <joint name="right_finger_joint" type="prismatic">
    <axis xyz="0 1 0"/>
    <origin xyz="0.0 -0.48 1" rpy="0.0 0.0 0.0"/>
    <parent link="base"/>
    <child link="finger_right"/>
    <limit effort="1000.0" lower="0" upper="0.38" velocity="10"/>
  </joint>
  <joint name="left_finger_joint" type="prismatic">
    <mimic joint="right_finger_joint" multiplier="1" offset="0"/>
    <axis xyz="0 1 0"/>
    <origin xyz="0.0 0.48 1" rpy="0.0 0.0 3.1415926535"/>
    <parent link="base"/>
    <child link="finger_left"/>
    <limit effort="1000.0" lower="0" upper="0.38" velocity="10"/>
  </joint>

The mimic joint must not have command interfaces configured in the ``<ros2_control>`` tag, but state interfaces can be configured.


Add the gz_ros2_control plugin
==========================================

In addition to the *ros2_control* tags, a Gazebo plugin needs to be added to your URDF or SDF that
actually parses the *ros2_control* tags and loads the appropriate hardware interfaces and
controller manager. By default the *gz_ros2_control* plugin is very simple, though it is also
extensible via an additional plugin architecture to allow power users to create their own custom
robot hardware interfaces between *ros2_control* and Gazebo.

URDF:

.. code-block:: xml

  <gazebo>
    <plugin filename="libgz_ros2_control-system.so" name="gz_ros2_control::GazeboSimROS2ControlPlugin">
      <parameters>$(find gz_ros2_control_demos)/config/cart_controller.yaml</parameters>
    </plugin>
  </gazebo>

SDF:

.. code-block:: xml

  <plugin filename="libgz_ros2_control-system.so" name="gz_ros2_control::GazeboSimROS2ControlPlugin">
    <parameters>$(find gz_ros2_control_demos)/config/cart_controller.yaml</parameters>
  </plugin>

The *gz_ros2_control* ``<plugin>`` tag also has the following optional child elements:

* ``<parameters>``: A YAML file with the configuration of the controllers. This element can be given multiple times to load multiple files.
* ``<controller_manager_name>``: Set controller manager name (default: ``controller_manager``)

The following additional parameters can be set via child elements in the URDF/SDF or via ROS parameters in the YAML file above:

* ``<hold_joints>``: if set to true (default), it will hold the joints' position if their interface was not claimed, e.g., the controller hasn't been activated yet.
* ``<position_proportional_gain>``: Set the proportional gain. (default: 0.1) This determines the setpoint for a position-controlled joint ``joint_velocity = joint_position_error * position_proportional_gain``.

or via ROS parameters:

.. code-block:: yaml

  gz_ros_control:
    ros__parameters:
      hold_joints: false
      position_proportional_gain: 0.5

Additionally, one can specify a namespace and remapping rules, which will be forwarded to the controller_manager and loaded controllers. Add the following ``<ros>`` section:

URDF:

.. code-block:: xml

  <gazebo>
    <plugin filename="libgz_ros2_control-system.so" name="gz_ros2_control::GazeboSimROS2ControlPlugin">
      ...
      <ros>
        <namespace>my_namespace</namespace>
        <remapping>/robot_description:=/robot_description_full</remapping>
      </ros>
    </plugin>
  </gazebo>

SDF:

.. code-block:: xml

  <plugin filename="libgz_ros2_control-system.so" name="gz_ros2_control::GazeboSimROS2ControlPlugin">
    ...
    <ros>
      <namespace>my_namespace</namespace>
      <remapping>/robot_description:=/robot_description_full</remapping>
    </ros>
  </plugin>

Default gz_ros2_control Behavior
-----------------------------------------------------------

By default, without a ``<plugin>`` tag, *gz_ros2_control* will attempt to get all of the information it needs to interface with a ros2_control-based controller out of the URDF or SDF. This is sufficient for most cases, and good for at least getting started.

The default behavior provides the following ros2_control interfaces:

* hardware_interface::JointStateInterface
* hardware_interface::EffortJointInterface
* hardware_interface::VelocityJointInterface

Advanced: custom gz_ros2_control Simulation Plugins
-----------------------------------------------------------

The *gz_ros2_control* Gazebo plugin also provides a pluginlib-based interface to implement custom interfaces between Gazebo and *ros2_control* for simulating more complex mechanisms (nonlinear springs, linkages, etc).

These plugins must inherit the ``gz_ros2_control::GazeboSimSystemInterface``, which implements a simulated *ros2_control*
``hardware_interface::SystemInterface``. SystemInterface provides API-level access to read and command joint properties.

The respective GazeboSimSystemInterface sub-class is specified in a URDF or SDF model and is loaded when the
robot model is loaded. For example, the following XML will load the default plugin:

URDF:

.. code-block:: xml

  <ros2_control name="GazeboSimSystem" type="system">
    <hardware>
      <plugin>gz_ros2_control/GazeboSimSystem</plugin>
    </hardware>
    ...
  <ros2_control>
  <gazebo>
    <plugin name="gz_ros2_control::GazeboSimROS2ControlPlugin" filename="libgz_ros2_control-system">
      ...
    </plugin>
  </gazebo>

SDF:

.. code-block:: xml

  <ros2_control name="GazeboSimSystem" type="system">
    <hardware>
      <plugin>gz_ros2_control/GazeboSimSystem</plugin>
    </hardware>
    ...
  <ros2_control>
  <plugin name="gz_ros2_control::GazeboSimROS2ControlPlugin" filename="libgz_ros2_control-system">
    ...
  </plugin>

Set up controllers
-----------------------------------------------------------

Use the tag ``<parameters>`` inside ``<plugin>`` to set the YAML file with the controller configuration
and use the tag ``<controller_manager_prefix_node_name>`` to set the controller manager node name.

URDF:

.. code-block:: xml

  <gazebo>
    <plugin name="gz_ros2_control::GazeboSimROS2ControlPlugin" filename="libgz_ros2_control-system">
      <parameters>$(find gz_ros2_control_demos)/config/cart_controller.yaml</parameters>
      <controller_manager_prefix_node_name>controller_manager</controller_manager_prefix_node_name>
    </plugin>
  <gazebo>

SDF:

.. code-block:: xml

  <plugin name="gz_ros2_control::GazeboSimROS2ControlPlugin" filename="libgz_ros2_control-system">
    <parameters>$(find gz_ros2_control_demos)/config/cart_controller.yaml</parameters>
    <controller_manager_prefix_node_name>controller_manager</controller_manager_prefix_node_name>
  </plugin>

The following is a basic configuration of the controllers:

- ``joint_state_broadcaster``: This controller publishes the state of all resources registered to a ``hardware_interface::StateInterface`` to a topic of type ``sensor_msgs/msg/JointState``.
- ``joint_trajectory_controller``: This controller creates an action called ``/joint_trajectory_controller/follow_joint_trajectory`` of type ``control_msgs::action::FollowJointTrajectory``.

.. literalinclude:: ../gz_ros2_control_demos/config/cart_controller_position.yaml
   :language: yaml


gz_ros2_control_demos
==========================================

There are some examples in the *gz_ros2_control_demos* package.
To specify whether to use URDF or SDF, you can launch the demo in the following way (the default is URDF):

.. code-block:: shell

  ros2 launch gz_ros2_control_demos <launch file> description_format:=sdf

Cart on rail
-----------------------------------------------------------

These examples allow to launch a cart in a 30 meter rail.

.. image:: img/gz_ros2_control.gif
  :alt: Cart

You can run some of the example configurations by running the following commands:

.. code-block:: shell

  ros2 launch gz_ros2_control_demos cart_example_position.launch.py
  ros2 launch gz_ros2_control_demos cart_example_velocity.launch.py
  ros2 launch gz_ros2_control_demos cart_example_effort.launch.py

When the Gazebo world is launched, you can run some of the following commands to move the cart.

.. code-block:: shell

  ros2 run gz_ros2_control_demos example_position
  ros2 run gz_ros2_control_demos example_velocity
  ros2 run gz_ros2_control_demos example_effort

Mobile robots
-----------------------------------------------------------

.. image:: img/diff_drive.gif
  :alt: DiffBot

You can run some of the mobile robots running the following commands:

.. code-block:: shell

  ros2 launch gz_ros2_control_demos diff_drive_example.launch.py
  ros2 launch gz_ros2_control_demos tricycle_drive_example.launch.py
  ros2 launch gz_ros2_control_demos ackermann_drive_example.launch.py

When the Gazebo world is launched you can run some of the following commands to move the robots.

.. code-block:: shell

  ros2 run gz_ros2_control_demos example_diff_drive
  ros2 run gz_ros2_control_demos example_tricycle_drive
  ros2 run gz_ros2_control_demos example_ackermann_drive

To demonstrate the setup of a namespaced robot, run

.. code-block:: shell

  ros2 launch gz_ros2_control_demos diff_drive_example_namespaced.launch.py

which will launch a diff drive robot within the namespace ``r1``.

.. note::

  The ros2_control settings for the controller_manager and the controller defined in ``diff_drive_controller.yaml`` use wildcards to match all namespaces.

To run the Mecanum mobile robot run the following commands to drive it from the keyboard:

.. code-block:: shell

  ros2 launch gz_ros2_control_demos mecanum_drive_example.launch.py
  ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -p stamped:=true

Gripper
-----------------------------------------------------------

The following example shows a parallel gripper with a mimic joint:

.. code-block:: shell

  ros2 launch gz_ros2_control_demos gripper_mimic_joint_example_position.launch.py

.. image:: img/gz_gripper.gif
  :alt: Gripper

To demonstrate the setup of the initial position and a position-mimicked joint in
case of an effort command interface of the joint to be mimicked, run

.. code-block:: shell

  ros2 launch gz_ros2_control_demos gripper_mimic_joint_example_effort.launch.py

instead.

Send example commands:

.. code-block:: shell

  ros2 run gz_ros2_control_demos example_gripper


Pendulum with passive joints (cart-pole)
-----------------------------------------------------------

The following example shows a cart with a pendulum arm:

.. code-block:: shell

  ros2 launch gz_ros2_control_demos pendulum_example_effort.launch.py
  ros2 run gz_ros2_control_demos example_effort

This uses the effort command interface for the cart's degree of freedom on the rail. To demonstrate that the physics of the passive joint of the pendulum is solved correctly even with the position command interface, run

.. code-block:: shell

  ros2 launch gz_ros2_control_demos pendulum_example_position.launch.py
  ros2 run gz_ros2_control_demos example_position
