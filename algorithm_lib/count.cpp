#include <iostream>
#include <vector>
#include <algorithm>

auto showRes(int& n, int& res, const char* c){
std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
std::cout << "\033[1;" << c << "m" << line << " The vector element " << n << "\n appears " 
 << res << " times the vector!\n" << std::endl;
}

auto show(std::vector<int>& arr, std::vector<int>::iterator& it, const char* c){
    std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
    std::cout << "\033[1;" << c << "m" << line << "  Here you are the vector members: \n  Numbers = {";
    for(it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "}." << "\033[1;" << c << "m" << line << std::endl;
}

auto main() -> int{
 
    std::vector<int> nums{{3, 4, 5, 8, 7, 10, 7, 13, 22, 7, 9, 21}};
     std::vector<int>::iterator itr1;
    const char* c1 = "34";
    show(nums, itr1, c1);

    int value = 7;
    auto times = std::count(nums.begin(), nums.end(), value);
    
    const char* c2 = "33";
    showRes(value, times, c2);

  return 0;
}