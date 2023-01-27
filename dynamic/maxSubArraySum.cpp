#include <iostream>
#include <vector>
#include <limits>
#define NOTHING 0

auto less(int first, int second) -> bool {
    return (first > second);
}

auto greater(int first, int second) -> bool {
    return (first > second);
}

auto kadaneSubArraySum(const std::vector<int>& vec, int& start, int& finish) -> int {
    int maxSum = -std::numeric_limits<int>::max(); 
    int sum = 0;
    unsigned int left = 0, right = 0;
    start = finish = 0;
    
    for(unsigned int i=0; i<vec.size(); ++i){
        sum += vec[i];
        if(greater(sum, maxSum)){
            maxSum = sum;
            finish = right = i;
            start = left;
        }
        else if(less(sum, NOTHING)){
            sum = 0;
            left = right = i + 1;
        }
    }
   return maxSum;   
}

auto main() -> int {
  std::vector<int> numVec{{2, 3, 4, 1, 9}};
    int start = 0, finish = 4;
  auto result = kadaneSubArraySum(numVec, start, finish);
  std::cout << "\n   maxSubArraySum = " << result << std::endl;

  return 0;  
}