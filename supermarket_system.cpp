#include<iomanip>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>

std::fstream file;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
//**************Global Functions**************//
void showTime(){
    time_t now;
    time(&now);
    SetConsoleTextAttribute(hConsole, 12);
    std::cout << "\n" << std::setw(40) << "This is the time --->>" << ctime(&now) << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void stars(){
    SetConsoleTextAttribute(hConsole, 10);
    std::cout<<"\n********************************************************************************\n"<<std::endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void displayHeader(){
    SetConsoleTextAttribute(hConsole, 13);
    std::cout << std::setw(50)<<"_____________________"<<std::endl;
    std::cout << std::setw(51)<<"|***NCE SUPERMARKET***|"<<std::endl;
    std::cout << std::setw(51)<<"|_____________________|"<<std::endl;
    SetConsoleTextAttribute(hConsole, 15);
    stars();
}

class User {
    private:
        char* username;
        char* password;
    public:
        User();
        void addUser();
};

User::User(){}

void User::addUser(){
        char* repetition;
        std::cout<<"\n\n\t\t\tADD USER\n\n";
        std::cout<<"\n\t\tEnter the username and password\n";
        std::cout<<"\t >>> Username :  ";
        std::cin>>username;
        std::cout<<"\t >>> Password  :  ";
        std::cin >> password;
        fflush(stdin);
        std::cout<<"\t Confirm the password: \n\t>>> Password again :  ";
        std::cin >> repetition;
        if(strcmp(password, repetition)){
            std::cout << "\t Alright. New user has been added.\n";
        }
        file.open("user.txt",std::ios::app | std::ios::out);
        file.write(reinterpret_cast<char*>(this),sizeof(*this));
        file.close();
}

int main(){

    system("cls");
    displayHeader();
    showTime();
    std::unique_ptr<User> user = std::make_unique<User>(User());
    user->addUser();
    std::cout << std::setw(40) << " Press any key to exit...\n";
    getch();

    return 0;
}