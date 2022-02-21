#include <iostream>
#include <cstdlib>
#include <array>
#include <chrono>
#include <thread>
#include <iomanip>

#define space 12
#define blue 34
#define green 32

void printData(const std::string& a, const std::string& b, const std::string& c, int space, int color, bool flag=false){
    if(flag){
        std::cout << std::right << "\n\033[1;" << color << "m" << std::setw(space) << a 
        << std::setw(space) << b << std::setw(space) << c << "\033[0m" << std::endl;
    } else {
        std::cout << "\n\033[1;" << color << "m" << std::setw(space) << a 
        << std::setw(space) << b << std::setw(space) << c << "\033[0m" << std::endl;
   }
}

int main(int argc, char** argv){
  
    const std::string name("  NAME  ");
    const std::string surname(" SURNAME  ");
    const std::string job(" OCCUPATION ");
    bool flag {true};
    
    std::array<std::string, 4> firstNames{"Marlon", "Jakub", "León", "Ezra"};
    std::array<std::string, 4> lastNames{"Couto", "Szyminski", "Navarro", "Heathrer"};
    std::array<std::string, 4> professions{"translator", "programmer", "teacher", "attorney"};

    printData(name, surname, job, space, blue, flag);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    for(int i{}; i<4; i++){
        printData(firstNames[i], lastNames[i], professions[i], SP, green);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
  return 0;
}
