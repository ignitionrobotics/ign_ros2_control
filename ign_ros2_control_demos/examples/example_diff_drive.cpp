// Copyright 2022 Open Source Robotics Foundation, Inc.
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

#include <memory>

#include <rclcpp/rclcpp.hpp>

#include <geometry_msgs/msg/twist.hpp>

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node =
    std::make_shared<rclcpp::Node>("diff_drive_test_node");

  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>(
    "/diff_drive_base_controller/cmd_vel_unstamped", 10);

  RCLCPP_INFO(node->get_logger(), "node created");

  geometry_msgs::msg::Twist command;

  command.linear.x = 0.1;
  command.linear.y = 0.0;
  command.linear.z = 0.0;

  command.angular.x = 0.0;
  command.angular.y = 0.0;
  command.angular.z = 0.1;

  while (1) {
    publisher->publish(command);
    std::this_thread::sleep_for(50ms);
    rclcpp::spin_some(node);
  }
  rclcpp::shutdown();

  return 0;
}
