#include <iostream> // std::cout, std::endl
#include <functional> // std::function
#include <utility> // std::make_pair
#include <vector> // std::vector
#include <map> // std::map

typedef std::function<void()> func;
struct Sensor {
   std::string type;
   float power;
   void testFive(){ std::cout << "\n testFive function has been called! \n The type of sensor is: " << type << " \n You need to power it with: " << power << " volts!\n" << std::endl; }   
};

std::string getUsername(){
    std::string name("");
    std::cout << " \n\t Please tell us what your name is: ";
    std::cin >> name;
    return name;
}

void invalidOption(){
    std::cout << "\n\t The option you entered is not valid. Try again!" << std::endl;
}

void testOne(){
    std::cout << " testOne function has been called!" << std::endl;
}

void testTwo(){
    std::vector<int> nums{{3, 5, 7, 9, 1, 13, 15, 19, 21}};
    std::cout << " testTwo function has been called!" << std::endl;
    std::cout << " ------------------------- \n\t Nums elements: \n\t{" << std::endl;
    for(auto& num : nums){
        std::cout << num << " ";
    }
    std::cout << " }" << std::endl; 
}

void testThree(){
    int age{};   
    std::cout << " testThree function has been called!" << std::endl;
    std::cout << " ------------------------- \n\t How old are you now?" << std::endl;
    std::cout << "\t\t Age: ";
    std::cin >> age;
    switch(age){
        case 4:
            std::cout << " >> " << age << "?????? Are you kidding? It is your son who is only four years old!" << std::endl;
            break;
        case 18:
            std::cout << " >> " << age << "?? Pleae tell a better joke..!" << std::endl;
            break;
        case 35:
            std::cout << " >> " << age << "? That was your age last year!" << std::endl;
            break;
        default:
            std::cout << " Wow, if you\'re " << age << " years, you are really old, man!" << std::endl;
            break;
    }
}

void testFour(){
    auto name = getUsername();
    int n = name.length();
    std::cout << " testFour function has been called!\n" << std::endl;
    std::string line("\n=================================\n");
    std::cout << line<< "   Your name has: " << n << " letters! " << line << std::endl;
}

int simpleMenu(){
    int choice{};
 
    std::cout << "\n ::::: WELCOME TO FUNCTION MAP TEST :::::" << std::endl;
    std::cout << "\n   --> Choose one option: \n\t(1) Call func1 \n\t(2) Call func2 \n\t(3) Call func3 \n\t(4) Call func4 \n\t(5) Call func5 \n\t(6) Exit\n" << std::endl;
    std::cout << "\n  Your choice ==>> ";
    std::cin >> choice;
    return choice;
}

int main(){
    std::map<int, func> action;
    Sensor imu6050;
    imu6050.type = "Gyroscope MPU 6050";
    imu6050.power = 3.3;
    
    action.insert(std::make_pair(1, testOne));
    action.insert(std::make_pair(2, testTwo));
    action.insert(std::make_pair(3, testThree));
    action.insert(std::make_pair(4, testFour));
    action.insert(std::make_pair(5, std::bind(imu6050.testFive, imu6050)));
    
    int option{}; 
    option = simpleMenu();

    while(option != 6){
       if(action.count(option)){ 
          action[option]();
       } else {
          invalidOption();
       }
       option = simpleMenu();
    }
    
    if(option == 6){
        std::cout << "\n   --> Goodbye, master Marlon!" << std::endl;
        std::cout << " ::::: SAMPLE PROGRAM HAS ENDED :::::\n" << std::endl;
    }

  return 0;
}