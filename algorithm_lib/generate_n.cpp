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

auto elemsLessThan100() -> int {
   return std::rand() / 1000;
}

auto elemsLessThan1000() -> int {
   return std::rand() / 100;
}

auto main() -> int{
 
    std::vector<int> nums(11);
    std::vector<int> vals(10);
    
    std::vector<int>::iterator itr1;
    const char* c1 = "34";
    const char* c2 = "35";

    std::generate_n(nums.begin(), 6, elemsLessThan100);
    show(nums, itr1, c1);

    std::generate_n(vals.begin(), 5, elemsLessThan1000);
    show(vals, itr1, c2);
 
  return 0;
}