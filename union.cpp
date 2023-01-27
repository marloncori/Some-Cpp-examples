#include <iostream>
#include <ostream>
#include <Windows.h>

union Robot {
    double price;
    int sensors;
} bot;

std::ostream& operator<<(std::ostream& os, Robot& bot){
    os << "\n\tRobot price:  " << bot.price << "\n\t"
        <<"Total sensors: " << bot.sensors << "\n";
    return os;
}

void show(Robot b){
    std::cout << "\n\t INFORMATION \n" << b << "\n";
}

int main(){
 
    bot.price = 1000.0;
    bot.sensors = 4;

    show(bot);

 return 0;
}