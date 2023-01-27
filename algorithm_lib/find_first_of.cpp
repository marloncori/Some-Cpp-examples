#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> nums{{1, 7, 1, 7, 1, 7, 1, 2, 4}};
std::vector<int> seq{{20, 7}};
std::vector<int> vec{{2, 10}};

auto showRes(auto res, int& val, const char* c){
   std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
   if(res != nums.end()){
       std::cout << "\033[1;" << c << "m" << line << "   Found first element at index #" << val << "\033[1;" << c << "m" << line << std::endl;
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
    auto res = std::find_first_of(nums.begin(), nums.end(), seq.begin(), seq.end());

    auto dist = std::distance(nums.begin(), res);
    const char* c1 {"34"};
    showRes(res, dist, c1);
     
    res = std::find_first_of(nums.begin(), nums.end(), vec.begin(), vec.end());
    const char* c3 {"35"};
    dist = std::distance(nums.begin(), res);
    showRes(res, dist, c3);
    
  return 0;
}