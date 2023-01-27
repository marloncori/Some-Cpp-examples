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
 
    std::vector<int> nums(10, 7);
    std::vector<int>::iterator itr1;
 
    const char* c2 {"36"};
    show(nums, itr1, c2);

    int howManyElems = 5;
    int valueToBeFilled = 12;
    std::fill_n(nums.begin(), howManyElems, valueToBeFilled);

    const char* c1 {"34"};
    show(nums, itr1, c1);
 
    howManyElems = 4;
    valueToBeFilled = 31;
    std::fill_n(nums.begin()+5, howManyElems, valueToBeFilled);

    const char* c3 {"33"};
    show(nums, itr1, c3);

  return 0;
}