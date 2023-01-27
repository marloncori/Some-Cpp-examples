
#include <iostream>
#include <vector>

#define NOTHING 0

auto less(int first, int second) -> bool {
    return (first < second);
}

auto maxSubArraySum(const std::vector<int>& vec) -> int {
    int maxSoFar = 0;
    int maxEndingHere = 0;
    
    for(unsigned int i=0; i<vec.size(); ++i){
        maxEndingHere += vec[i];
        if(less(maxEndingHere, NOTHING)){
            maxEndingHere = 0;
        }
        if(less(maxSoFar, maxEndingHere)){
            maxSoFar = maxEndingHere;
        }
    }
    return maxSoFar;   
}

auto main() -> int {
  std::vector<int> numVec{{2, 3, 4, 1, 9}};

  auto result = maxSubArraySum(numVec);
  std::cout << "   maxSubArraySum = " << result << std::endl;

  return 0;  
}