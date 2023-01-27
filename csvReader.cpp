#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <errno.h>
#include <system_error>

std::vector<std::vector<std::string>> data;
std::string io_error(" Unable to open file! Make sure you have created it.");

int main() {
    std::ifstream file("testFile2.txt", std::ios::in);

   if(file.is_open()){
     while(file.good()){
        std::string str;
        std::vector<std::string> records;
        if(!std::getline(file, str)) {
             break;
        }
        else {
             std::istringstream iss(str);
             while(iss){
                std::string word;
                if(!std::getline(iss, word, ',')){   
                     break;
                 } 
                else {
                    records.push_back(word);
                 
                }
            }
        }
         data.emplace_back(records);
      }
    }
    else {
        throw std::system_error(errno,
                std::system_category(), io_error);
    }
   
 for(auto& dt : data){
    for(auto& io : dt){
        std::cout << " | >> " << io;
    }
     std::cout << std::endl;    
 }

 return 0;
}