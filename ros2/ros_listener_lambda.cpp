#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("ros_listener");

    auto sub = node->create_subscription<std_msgs::msg::String>(
        "chatter", [](const std_msgs::msg::String::SharedPtr msg) -> void {
            printf( "\033[1;34m >>> The robot has informed the following:\033[0m [%s]", 
            msg->data.c_str());}, rmw_qos_profile_sensor_data);

    rclcpp::spin(node);
    return 0;
}