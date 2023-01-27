#include <iostream>
#include <algorithm>
#include <vector>

auto doubleIt(int& n) {
   std::cout << " " << n*2 << " ";
}

auto showIt(int& num) {
   std::cout << " " << num << " ";
}

auto main() -> int {
  std::vector<int> nums{{23, 56, 78, 90, 11, 9, 8}};

  std::cout << "\n These are the vector elements: \n" << std::endl;
  std::for_each(nums.begin(), nums.end(), showIt);
  
   std::cout << "\n These are the vector elements: \n" << std::endl;
   std::for_each(nums.begin(), nums.end(), doubleIt);

   std::cout << "\n These are the vector elements: \n" << std::endl;
   std::for_each(nums.begin(), nums.end(), showIt);
  

  return 0;
}