#!/usr/bin/env python3
# Copyright 2023 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
import unittest

from ament_index_python.packages import get_package_share_directory

import launch
from launch.actions import IncludeLaunchDescription
from launch.actions import RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
import launch_testing
from launch_testing.actions import ReadyToTest
from launch_testing.util import KeepAliveProc

import psutil
import pytest
import xacro


# This function specifies the processes to be run for our test
@pytest.mark.launch_test
def generate_test_description():
    # This is necessary to get unbuffered output from the process under test
    proc_env = os.environ.copy()
    proc_env['PYTHONUNBUFFERED'] = '1'

    if 'SHOW_GZ_GUI' in os.environ and os.environ['SHOW_GZ_GUI']:
        gz_gui_args = ''
    else:
        gz_gui_args = '--headless-rendering -s'
    gz_args = f'{gz_gui_args} -r -v 4 empty.sdf'

    included_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [os.path.join(get_package_share_directory('ros_gz_sim'),
                          'launch', 'gz_sim.launch.py')]),
        launch_arguments=[('gz_args', [gz_args])]
    )

    gz_ros2_control_tests_path = os.path.join(
        get_package_share_directory('gz_ros2_control_tests'))

    xacro_file = os.path.join(gz_ros2_control_tests_path,
                              'urdf',
                              'test_cart_position.xacro.urdf')
    robot_controllers = os.path.join(
            gz_ros2_control_tests_path,
            'config',
            'cart_controller_position.yaml'
    )

    print('xacro_file ', xacro_file)
    doc = xacro.parse(open(xacro_file))
    xacro.process_doc(doc)
    params = {'robot_description': doc.toxml()}

    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[params]
    )

    gz_spawn_entity = Node(
        package='ros_gz_sim',
        executable='create',
        output='screen',
        arguments=['-string', doc.toxml(),
                   '-name', 'cart',
                   '-allow_renaming', 'true'],
    )

    joint_state_broadcaster_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster'],
    )
    joint_trajectory_controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=[
            'joint_trajectory_controller',
            '--param-file',
            robot_controllers,
            ],
    )

    # Bridge
    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'],
        output='screen'
    )

    ld = launch.LaunchDescription([
        included_launch,
        bridge,
        gz_spawn_entity,
        node_robot_state_publisher,
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=gz_spawn_entity,
                on_exit=[joint_state_broadcaster_spawner],
            )
        ),
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=joint_state_broadcaster_spawner,
                on_exit=[joint_trajectory_controller_spawner],
            )
        ),
        KeepAliveProc(),
        # Tell launch to start the test
        ReadyToTest(),
    ])

    return ld


class TestFixture(unittest.TestCase):

    def test_arm(self, launch_service, proc_info, proc_output):
        proc_output.assertWaitFor('Configured and activated',
                                  process='spawner',
                                  cmd_args=['joint_trajectory_controller'],
                                  timeout=100)

        proc_action = Node(
            package='gz_ros2_control_tests',
            executable='test_position',
            output='screen',
        )

        with launch_testing.tools.launch_process(
            launch_service, proc_action, proc_info, proc_output
        ):
            proc_info.assertWaitForShutdown(process=proc_action, timeout=300)
            launch_testing.asserts.assertExitCodes(proc_info, process=proc_action,
                                                   allowable_exit_codes=[0])

    def tearDown(self):
        for proc in psutil.process_iter():
            # check whether the process name matches
            if proc.name() == 'ruby':
                proc.kill()
            if 'gz sim' in proc.name():
                proc.kill()
