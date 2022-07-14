#include <iostream>
#include "arrays.h"

/*namespace algorithms {
 template<typename T, size_t N>
 void bubbleSort(T* arr, N size){ 
	
 }
}*/
constexpr size_t numSize = 5;
constexpr size_t arrSize = 7;

int main(){
	int nums[5] = {34, 57, 89, 13, 7};
	std::vector<long> vec{123, 456, 789, 381, 501, 732};
	double vals[7] = {11.34, 33.21, 57.05, 89.73, 102.17, 38.02, 26.43};
 
    arrays::show(nums, 0);
    vectors::show(vec, 0);
    arrays::show(vals, 0);
	
	
  return 0;
}
