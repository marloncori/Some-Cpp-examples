#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <array>
#include <windows.h>

#define SIZE_A 20
#define SIZE_B 35

std::string convertIntToStr(const int);
void show_str(const std::vector<std::string>&);
std::string convertIntToChar(const int);
void show_word(const std::list<std::string>&);

int main(){

  std::vector<std::string> letters;
  std::list<std::string> chars;
  std::string str = "";
  std::string letter = "";

  std::array<int, SIZE_A> numbers = {73, 32, 108, 105, 107, 101, 
    32, 108, 101, 97, 114, 110, 105, 110, 103, 32,
    67, 112, 112, 33}; 
  for(auto& num : numbers){ 
      str = convertIntToStr(num);
      letters.emplace_back(str); 
  } 
  
  std::vector<int> values = {72, 101, 108, 108, 111, 44, 32, 74,
    101, 115, 117, 115, 32, 67, 104, 114, 105, 115, 116, 32,
    105, 115, 32, 99, 111, 109, 105, 110, 103, 32, 98, 97,
    99, 107, 33}; 
  for(int i {0}; i < SIZE_B; i++){
       letter = convertIntToChar(values[i]);
       chars.push_back(letter);
   }
   std::cout << "\n\t--------------------------------------" << std::endl;
   std::cout << "\n\t:::: WELCOME TO THE ASCII - CHAR & STR CONVERTER! ::::" << std::endl; 
   Sleep(5);
   
   show_str(letters);
   Sleep(1);
   show_word(chars); 
   Sleep(1);
   std::cout << "\n\t:::: PROGRAM EXECUTION HAS ENDED ::::" << std::endl; 
   std::cout << "\n\t--------------------------------------" << std::endl;
   Sleep(1);

 return 0;
}

std::string convertIntToStr(const int ASCII_Val){
    std::string character;
    return character += (char)ASCII_Val;
}


void show_str(const std::vector<std::string>& letters){
   std::cout << "\n  This is the generated string: \n" << std::endl; 
   Sleep(2);
   std::cout << "\n     ====> ";
   for(auto& str : letters){
      std::cout << str;
      Sleep(3);
   }
   Sleep(2); 
   std::cout << "\n\t--------------------------------------" << std::endl;
}

std::string convertIntToChar(const int ASCII_Val){
    //char letter[2] = { (char)ASCII_Val, 0};
    std::string character;
    character += (char)ASCII_Val;   
 return character;
}

void show_word(const std::list<std::string>& charList){
   std::cout << "\n  This is the generated sentence: \n" << std::endl; 
   Sleep(2);
   std::cout << "\n      ===> "; 
   for(auto& c : charList){
      std::cout << c;
      Sleep(3); 
   }
   Sleep(2); 
   std::cout << "\n\t---------------------------------------" << std::endl;
}