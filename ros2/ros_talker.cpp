#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char * argv[]){

    rclpcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("ros_talker");

    rmw_qos_profile_t custom_qos_profile = rmw_qos_profile_default;
    custom_qos_profile.depth = 7;

    auto chatter_pub = node->create_publisher<std_msgs::msg::String>("ros_chatter", custom_qos_profile);

    rclpcpp::WallRate loopRate(2);

    auto msg = std::make_shared<std_msgs::msg:String>();
    auto it = 1;
    std::string line("---------------------------------------------------\n");

    while(rclcpp::ok()){
        msg->data = "\n" + line + "\033[1;36m >>> This is the covered distance => " + std::to_string(it++) + " m.\033[0m\n" + line;
        std::cout << "\033[1;34m :::: [ incoming message from ROBOT ] :::: \033[0m" << std::endl;
        std::cout << msg->data << std::endl;
        chatter_pub->publish(msg);
        rclcpp::spin_some(node);
        loopRate.sleep();
    }

    return 0;
}
