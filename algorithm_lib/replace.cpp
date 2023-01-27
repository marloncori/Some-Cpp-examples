#include <iostream>   // std::cout
#include <vector>
#include <algorithm>  // std::transform
#include <functional> // std::plus to add vectors
#include <cmath>      // std::sqrt

void showVec(std::vector<int>& arr, std::vector<int>::iterator& it, const char* c){
    std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
    std::cout << "\033[1;" << c << "m" << line << "  Here you are the vector members: \n  Numbers = {";
    for(it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "}." << "\033[1;" << c << "m" << line << std::endl;
}

int main(){
    std::vector<int> nums; 
    std::vector<int>::iterator itr;

    const char* c[3] = {"34", "35", "36"};
    int vals[4] = {7, 100, 0, 77};

    for(int i=0; i<7; i++){
        nums.push_back(std::sqrt(i*100/3));
    }
    showVec(nums, itr, c[1]);
   
    std::replace(nums.begin(), nums.end(), vals[0], vals[1]);
    showVec(nums, itr, c[0]);

    std::replace(nums.begin(), nums.end(), vals[2], vals[3]);
    showVec(nums, itr, c[2]);

  return 0;
}