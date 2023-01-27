#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <errno.h>
#include <system_error>

std::array<const char*, 30> words;
unsigned int i {0};
std::string word, io_error(" Unable to open file! Make sure you have created it.");

int main(){
    std::ifstream file;
        file.open("testFile2.txt", std::ios::in);

        if(file.is_open()){
            while(file.good()){
                std::getline(file, word, ',');
                words.at(i) = word.c_str();
                i++;
            }
            file.close();
        }
        else {
            throw std::system_error(errno, 
                std::system_category(), io_error);
        }
    std::cout << " Retrieved data: ";
    for(auto& wrd : words){
        std::cout << wrd << " ";
    }
    std::cout << " . END\n";

    return 0;
}
