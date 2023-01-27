#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> nums(10, 7);

auto showRes(auto res, int& val, const char* c){
   std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
   if(res == std::end(nums)){
       std::cout << "\033[1;" << c << "m" << line << " The number " << val << " is NOT present in the vector!"  
          << "\033[1;" << c << "m" << line << std::endl;
   } else {
       std::cout << "\033[1;31m" << line << " The number " << val << " IS present in the vector!"  
          << "\033[1;31m" << line << std::endl;
   }
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
 
    std::vector<int>::iterator itr1;
 
    const char* c2 {"36"};
    show(nums, itr1, c2);

    int query = 5;
    auto result = std::find(nums.begin(), nums.end(), query);

    const char* c1 {"34"};
    showRes(result, query, c1);
 
    query = 7;
    result = std::find(nums.begin(), nums.end(), query);

    const char* c3 {"35"};
    showRes(result, query, c3);
    
  return 0;
}