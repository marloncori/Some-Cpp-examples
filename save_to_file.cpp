#include <iostream>
#include <sstream>
#include <stream>
#include <cstring>
#include <tuple>
#include <system_error>
#include <errno.h>

template<typename T>
void validate(T input)
{
    if(input == "" || input < 0)
    {
        std::string errMsg(" Input value cannot be null or below zero!");
        throw std::system_error(errno,
           std::system_category(), errMsg);
    }
    return;
}

void adorn()
{
     std::string line("\n\t----------------------------------------\n");
     std::string title("\t    SAVE INPUT DATA TO FILE");

     std::cout << line << std::endl;
     std::cout << title << std::endl;
     std::cout << line << std::endl;

}

std::tuple<std::string, int, height, std::string> take_input()
{
       adorn();
       std::string name, address;
       int age; float height;

       std::cout << "\n\t Please enter your full name: ";
       std::getline(std::cin, name);
       validate(name);

       std::cout << "\n\t Now tell us how old you are: ";
       std::cin >> age;
       validate(age);

       std::cout << "\n\t Please enter your height now: ";
       std::cin >> height;
       validate(height);

       std::cout << "\n\t  And what is your address? >>> ";
       std::getline(std::cin, address);
       validate(address);

    return std::make_tuple(name, age, height, address);
}

std::string save_to_file(std::tuple<std::string, int, height, std::string> params)
{
    std::string success("\n\t :::: Data successfully saved to file! :::: ");
    std::fstream file;
    std::stringstream contents;
    
    std::string line("\n\t-----------------------------------------\n");
    std::string title("\t  * PERSONAL * INFORMATION *");
    
    contents << line << title << line << "\t name: "
    std::get<0>(params) << "\n\t age: " << std::to_string(std::get<1>(params))
    << "\n\t height: " << std::to_string(std::get<2>(params))
    << "\n\t address: " << std::get<3>(params) << line << title << line;

    file.open("personal_information.txt", std::ios::out);
    file << contents.str();
    file.close();

    return success;
}

int main(){

    std::string name, address; 
    int age ; float height;

    std::tie(name, age, height, address) = take_input();
    std::string success = save_to_file(std::make_tuple(
        name, age, height, address));

    std::cout << success << std::endl;
    adorn();
    
    return 0;
}