#include <iostream>
#include <vector>
#include <algorithm>

auto showRes(bool& result){
    if(result){
        std::cout << "\033[1;36m  --> Vector VALS is a subset of NUMS.\033[0m\n" << std::endl;
    } 
    else {
        std::cout << "\033[1;31m  >>> Vector Vals is NOT a subset of Nums. <<< \033[0m\n" << std::endl;
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
 
    std::vector<int> nums{{1, 3, 5, 7, 10, 13, 14, 15, 17, 20}};
    std::vector<int> vals{{4, 8, 9, 2, 11}};
    
    std::vector<int>::iterator itr1;
    
    const char* c1 = "36";
    show(nums, itr1, c1);

    const char* c2 = "33";
    show(vals, itr1, c2);

    std::inplace_merge(nums.begin(), nums.end(), vals.end());
    
    const char* c3 = "34";
    show(vals, itr1, c3);

    const char* c4 = "32";
    show(nums, itr1, c4);


  return 0;
}