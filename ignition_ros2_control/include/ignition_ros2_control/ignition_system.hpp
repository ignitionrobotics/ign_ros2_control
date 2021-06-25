// Copyright 2021 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef IGNITION_ROS2_CONTROL__IGNITION_SYSTEM_HPP_
#define IGNITION_ROS2_CONTROL__IGNITION_SYSTEM_HPP_

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "ignition_ros2_control/ignition_system_interface.hpp"

namespace ignition_ros2_control
{
// Forward declaration
class IgnitionSystemPrivate;

// These class must inherit `ignition_ros2_control::IgnitionSystemInterface` which implements a
// simulated `ros2_control` `hardware_interface::SystemInterface`.

class IgnitionSystem : public IgnitionSystemInterface
{
public:
  // Documentation Inherited
  hardware_interface::return_type configure(const hardware_interface::HardwareInfo & system_info)
  override;

  // Documentation Inherited
  std::vector<hardware_interface::StateInterface> export_state_interfaces() override;

  // Documentation Inherited
  std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

  // Documentation Inherited
  hardware_interface::return_type start() override;

  // Documentation Inherited
  hardware_interface::return_type stop() override;

  // Documentation Inherited
  hardware_interface::return_type read() override;

  // Documentation Inherited
  hardware_interface::return_type write() override;

  // Documentation Inherited
  bool initSim(
    rclcpp::Node::SharedPtr & model_nh,
    std::map<std::string, ignition::gazebo::Entity> & joints,
    const hardware_interface::HardwareInfo & hardware_info,
    ignition::gazebo::EntityComponentManager & _ecm) override;

private:
  /// \brief Private data class
  std::unique_ptr<IgnitionSystemPrivate> dataPtr;
};

}  // namespace ignition_ros2_control

#endif  // IGNITION_ROS2_CONTROL__IGNITION_SYSTEM_HPP_
