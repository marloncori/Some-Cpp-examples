#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool canSum(int targetSum, vector<int> &vec, map<int, bool> &memo) {
    int remainder;
    if (memo.find(targetSum) != memo.end())
        return memo[targetSum];
    else if (targetSum == 0)
        return true;
    else if (targetSum < 0)
        return false;
    else{
        bool ans = false;
        for(auto i : vec) {
            remainder = targetSum - i;
            ans = ans || canSum(remainder, vec, memo);
            if (ans) {
                memo.emplace(targetSum, true);
                return true;
            }
        }
        memo.emplace(targetSum, false);
    }
    return false;
}

int main() {
  
   map<int, bool> memo;
   vector<int> nums = {2, 3};
   vector<int> nums2 = {5, 3, 5, 7};
   vector<int> nums3 = {2, 4};

   int target = 7;
   cout << (canSum(target, nums, memo) == 0 ? "\t result: FALSE.\n" : "\t result: TRUE.\n") << endl;
   cout << (canSum(target, nums2, memo) == 0 ? "\t result: FALSE.\n" : "\t result: TRUE.\n") << endl;
   cout << (canSum(target, nums3, memo) == 0 ? "\t result: FALSE.\n" : "\t result: TRUE.\n") << endl;
 

  return 0;
}