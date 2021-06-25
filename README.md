# ign_ros2_control

This is a ROS 2 package for integrating the `ros2_control` controller architecture with the [Ignition Gazebo](http://ignitionrobotics.org/) simulator.
More information about `ros2_control` can be found here: https://ros-controls.github.io/control.ros.org/

This package provides an Ignition Gazebo system plugin which instantiates a `ros2_control` controller manager and connects it to a Gazebo model.

Tested on:

  - [ROS 2 Foxy](https://docs.ros.org/en/foxy/Installation.html)
  - [Ignition Edifice](https://ignitionrobotics.org/docs/edifice)

# Usage

## Video + Pictures

![](img/ign_ros2_control.gif)

## Running

### Modifying or building your own

```bash
cd Docker
docker build -t ignition_ros2_control .
```

### To run the demo

#### Using Docker

Docker allows us to run the demo without the GUI if configured properly. The following command runs the demo without the GUI:

```bash
docker run -it --rm --name ignition_ros2_control_demo --net host ignition_ros2_control ros2 launch ignition_ros2_control_demos cart_example_position.launch.py gui:=false
```

Then on your local machine, you can run the Gazebo client:

```bash
ign gazebo -g
```

#### Using Rocker

To run the demo with the GUI, we are going to use [rocker](https://github.com/osrf/rocker/), which is a tool to run docker
images with customized local support injected for things like nvidia support. Rocker also supports user id specific files for cleaner
mounting file permissions. You can install this tool with the following [instructions](https://github.com/osrf/rocker/#installation) (make sure you meet all of the [prerequisites](https://github.com/osrf/rocker/#prerequisites)).

The following command will launch Gazebo:

```bash
rocker --x11 --nvidia --name ignition_ros2_control_demo ignition_ros2_control:latest
```

The following commands allow the cart to be moved along the rail:

```bash
docker exec -it ignition_ros2_control_demo bash
source /home/ros2_ws/install/setup.bash
ros2 run ignition_ros2_control_demos example_position
```

## Add ros2_control tag to a URDF

To use `ros2_control` with your robot, you need to add some additional elements to your URDF.
You should include the tag `<ros2_control>` to access and control the robot interfaces. We should
include:

 - a specific `<plugin>` for our robot
 - `<joint>` tag including the robot controllers: commands and states.

```xml
<ros2_control name="GazeboSystem" type="system">
  <hardware>
    <plugin>ignition_ros2_control/GazeboSystem</plugin>
  </hardware>
  <joint name="slider_to_cart">
    <command_interface name="effort">
      <param name="min">-1000</param>
      <param name="max">1000</param>
    </command_interface>
    <state_interface name="position"/>
    <state_interface name="velocity"/>
    <state_interface name="effort"/>
  </joint>
</ros2_control>
```

## Add the ignition_ros2_control plugin

In addition to the `ros2_control` tags, a Gazebo plugin needs to be added to your URDF that
actually parses the `ros2_control` tags and loads the appropriate hardware interfaces and
controller manager. By default the `ignition_ros2_control` plugin is very simple, though it is also
extensible via an additional plugin architecture to allow power users to create their own custom
robot hardware interfaces between `ros2_control` and Gazebo.

```xml
<gazebo>
    <plugin filename="libignition_ros2_control.so" name="ignition_ros2_control">
      <robot_param>robot_description</robot_param>
      <robot_param_node>robot_state_publisher</robot_param_node>
      <parameters>$(find ignition_ros2_control_demos)/config/cartpole_controller.yaml</parameters>
    </plugin>
</gazebo>
```

The `ignition_ros2_control` `<plugin>` tag also has the following optional child elements:

 - `<parameters>`: YAML file with the configuration of the controllers

#### Default ignition_ros2_control Behavior

By default, without a `<plugin>` tag, `ignition_ros2_control` will attempt to get all of the information it needs to interface with a ros2_control-based controller out of the URDF. This is sufficient for most cases, and good for at least getting started.

The default behavior provides the following ros2_control interfaces:

 - hardware_interface::JointStateInterface
 - hardware_interface::EffortJointInterface
 - hardware_interface::VelocityJointInterface

#### Advanced: custom ignition_ros2_control Simulation Plugins

The `ignition_ros2_control` Gazebo plugin also provides a pluginlib-based interface to implement custom interfaces between Gazebo and `ros2_control` for simulating more complex mechanisms (nonlinear springs, linkages, etc).

These plugins must inherit the `ignition_ros2_control::GazeboSystemInterface`, which implements a simulated `ros2_control`
`hardware_interface::SystemInterface`. SystemInterface provides API-level access to read and command joint properties.

The respective GazeboSystemInterface sub-class is specified in a URDF model and is loaded when the
robot model is loaded. For example, the following XML will load the default plugin:
```xml
<ros2_control name="GazeboSystem" type="system">
  <hardware>
    <plugin>ignition_ros2_control/GazeboSystem</plugin>
  </hardware>
  ...
<ros2_control>
<gazebo>
  <plugin name="ignition_ros2_control" filename="libignition_ros2_control.so">
    ...
  </plugin>
</gazebo>
```

#### Set up controllers

Use the tag `<parameters>` inside `<plugin>` to set the YAML file with the controller configuration.

```xml
<gazebo>
  <plugin name="ignition_ros2_control" filename="libignition_ros2_control.so">
    <parameters>$(find ignition_ros2_control_demos)/config/cartpole_controller.yaml</parameters>
  </plugin>
<gazebo>
```

This controller publishes the state of all resources registered to a
`hardware_interface::StateInterface` to a topic of type `sensor_msgs/msg/JointState`.
The following is a basic configuration of the controller.

```yaml
joint_state_controller:
  ros__parameters:
    type: joint_state_controller/JointStateController
```

This controller creates an action called `/cart_pole_controller/follow_joint_trajectory` of type `control_msgs::action::FollowJointTrajectory`.

```yaml
cart_pole_controller:
  ros__parameters:
    type: joint_trajectory_controller/JointTrajectoryController
    joints:
       - slider_to_cart
    write_op_modes:
       - slider_to_cart
```
#### Executing the examples

There are some examples in the `ignition_ros2_control_demos` package. These examples allow to launch a cart in a 30 meter rail.

You can run some of the example configurations by running the following commands:

```bash
ros2 launch ignition_ros2_control_demos cart_example_position.launch.py
ros2 launch ignition_ros2_control_demos cart_example_velocity.launch.py
ros2 launch ignition_ros2_control_demos cart_example_effort.launch.py
```

Send example commands:

When the Gazebo world is launched, you can run some of the following commands to move the cart.

```bash
ros2 run ignition_ros2_control_demos example_position
ros2 run ignition_ros2_control_demos example_velocity
ros2 run ignition_ros2_control_demos example_effort
```
