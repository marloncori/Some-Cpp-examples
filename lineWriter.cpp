#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <errno.h>
#include <system_error>

std::string io_error(" Unable to open file! Make sure you have created it.");
std::vector<std::string> words;
std::ofstream myFile;
int numLines {0};
std::string data;
std::string line("===============================================\n");
std::string title("      EMPLOYEE PERSONAL INFORMATION");

int readCSV(std::istream& input, std::vector<std::vector<std::string>> &output){
    int lines {0};
    std::string csvLine;

    while(std::getline(input, csvLine)){
        std::istringstream csvStream(csvLine);
        std::vector<std::string> csvColumn;
        std::string csvElement;
        ++lines;

        while(std::getline(csvStream, csvElement, ',')){
            csvColumn.push_back(csvElement);
        }
        output.push_back(csvColumn);   
    }
    return lines;
}

int main(int argc, char** argv){

    std::fstream file("employees.txt", std::ios::in);
    myFile.open("testFile2.txt");

    if(!file.is_open()){
       throw std::system_error(errno, std::system_category(), io_error);
    }

    if(!myFile.is_open()){
       throw std::system_error(errno, std::system_category(), io_error);
    }

    std::vector<std::vector<std::string>> csvData;
    numLines = readCSV(file, csvData);

    std::cout << " \n Total number of read lines: " << numLines << "\n\n";
    for(std::vector<std::vector<std::string>>::iterator it = csvData.begin(); 
            it != csvData.end(); ++it){
        for(std::vector<std::string>::iterator j = it->begin(); j != it->end(); ++j){
              data = *j;
              std::cout << line << std::endl;         
              std::cout << "\n   DATA : " << std::setw(2) << data << "\n";
              myFile << "DATA: " << data << " | ";
        }
        myFile << "\n";
        std::cout << "\n ---------------------------------------- \n";
    }

    file.close();
    myFile.close();

    return 0;
}