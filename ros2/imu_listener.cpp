#include <cstdio>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"

void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg){
    std::string line("\033[1;31m==========================================\033[0m");
    printf("\n%s\n", line);
    printf("\033[1;33m Accel:\033[0m \033[34m\n\t%+6.3f\033[0m 
    \033[35m\n\t%+6.3f\033[0m\033[36m\n\t%+6.3f\033[0m\n", 
    msg->linear_acceleration.x,
    msg->linear_acceleration.y,
    msg->linear_acceleration.z);
    printf("\n%s\n", line);
}

int main(int argc, char* argv[]){

    rclcpp::init(argc, argv);

    auto node = rclpcpp::Node::make_shared("imu_listener");
    autp sub = node->create_subscription<sensor_msgs::msg::Imu>(
        "imu", imuCallback, rmw_qos_profile_sensor_data);

    rclcpp::spin(node);

    return 0;
}