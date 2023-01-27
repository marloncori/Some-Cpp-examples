
#include <iostream>
#include "mergeSort.h"

int main(){
    int nums[6] = {34, 78, 12, 100, 57, 67};
    size_t nums_min = 0, nums_max = 5, nums_size = 6;
    
    int mode = 0;
    algorithms::showArray(nums, nums_size, mode);
    algorithms::mergeSort(nums, nums_min, nums_max);
    
    mode = 1;
    algorithms::showArray(nums, nums_size, mode);
    
    float vals[7] = {78.01, 34.23, 101.35, 12.08, 87.38, 57.99, 1.45};
    size_t vals_min = 0, vals_max = 6, vals_size = 7;
    
    mode = 0;
    algorithms::showArray(vals, vals_size, mode);
    algorithms::mergeSort(vals, vals_min, vals_max);

    mode = 1;
    algorithms::showArray(vals, vals_size, mode);

  return 0;
}