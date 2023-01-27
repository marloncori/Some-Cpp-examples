#include <iostream>
#include <vector>
#include <algorithm>

auto showRes(bool& res, const char* c){
   std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
   if(res){
      std::cout << "\033[1;" << c << "m" << line << "      Both vectors are identical!" << line << std::endl;
   } else {
      std::cout << "\033[1;31m" << line << "      Both vectors are different, \n     they are not equal!" << line << std::endl;
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
    std::vector<int> vars{{3, 4, 5, 8, 10, 13, 22, 9, 21}};

    std::vector<int>::iterator itr1;
    const char* c1 = "34";
    show(nums, itr1, c1);

    auto result = std::equal(nums.begin(), nums.end(), vals.begin());
    const char* c2 = "33";
    showRes(result, c2);

    result = std::equal(vals.begin(), vals.end(), vars.begin());
    const char* c3 = "36";
    showRes(result, c3);

  return 0;
}