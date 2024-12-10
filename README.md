# gz_ros2_control

ROS2 Distro | Build Status | Package build |
:---------: | :----: | :----------: |
[![Licence](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0) |  [![Build Status](https://build.ros2.org/buildStatus/icon?job=Jdev__gz_ros2_control__ubuntu_noble_amd64)](https://build.ros2.org/job/Jdev__gz_ros2_control__ubuntu_noble_amd64/) |  [![Build Status](https://build.ros2.org/buildStatus/icon?job=Jbin_uN64__gz_ros2_control__ubuntu_noble_amd64__binary)](https://build.ros2.org/job/Jbin_uN64__gz_ros2_control__ubuntu_noble_amd64__binary/) |

This is a ROS 2 package for integrating the `ros2_control` controller architecture with the [Gazebo](http://gazebosim.org/) simulator.
More information about `ros2_control` can be found here: https://control.ros.org/

This package provides a Gazebo-Sim system plugin which instantiates a `ros2_control` controller manager and connects it to a Gazebo model.

ROS version | Gazebo version | Branch | Binaries hosted at | APT key
-- | -- | -- | -- | --
Humble | Fortress | [humble](https://github.com/ros-controls/gz_ros2_control/tree/humble) | https://packages.ros.org | `ros-humble-ign-ros2-control`
Jazzy | Harmonic | [jazzy](https://github.com/ros-controls/gz_ros2_control/tree/jazzy) | https://packages.ros.org | `ros-jazzy-gz-ros2-control`
Rolling | Harmonic | [master](https://github.com/ros-controls/gz_ros2_control/tree/master) | https://packages.ros.org | `ros-rolling-gz-ros2-control`

## Build status

ROS 2 Distro | Branch | Build status | Documentation
:----------: | :----: | :----------: | :-----------:
**Rolling** | [`rolling`](https://github.com/ros-controls/gz_ros2_control/tree/rolling) | [![gazebo_ros2_control CI - Rolling](https://github.com/ros-controls/gz_ros2_control/actions/workflows/ci-rolling.yaml/badge.svg?branch=rolling)](https://github.com/ros-controls/gz_ros2_control/actions/workflows/ci-rolling.yaml) | [Documentation](https://control.ros.org/rolling/index.html) <br /> [API Reference](https://control.ros.org/rolling/doc/api/index.html)
**Jazzy** | [`jazzy`](https://github.com/ros-controls/gz_ros2_control/tree/jazzy) | [![gazebo_ros2_control CI - Jazzy](https://github.com/ros-controls/gz_ros2_control/actions/workflows/ci-jazzy.yaml/badge.svg?branch=rolling)](https://github.com/ros-controls/gz_ros2_control/actions/workflows/ci-jazzy.yaml) | [Documentation](https://control.ros.org/jazzy/index.html) <br /> [API Reference](https://control.ros.org/jazzy/doc/api/index.html)
**Humble** | [`humble`](https://github.com/ros-controls/gz_ros2_control/tree/humble) | [![ign_ros2_control CI - Humble](https://github.com/ros-controls/gz_ros2_control/actions/workflows/ci-humble.yaml/badge.svg?branch=humble)](https://github.com/ros-controls/gz_ros2_control/actions/workflows/ci-humble.yaml) | [Documentation](https://control.ros.org/humble/index.html) <br /> [API Reference](https://control.ros.org/humble/doc/api/index.html)

## Documentation
See the [documentation file](doc/index.rst) or [control.ros.org](https://control.ros.org/master/doc/gz_ros2_control/doc/index.html)

# Compile from source

Note that `gz_ros2_control` depends on the version of Gazebo that is
provided by the Gazebo Vendor packages [`gz_plugin_vendor`](https://github.com/gazebo-release/gz_plugin_vendor) and [`gz_sim_vendor`](https://github.com/gazebo-release/gz_sim_vendor).
Currently, for ROS 2 Jazzy and Rolling, the Gazebo version is Harmonic.

To compile `gz_ros2_control` from source, create a workspace, clone the correct branch of this repo and compile it:

```bash
mkdir -p ~/gz_ros2_control_ws/src
cd ~/gz_ros2_control_ws/src
git clone https://github.com/ros-controls/gz_ros2_control -b {ROS_DISTRO}
rosdep install -r --from-paths . --ignore-src --rosdistro $ROS_DISTRO -y
cd ~/gz_ros2_control_ws
colcon build
```
