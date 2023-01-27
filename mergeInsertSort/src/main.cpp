
#include "mergeInsertSort.h"

int main(){

    int nums[6] = {34, 78, 12, 100, 57, 67};
    size_t min = 0, max = 5, size = 6;
    
    int mode = 0;
    sorting::showArray(nums, size, mode);

    sorting::mergeSort(nums, min, max, size);
    mode = 1;
    sorting::showArray(nums, size, mode);

  return 0;
}