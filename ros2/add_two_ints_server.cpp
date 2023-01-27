#include <iostream>
#include <memory>
#include <iomanip>

#include "rclcpp/rclcpp.hpp"

#include "example_interfaces/srv/add_two_ints.hpp"

void handleAddTwoInts(
    const std::shared_ptr<rmw_request_id_t> request_header,
    const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
    std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response) {
        std::string line("\033[1;33m======================================\n\033[0m");
        (void)request_header;
        std::cout << "\n" << line << std::endl;
        std::cout << "\033[1;36m [ incoming request ]\033[0m" << std::endl;
        std::cout << std::setw(5) << "\033[1;34m  >> a: " << request-> a << std::setw(5) 
        << "\n  >> b: " << request->b << std::endl;  
        std::cout << line << std::endl;

        response->sum = request->a + request->b; 
    }

    int main(int argc, char** argv){

        rclcpp::init(argc, argv);
        auto node = rclcpp::Node::make_shared("add_two_ints_server");

        auto server = node->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", handleAddTwoInts);
        rclcpp::spin(node);

        return 0;
    }