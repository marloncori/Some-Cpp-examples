#include <iostream>
#include <cstring>
#include <vector>

int main(){
    std::vector<char*> words;
    char str[100];
    std::cout << "  Enter a word below. " << std::endl;
    
    std::cout << "\t Str: ";
    std::cin.getline(str, 100);

    char* chptr = new char[100];
    // use strtok function to separate string 
    // using the comma , delimitter
    chptr = std::strtok(str, ": ");  
            std::cout << "\n  Trying and split string by using strtok function" << std::endl;
    while(chptr != NULL){
                std::cout << "\t This is the string token: " << chptr << std::endl;
                words.push_back(chptr);
                chptr = std::strtok(NULL, " ");
    }

    std::cout << "\n So this is the name of the product: " 
         << words.at(2) << " " << words.at(3) << std::endl;

    delete chptr;
  return 0;
}