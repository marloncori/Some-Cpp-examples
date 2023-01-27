#include<iostream>
#include<unordered_map>
#include<array>

int main(){

    std::array<std::string, 7> days = {
        "Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday",
        "Saturday"
    };

    std::unordered_map<int, std::string> week;
    for(int i = 0; i < 7; i++){
        week[i] = days[i];
    }

    std::cout << "\033[1;34m\nThis is the seventh day of the week:\n\t\033[0m \033[1;36m" << week.at(6) << ".\033[0m" << std::endl;

    std::unordered_map<int, std::string>::iterator itr;
    //have a look at the 4 day -> Wednesday
    std::cout << "\033[1;31m\n These are all the UNORDERED MAP elements:\n\t\033[0m \033[1;35m";
    for(itr = week.begin(); itr != week.end(); itr++){
        std::cout << itr->first << " : " << itr->second << "." << std::endl;
    }
    std::cout << "\033[0m" << std::endl;

     std::array<std::string, 7> constants = {
        "e = 2.71828", "pi = 3.14159", " sqrt(2) = 1.414",
        "golden ratio = 1.618", "laplace lim. = 0.66274", "pi**2 = 9.86960",
        "1/pi = 0.31830"
    };

    std::unordered_map<int, std::string> values;
    for(int i = 0; i < 7; i++){
        values[i] = constants[i];
    }

    std::cout << "\033[1;32m\n These are all the UNORDERED MAP constants:\n\t\033[0m \033[1;35m";
    for(auto& v : values){
        std::cout << v.first << " ==>> " << v.second << "." << std::endl;
    }
    std::cout << "\033[0m" << std::endl;
    
    return 0;
}