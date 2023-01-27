#include <iostream>
#include <memory>
#include "Point3D.h"

Point3D point;

void show(){
    std::cout << point << std::endl;
}

void header(){
    std::string line("\033[1;31m ::::::::::::::::::::::::::::::::::::\033[0m");
    std::string title("\033[1;33m    CONSOLE ROBOTICS - 3D POINT\033[0m");

    std::cout << "\n" << line << "\n" << title <<  "\n" << line << "\n" << std::endl;
}

void operations(int opt){
    float tx = 0.0, ty = 0.0, tz = 0.0, angle;
    float sf = 0.0, xf = 0.0, yf = 0.0, zf = 0.0;
    switch(opt){
        case 1:
            std::cout << "  Enter the value of tx, ty and tz: " << std::endl;
            std::cout << "\t tX: ";
            std::cin >> tx;
            std::cout << "\t tY: ";
            std::cin >> ty;
            std::cout << "\t tZ: ";
            std::cin >> tz;
            translate(point, tx, ty, tz);
            show();
            break;
        case 2:
            std::cout << " --> Enter the angle: ";
            std::cin >> angle;
            rotateX(point, angle);
            show();
            break;
        case 3:
            std::cout << " --> Enter the angle: ";
            std::cin >> angle;
            rotateY(point, angle);
            show();
            break;
        case 4:
            std::cout<< "  [INFO] Enter the angle: ";
            std::cin >> angle;
            rotateZ(point, angle);
            show();
            break;
        case 5:
            std::cout<<"    Enter the value of sf, xf, yf and zf for scalation: ";
            std::cout << "\t sf: ";
            std::cin >> sf;
            std::cout << "\t xf: ";
            std::cin >> xf;
            std::cout << "\t yf: ";
            std::cin >> yf;
            std::cout << "\t zf: ";
            std::cin >> zf;
            scale(point, sf, xf, yf, zf);
            show();
            break;
        default:
            break;
    }
}

int menu(){
    int choice;
    std::cout<< " --> Enter the initial point you want to transform:" << std::endl;
    std::cout << "\t X value: ";
    std::cin >> point.x;
    std::cout << "\t Y value: ";
    std::cin >> point.y;
    std::cout << "\t Z value: ";
    std::cin >> point.z;
    std::cout << "\n  Now choose an operation:" << std:: endl;
    std::cout<<"\t1. Translate"<< std::endl;
    std::cout<<"\t2. Rotate about X axis"<< std::endl;
    std::cout<<"\t3. Rotate about Y axis"<< std::endl;
    std::cout<<"\t4. Rotate about Z axis"<< std::endl;
    std::cout<<"\t5. Scale" << std::endl;   
    std::cout << "\t6. Exit" << std::endl;   
    std::cout << "\n   >>> Option: ";
    std::cin >> choice;
    return choice;
}

int main(){
    
    header();
    int option = menu();

    while(option != 6){
        header();
        operations(option);
        option = menu();
    }   
    std::cout << "\033[1;32m\n    ==>> Thank you. Goodbye!\033[0m\n" << std::endl;

    return 0;
}