#include <iostream>

constexpr unsigned int OCCUPIED_SIZE = 5;
constexpr unsigned int TOTAL_CAPACITY = 10;

auto equalZero(unsigned int first, unsigned int second) -> bool {
    return (first == 0 || second == 0);
}

auto isLess(unsigned int first, unsigned int second) -> bool {
    return (first < second);
}

auto knapsackResursive(const unsigned int capacity, const unsigned int weight[], 
const unsigned int value[], const unsigned int members) -> unsigned int {
  auto lastMember = members - 1;

  if(equalZero(capacity, members)){
      return 0;
  }   
  if(isLess(weight[members-1], capacity)){
      return knapsackResursive(capacity, weight, value, lastMember);
  }
  else {
      return std::max(
          value[lastMember] + knapsackResursive(capacity-weight[lastMember], weight, value, lastMember),
              knapsackResursive(capacity, weight, value, lastMember));
  }
}

int main(){
    unsigned int nums[10] = {12, 34, 56, 78, 5};
    unsigned int weights[6] = {2, 1, 4, 5, 7, 3};

   auto result = knapsackResursive(TOTAL_CAPACITY, weights, nums, OCCUPIED_SIZE);
   std::cout << result << std::endl;

 return 0;
}