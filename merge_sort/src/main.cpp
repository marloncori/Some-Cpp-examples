#include <vector>
#include <memory>

#include "merge_sort.h"

int main(){
    std::vector<int> nums{45, 12, 134, 56, 71, 1, 89, 74, 9, 3, 28, 31, 120, 104, 154, 200, 173, 134};
    std::unique_ptr<MergeSort> mergeSort = 
            std::make_unique<MergeSort>(MergeSort(nums));
    
    int mode = 0;
    mergeSort->show(mode);
    mergeSort->apply();

    mode = 1;
    mergeSort->show(mode);

    std::vector<int> vals{31, 28, 132, 8, 104, 40, 154, 173, 89, 37};
    std::unique_ptr<MergeSort> sorter = 
            std::make_unique<MergeSort>(MergeSort(vals));
    
    mode = 0;
    sorter->show(mode);
    sorter->apply();

    mode = 1;
    sorter->show(mode);

  return 0;
}