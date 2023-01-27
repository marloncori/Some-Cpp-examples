#include <iostream>
#include <vector>

std::vector<int> howSum(int target, std::vector<int>& nums)
{
    std::vector<int> remainderResult{};
    std::vector<int> result{1};
    if (target == 0){
        return {};
    }
    if (target < 0){
        return result;
    }
    for (auto n : nums) {
        int remainder = target - n;
        remainderResult = howSum(remainder, nums);
        if (remainderResult.size() > 0){
            remainderResult.push_back(n);
            return remainderResult;
        }
    }
    return result;
}

int main(){

  std::vector<int> nums{{4, 5, 1, 3}};
  std::vector<int> nums2{{5, 3, 4, 7}};
  std::vector<int> nums3{{7, 14, 26, 4, 5, 1}};

  int target = 7; 
  int target2 = 8; 
  int target3 = 300;

   auto result = howSum(target, nums);
   if(result.size() > 0){
       std::cout << " result: { ";
       for(auto res : result ){
           std::cout << res << ", ";
       }
       std::cout << "}" << std::endl;
   }

   result = howSum(target2, nums2);
   if(result.size() > 0){
       std::cout << " result: { ";
       for(auto res : result ){
           std::cout << res << ", ";
       }
       std::cout << "}" << std::endl;
   }


 return 0;
}