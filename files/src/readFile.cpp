#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <system_error>
#include <errno.h>

void adorn()
{
     std::string line("\n\t----------------------------------------\n");
     std::string title("\t    READ DATA FROM .TXT FILE");

     std::cout << line << std::endl;
     std::cout << title << std::endl;
     std::cout << line << std::endl;

}

std::string take_input()
{
       adorn();
       std::string fileName;

       std::cout << "\n\t Enter below the name of the file to read." << std::endl;
       std::cout << "\t >>>> File name: ";
       std::getline(std::cin, fileName);
       if(fileName == "")
       {
         throw std::system_error(errno,
            std::system_category(),
            " Input value cannot be null or below zero!");
       }   

    return fileName;
}

std::string readFromFile(std::string file_name)
{
    std::string success("\n\n\t :::: Data successfully read and displayed! :::: ");
    std::ifstream file;
    std::string contents, title; int lineNumber = 1; 
    std::vector<std::string> names;
    std::vector<std::string> ages;
    std::vector<std::string> heights;

    std::cout << "\n\t  Opening file..." << std::endl;

    file.open(file_name, std::ios::in);
    if(!file.good()){
        throw std::system_error(errno,
            std::system_category(),
            " There is no such file, \n make sure you wrote the correct \n file name!");
    }
 
    while(std::getline(file, contents)){
        switch(lineNumber){
            case 1: 
            case 5:
            case 9:
            case 13:
                title = contents; 
                break;
            case 2:
            case 6:
            case 10:
            case 14:
                names.push_back(contents); 
                break;
            case 3:
            case 7:
            case 11:
            case 15:
                ages.push_back(contents); 
                break;
            case 4:
            case 8: 
            case 12:
            case 16:
                heights.push_back(contents);
                break;
            default:
                break;
        }
        lineNumber++;
    }
    file.close();
    for(int i=0; i<names.size(); i++){
        std::cout << "\n " << title << std::endl;
        std::cout << names[i] << std::endl;
        std::cout << ages[i] << std::endl;
        std::cout << heights[i] << std::endl;
        std::cout << "\n " << title << "\n " << std::endl;
    } 

   return success;
}

int main(){

    std::string file_name; 
    int line ; float height;

    file_name = take_input();
    std::string success = readFromFile(file_name);

    std::cout << success << std::endl;
    adorn();
    
    return 0;
}