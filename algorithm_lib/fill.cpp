#include <iostream>
#include <vector>
#include <algorithm>

auto show(std::vector<int>& arr, std::vector<int>::iterator& it, const char* c){
    std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
    std::cout << "\033[1;" << c << "m" << line << "  Here you are the vector members: \n  Numbers = {";
    for(it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "}." << "\033[1;" << c << "m" << line << std::endl;
}

auto main() -> int{
 
    std::vector<int> nums(10);
    std::vector<int>::iterator itr1;
 
    std::fill(nums.begin(), nums.end(), 7);

    const char* c1 {"34"};
    show(nums, itr1, c1);
 
  return 0;
}