#include <iostream>
#include <vector>
#include <algorithm>

auto main() -> int {
   std::vector<int> vec{{4, 2, 5, 3, 1, 2}};
   auto result = std::is_heap_until(vec.begin(), vec.end());

   std::cout << *result  << " is the first element which "
        << "violates the max heap." << std::endl;

   std::vector<int> val{{7, 6, 5, 4, 3}};
   result = std::is_heap_until(val.begin(), val.end());

   if(result == std::end(val)){
      std::cout << "Entire range is valid heap." << std::endl;
   }
  
  return 0;
}