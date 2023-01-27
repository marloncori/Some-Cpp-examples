#include <chrono>
#include <iostream>
#include <memory>
#include <system_error>

#include "rclcpp/rclcpp.hpp"

#include "example_interfaces/srv/add_two_ints.hpp"

using namespace std::chrono_literals;

example::interface::srv::AddTwoInts_Response::SharedPtr send_request(
    rclcpp::Node::SharedPtr node, rclcpp::client::Client
    <example_interfaces::srv::AddTwoInts>::SharedPtr client, example_interfaces::srv::AddTwoInts_Request::SharedPtr request){
        auto result {client->async_send_request(request)};
        if(rclcpp::spin_until_future_complete(node, result) ==
            rclcpp::executor::FutureReturnCode::SUCCESS){
                return result.get();
        } else {
            return NULL;
    }
) 

int main(int argc, char** argv){

    rclcpp::init(argc, argv);
    auto client = node->create_client<example_interface::srv::AddTwoInts>("add_two_ints");
    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = 2;
    request->b = 3;

while(!client->wait_for_service(1s)){
    if(!rclcpp::ok()){
        std::cout << "\033[1;32m\n>>> add_two_ints_client was interrupted while waiting for the service. Exiting.\n\033[0m" << std::endl;
        return 0;
    }
    std::cout << " Service not available, waiting again..." << std::endl;
}
    auto result = send_request(node, client, request);

    try{    
        if(result){
            std::cout << " The result of \'add_two_ints\' :" << result->sum << "." << std::endl;
        } else {
            std::cout << " ADD_TWO_INTS has been interrupted by Master. Exiting..." << std::endl;
        }
    }catch(const std::system_error& e){
        std::cout << " WARNING: system error has been caught \n with code"
        << e.code() << ", which stands for: " << e.what() << std::endl; 
    }

    rclpc::shutdown();
       
    return 0;
}