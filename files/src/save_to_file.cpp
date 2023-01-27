#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <tuple>
#include <system_error>
#include <errno.h>

void adorn()
{
     std::string line("\n\t----------------------------------------\n");
     std::string title("\t    SAVE INPUT DATA TO FILE");

     std::cout << line << std::endl;
     std::cout << title << std::endl;
     std::cout << line << std::endl;

}

std::tuple<std::string, int, float> take_input()
{
       adorn();
       std::string name;
       int age; float height;

       //char buffer[1024];
       //setvbuf(stdout, buffer, _IOFBF, 1024);

       std::cout << "\n\t Please enter your full name: ";
       std::getline(std::cin, name);
       if(name == "")
       {
         throw std::system_error(errno,
            std::system_category(),
            " Input value cannot be null or below zero!");
       }   

       std::cout << "\n\t Now tell us how old you are: ";
       std::cin >> age;
       if(age < 0)
       {
         throw std::system_error(errno,
            std::system_category(),
            " Input value cannot be null or below zero!");
        }
       
       //fflush(stdout);  
       std::cout << "\n\t Please enter your height now: ";
       std::cin >> height;
       if(height < 0)
       {
         throw std::system_error(errno,
            std::system_category(),
            " Input value cannot be null or below zero!");
        }
       
    return std::make_tuple(name, age, height);
}

std::string save_to_file(std::tuple<std::string, int, float> params)
{
    std::string success("\n\t :::: Data successfully saved to file! :::: ");
    std::fstream file;
    std::stringstream contents;

    std::cout << "\n\t  Saving collected data to file..." << std::endl;

    file.open("register.txt", std::ios::out);
    std::string line("\n\t----------------------------------------\n");
    std::string title("\t  * PERSONAL * INFORMATION *");
    
    contents << line << title << line << "\t name: " <<
    std::get<0>(params) << "\n\t age: " << std::to_string(std::get<1>(params))
    << "\n\t height: " << std::to_string(std::get<2>(params)) 
        << "\n" << line << title << line;

    file << contents.str();

    file.close();

    return success;
}

int main(){

    std::string name; 
    int age ; float height;

    std::tie(name, age, height) = take_input();
    std::string success = save_to_file(std::make_tuple(
        name, age, height));

    std::cout << success << std::endl;
    adorn();
    
    return 0;
}