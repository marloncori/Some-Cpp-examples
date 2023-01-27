#include <iostream>
#include <vector>
#include <algorithm>

auto show(bool& result) {
   if(!result){
      std::cout << "\033[1;34m\n Given sequence is not a \'max heap\'.\033[0m" << std::endl;
   }
   else {
      std::cout << "\033[1;32m\n Given sequence IS a \'max heap\'.\033[0m" << std::endl;
   }
}

auto main() -> int {
   std::vector<int> nums{{3, 5, 2, 1, 4}};
   bool result;

   result = std::is_heap(
       nums.begin(), nums.end());
   show(result);

   std::vector<int> vals{{5, 4, 3, 2, 1, 0}};
   
   result = std::is_heap(
       vals.begin(), vals.end());
    show(result);

  return 0;
}