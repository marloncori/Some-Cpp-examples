// memoization for the canSum problem
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
bool canSum(int targetSum, vector<int> &numbers, unordered_map<int,int> &memo){
    int key = targetSum;

     if(targetSum == 0) return true;  
     if(targetSum < 0) return false; 
     if(memo.find(key) != memo.end()) return memo[key]; // to avoid duplicate subtree calculations
     else {
       for(auto x : numbers) {
           int rem = targetSum - x;
           if(canSum(rem, numbers, memo)){
             memo[key] = true;
             return true;
           }
        }
     memo[key] = false;
    return false;
   }
}

int main() {
   unordered_map <int,int> mp1;
   unordered_map <int,int> mp2;
   unordered_map <int,int> mp3;
   unordered_map <int,int> mp4;
   unordered_map <int,int> mp5;

   vector <int> nums{2,3};
   vector <int> nums1{7,14};
   vector <int> nums2{5,3,4,7};
   vector <int> nums3{2,4};
   vector <int> nums4{2,3,5};
   cout << (canSum(7, nums, mp1) == 0 ? "\t result: FALSE.\n" : "\t result: TRUE.\n") << "\n"; 
   cout << (canSum(7, nums2, mp2) == 0 ? "\t result: FALSE.\n" : "\t result: TRUE.\n") << "\n"; 
   cout << (canSum(7, nums3, mp3) == 0 ? "\t result: FALSE.\n" : "\t result: TRUE.\n") << "\n"; 
   cout << (canSum(8, nums4, mp4) == 0 ? "\t result: FALSE.\n" : "\t result: TRUE.\n") << "\n"; 
   cout << (canSum(300, nums1, mp5) == 0 ? "\t result: FALSE.\n" : "\t result: TRUE.\n") << "\n"; 

   return 0;
 }