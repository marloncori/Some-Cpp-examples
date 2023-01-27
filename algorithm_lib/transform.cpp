#include <iostream>   // std::cout
#include <vector>
#include <algorithm>  // std::transform
#include <functional> // std::plus to add vectors
#include <cmath>      // std::sqrt

float incrementByTwo(float n){
    return (n += 2.0);
}

void showVec(std::vector<float>& arr, std::vector<float>::iterator& it, const char* c){
    std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
    std::cout << "\033[1;" << c << "m" << line << "  Here you are the vector members: \n  Numbers = {";
    for(it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "}." << "\033[1;" << c << "m" << line << std::endl;
}

int main(){
    std::vector<float> nums;
    std::vector<float> vals(2);

    std::vector<float>::iterator itr;
    const char* c1 = "34";
    const char* c2 = "35";
    const char* c3 = "32";

    for(int i=0; i<7; i++){
        nums.push_back(std::sqrt(i*50/3));
    }
    showVec(nums, itr, c1);

    vals.resize(nums.size());
    std::transform(nums.begin(), nums.end(), vals.begin(), incrementByTwo);
    showVec(vals, itr, c2);
    
    std::transform(nums.begin(), nums.end(), vals.begin(), nums.begin(), std::plus<float>());
    showVec(nums, itr, c3);

  return 0;
}