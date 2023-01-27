#include <iostream>
#include <vector>
#include <algorithm>

bool isOdd(int n) {
    return (n % 2 != 0);
}

void show(std::vector<int>& arr, std::vector<int>::iterator& it, const char* c){
    std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
    std::cout << "\033[1;" << c << "m" << line << "  Here you are the vector members: \n  Numbers = {";
    for(it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "}." << "\033[1;" << c << "m" << line << std::endl;
}

int main(){
 
    std::vector<int> nums{{3, 4, 5, 8, 7, 10, 13, 22, 9, 21}};
    std::vector<int> vals(nums.size());

    std::vector<int>::iterator itr1;
    const char* c1 = "34";
    show(nums, itr1, c1);

    std::copy_if(nums.begin(), nums.end(), vals.begin(), isOdd);
    
    std::vector<int>::iterator itr2;
    const char* c2 = "36";
    show(vals, itr2, c2);

  return 0;
}