#include <iostream>
#include <chrono>
#include <windows.h>

void printMsg(const std::string& msg, int color, uint16_t times){
    std::string line("---------------------------------------------");
    for(size_t i=0; i<times; i++){
       std::cout << "\n" << line << "\033[1;" << color+i
       << "m\n" << msg << "\033[0m" << line << std::endl;
       Sleep(2000);
    }
}

int main(int argc, char** argv){

    std::string msg(">>>>> This is a test message.");
    int gray = 30;
    int rpt = 7;

    printMsg(msg, gray, rpt);

 return 0;
}

