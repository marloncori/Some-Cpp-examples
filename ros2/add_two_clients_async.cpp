#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

using namespace std::chrono_literals;

int main(int argc, char** argv){

    rclcpp::init(argc, argv);

    auto node {rclcpp::Node::make_shared("add_two_ints_client")};
    auto client {node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints")};

    while(!client->wait_for_service(1s)){
        if(!rclcpp::ok()){
            std::cout << "\033[1;32m Add_two_client\033[0m \033[1;33mhas been interrupted while \n waiting for the service. Existing...\n\033[0m" << std::endl;
            return 0;
        }
        std::cout << "\033[1;35m >>> Service not available, waiting again...\033[0m";
    }    

    auto request {std::make_shared<example_interfaces::srv::AddTwoInts::Request>()};
    request->a {2};
    request->b {3};

    auto future_result {client->async_send_request(request)};
    std::string line("\033[1;31m------------------------------------------------------\n\033[0m");
    //wait for the result
    if(rclcpp::spin_until_future_complete(node, result) ==
        rclcpp::executor::FutureReturnCode::SUCCESS){
            std::cout << "\n" << line << "Result of \'add_two_ints\' =>"
                << future_result.get()->sum << ".\033[0m\n" << line << std::endl;
        } else {
            std::cout << "\033[1;32m >>> add_two_clients_asyns has been interrupted. Exiting...\033[0m<<<"
        }

        rclcpp::shutdown();
    
    return 0;
}