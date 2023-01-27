#include <iostream>
#include <vector>
#include <algorithm>

auto show_vec(std::vector<int>& arr, std::vector<int>::iterator& it, const char* c){
    std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
    std::cout << "\033[1;" << c << "m" << line << "  Here you are the vector members: \n  Numbers = {";
    for(it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "}." << "\033[1;" << c << "m" << line << std::endl;
}

auto write(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>::iterator& it, const char* c1, const char* c2) {
    show_vec(arr1, it, c1);
    show_vec(arr2, it, c2);
}

auto main() -> int{
 
    std::vector<int> nums{{3, 4, 5, 8, 7, 10}};
    std::vector<int> vals{{7, 13, 22, 7, 9, 21}};

    std::vector<int>::iterator itr1;
    const char* c[6] = {"34", "33", "36", "35", "32", "31"};

    std::cout << "  Before std::iter_swap()...\n";
    write(nums, vals, itr1, c[0], c[1]);

    std::iter_swap(nums.begin(), vals.begin());
    std::cout << "  After std::iter_swap()...\n";
    write(nums, vals, itr1, c[3], c[2]);

    std::iter_swap(nums.begin()+2, vals.begin()+3);
    std::cout << "  After second std::iter_swap()...\n";
    write(nums, vals, itr1, c[5], c[4]);

  return 0;
}