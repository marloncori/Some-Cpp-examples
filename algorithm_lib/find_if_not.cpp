#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> nums{{8, 7, 1, 7, 1, 7, 1, 9, 4}};

auto isEven(int n) -> bool {
    return (n % 2 == 0);
}

auto isOdd(int n) -> bool {
    return !isEven(n);
}

auto showRes(std::vector<int>::iterator& res, const char* c){
   std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
   if(res != nums.end()){
       std::cout << "\033[1;" << c << "m" << line << "   Found first element at index #" << *res << "\033[1;" << c << "m" << line << std::endl;
   } else {
       std::cout << "\033[1;31m" << line << "  Sequence is not present in vector." << "\033[1;31m" << line << std::endl;
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

    auto res = std::find_if(nums.begin(), nums.end(), isOdd);

    const char* c1 {"34"};
    showRes(res, c1);
    
  return 0;
}