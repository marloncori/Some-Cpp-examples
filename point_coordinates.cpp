#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <errno.h>
#include <system_error>
#include <windows.h>
#include <iomanip>

std::vector<float> gather_data();
std::pair<std::string, float> x_coord(std::vector<float>&);
std::pair<std::string, float> y_coord(std::vector<float>&);
void show_position(const std::pair<std::string, float>&, const std::pair<std::string, float>&);

int main(){
    /*std::vector<float> params;
     std::pair<std::string, float> Xq;
     std::pair<std::string, float> Yq;*/

    auto params = gather_data();
    auto Xq = x_coord(params);
    auto Yq = y_coord(params);
    show_position(Xq, Yq);

    return 0;
}

std::vector<float> gather_data(){
    std::vector<float> params;
    float L1, L2, theta1, theta2;
    std::string errMsg(" ERROR: The variable value cannot be zero!");
    std::cout << "\n  Let us gather the data to calculate \n the point Q coordinates!" << std::endl;
    Sleep(1);
    std::cout << "   Please enter below four needed values for the calculation." << std::endl;
    std::cout << "\n  ====> The first link length: ";
    std::cin >> L1;
    if(L1 == 0.0){
        throw std::system_error(errno, std::system_category(), errMsg);
    }
    params.emplace_back(L1);
    std::cout << "  ====> The second link length: ";
    std::cin >> L2;
    if(L2 == 0.0){
        throw std::system_error(errno, std::system_category(), errMsg);
    }
    params.emplace_back(L2);
    std::cout << "  ====> The first angle value: ";
    std::cin >> theta1;
    if(theta1 == 0.0){
        throw std::system_error(errno, std::system_category(), errMsg);
    }
    params.emplace_back(theta1);
    std::cout << "  ====> The second angle value: ";
    std::cin >> theta2;
    if(theta2 == 0.0){
        throw std::system_error(errno, std::system_category(), errMsg);
    }
    params.emplace_back(theta2);
    std::cout << " \n So you have entered the following values: " << std::endl;
    for(size_t i = 0; i < params.size(); i++){
        switch(i){
            case 0:
                std::cout << std::setw(5) << std::setprecision(4) << "   L1 = " << params[i] << std::endl;
                break;
            case 1:
                std::cout << std::setw(5) << std::setprecision(4) << "   L2 = " << params[i] << std::endl;
                break;
            case 2:
                std::cout << std::setw(5) << std::setprecision(4) << "   Theta 1 = " << params[i] << std::endl;
                break;
            case 3:
                std::cout << std::setw(5) << std::setprecision(4) << "   Theta 2 = " << params[i] << std::endl;
                break;
            default:
                break;
        }
       Sleep(1);
    }
    return params;
}

std::pair<std::string, float> x_coord(std::vector<float>& values){
    float l1, l2, th1, th2, x;
    std::string errMsg("Error: No values found! Vector cannot be null!");
    
    if(values.size() == 0){
        throw std::system_error(errno, std::system_category(), errMsg);
    }
    std::cout << "\n   Calculating..." << std::endl;
    Sleep(2);   
    l1 = values[0];
    l2 = values[1];
    th1 = values[2];
    th2 = values[3];

    x = (l1*cos(th1)) + l2*cos(th1+th2);
    return std::make_pair("Xq: ", x);
}

std::pair<std::string, float> y_coord(std::vector<float>& values){
    float l1, l2, th1, th2, y;
    std::string errMsg("Error: No values found! Vector cannot be null!");
    
    if(values.size() == 0){
        throw std::system_error(errno, std::system_category(), errMsg);
    }
    
    l1 = values[0];
    l2 = values[1];
    th1 = values[2];
    th2 = values[3];

    y = (l1*sin(th1)) + l2*sin(th1+th2);
    return std::make_pair("Yq: ", y);
}

void show_position(const std::pair<std::string, float>& xq, 
                    const std::pair<std::string, float>& yq){
    std::string line("-----------------------------------------------");
    std::cout << "  The position of Q point is: " << std::endl;
    std::cout << std::setw(10) << std::setprecision(4) << xq.first << xq.second << "\n"
     << std::setw(10) << std::setprecision(4) << yq.first << yq.second << std::endl;

    std::cout << line << std::endl; 
}