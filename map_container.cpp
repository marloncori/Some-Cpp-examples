#include <iostream>
#include <map>
#include <array>

int main(){

    std::array<std::string, 7> days = {
        "Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday",
        "Saturday"
    };

    std::map<int, std::string> week;
    for(int i = 0; i < 7; i++){
        week[i] = days[i];
    }

    std::cout << "\033[1;34m\nThis is the seventh day of the week:\n\t\033[0m \033[1;36m" << week.at(6) << ".\033[0m" << std::endl;

    std::map<int, std::string>::iterator current;
    //have a look at the 4 day -> Wednesday
    current = week.find(3);

    //find elements with a greater and smalller index
    std::map<int, std::string>::iterator previous = current;
    std::map<int, std::string>::iterator next = current;
    ++next;
    --previous;

    std::cout << "\033[1;33m\nIf today is -->\n\t\033[0m \033[1;36m" << current->second << ".\033[0m" << std::endl;
    std::cout << "\033[1;32m\nYesterday was ...\n\t\033[0m \033[1;36m" << previous->second << ".\033[0m" << std::endl;
    std::cout << "\033[1;35m\nAnd tomorrow will be:\n\t\033[0m \033[1;36m" << next->second << ".\033[0m" << std::endl;

    std::cout << "\033[1;31m\n These are all the MAP elements:\n\t\033[0m \033[1;36m";

    std::map<int, std::string>::iterator elem;
    for(size_t j=0; j<=week.size(); j++){
       elem = week.find(j-1);      
       std::cout << elem->first << " : " << elem->second << ".\033[0m" << std::endl;
    }
    
    return 0;
}