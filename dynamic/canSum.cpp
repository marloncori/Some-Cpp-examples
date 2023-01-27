#include <iostream>
#include <forward_list>

auto canSum(int target, std::forward_list<int> nums) -> bool {
   if(target == 0){
       return true;
   }
   if(target < 0){
       return false;
   }

   for(auto num : nums){
      int remainder = target - num;
      if(canSum(remainder, nums)){
              return true;
       }
    }

 return false;
}

auto main() -> int {
  
   std::forward_list<int> nums = {2, 3};
   std::forward_list<int> nums2 = {5, 3, 5, 7};
   std::forward_list<int> nums3 = {2, 4};

   int target = 7;
   std::cout << (canSum(target, nums) == 0 ? "\t result: FALSE.\n" : "\t result: TRUE.\n") << std::endl;
   std::cout << (canSum(target, nums2) == 0 ? "\t result: FALSE.\n" : "\t result: TRUE.\n") << std::endl;
   std::cout << (canSum(target, nums3) == 0 ? "\t result: FALSE.\n" : "\t result: TRUE.\n") << std::endl;
 
  return 0;
}