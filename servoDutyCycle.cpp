#include <iostream>
#include <system_error>
#include <errno.h>
#include <Windows.h>
#include <limits>

//--------------------------------------------------------------------------------
void header();
int getData();
int validateInput(int& position);
float calculateDutyCycle(const int& degree);
void showResult(const int& degrees, const float& dutyCycle);

//--------------------------------------------------------------------------------
int main(int argc, char** argv){

 header();

 auto degree = getData();
 auto duty = calculateDutyCycle(degree);

 showResult(degree, duty);
  
 return 0;
}

//--------------------------------------------------------------------------------
void header(){
  std::cout << " ===================================== " << std::endl;
  std::cout << " ===  SERVO Duty Cycle calculator  === " << std::endl;
  std::cout << " =====================================\n " << std::endl;
  Sleep(1000);
}

//---------------------------------------------------------
int validateInput(int& position){
   while(1){
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << " Please try again! You have entered the wrong input.\n";
        std::cout << "   ==> degrees: ";
        std::cin >> position;
      }
      if(!std::cin.fail()) break;
   }
  return position;
}

//---------------------------------------------------------
int getData(){
   int position, degrees {0};
   std::cout << "  Hello, please enter below a degree in 0-180 \n";
   Sleep(500);
   std::cout << "   for the duty cycle calculation.\n";
   Sleep(1000);
   std::cout << "   ==> degrees: ";
   std::cin >> position;
   degrees = validateInput(position);
   std::cout << "\n\n   Processing input...\n";
   Sleep(1000);

   return degrees;
}

//--------------------------------------------------------------------------------float calculateDutyCycle(const int& degree){
float calculateDutyCycle(const int& degree){
   if((degree < 0) || (degree > 180)){
     throw std::system_error(errno, 
           std::system_category(), " The degree value cannot be less then 0 or greater 180 degrees!!\n"); 
   }    
   return static_cast<float>(((1/180)*degree)+0.5);
}

//--------------------------------------------------------------------------------
void showResult(const int& degrees, const float& dutyCycle){
  std::string line(" ---------------------------------------\n");
  std::cout << line << std::endl;
  std::cout << "\n According to calculation, the \n needed duty cycle to reach\n"; 
  Sleep(500);
  std::cout << " the desired " << degrees << " degrees is: ";
  Sleep(500);
  std::cout << (dutyCycle*100) << "%.\n\n";
  std::cout << line << std::endl;
  header();
}

//--------------------------------------------------------------------------------