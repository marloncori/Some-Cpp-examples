#include <iostream>
#include <vector>
#include <algorithm>

auto showRes(int& res, const char* c){
   std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
   if(res > 0){
      std::cout << "\033[1;" << c << "m" << line << "      Element 7 appears " << res << " times the vector." << "\033[1;" << c << "m" << line << std::endl;
   } else {
      std::cout << "\033[1;" << c << "m" << line << "      Element is not present in the vector!" << "\033[1;" << c << "m" << line << std::endl;
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
 
    std::vector<int> nums{{3, 4, 5, 8, 7, 10, 7, 13, 22, 7, 9, 21}};
    std::vector<int> vals{{3, 4, 5, 8, 10, 13, 22, 9, 21}};
    int count {0};
    std::vector<int>::iterator itr1;
    const char* c1 {"34"};
    show(nums, itr1, c1);

    auto range = std::equal_range(nums.begin(), nums.end(), 7);
    for(auto it = range.first; it != range.second; ++it){
        ++count;
    }

    const char* c2 {"33"};
    showRes(count, c2);
 
    count = 0;
    const char* c3 {"36"};

    range = std::equal_range(nums.begin(), nums.end(), 33);
    for(auto it = range.first; it != range.second; ++it){
        ++count;
    }
    showRes(count, c3);

  return 0;
}