// Copyright 2024 Open Source Robotics Foundation, Inc.
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

#include <chrono>
#include <memory>

#include <rclcpp/rclcpp.hpp>

#include <geometry_msgs/msg/twist_stamped.hpp>

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node =
    std::make_shared<rclcpp::Node>("ackermann_drive_test_node");

  node->set_parameter(rclcpp::Parameter("use_sim_time", true));

  auto publisher = node->create_publisher<geometry_msgs::msg::TwistStamped>(
    "/ackermann_steering_controller/reference", 10);

  RCLCPP_INFO(node->get_logger(), "node created");

  geometry_msgs::msg::Twist tw;

  tw.linear.x = 0.5;
  tw.linear.y = 0.0;
  tw.linear.z = 0.0;

  tw.angular.x = 0.0;
  tw.angular.y = 0.0;
  tw.angular.z = 0.3;

  geometry_msgs::msg::TwistStamped command;
  command.twist = tw;

  while (1) {
    rclcpp::spin_some(node);
    if (node->get_clock()->started()) {
      command.header.stamp = node->now();
      publisher->publish(command);
    }
    std::this_thread::sleep_for(50ms);
  }
  rclcpp::shutdown();

  return 0;
}
