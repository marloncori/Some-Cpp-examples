#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/string.hpp"

void chatterCallback(const std_msgs::msgs::String::Shared_Ptr msg){
    if(msg->data != nullptr){
        std::cout << "\033[1;3m $$$$$ The robot has informed the following: $$$$$ \033[0m\n"
        std::cout << " [ " << msg->data << " ]" << std::endl;
    } else {
        throw std::runtime_error("\033[1;32m Something went wrong... NO DATA HAS ARRIVED!\033[0m");
    }
}

int main(int argc, char* argv[]){

    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("ros_listener");

    auto sub = node->create_subscription<std_msgs::msg::String>(
        "chatter", chatterCallback, rmw_qos_profile_default);

    rclcpp::spin(node);
    
    return 0;
}