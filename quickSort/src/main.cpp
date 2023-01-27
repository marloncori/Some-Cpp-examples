#include <vector>
#include <memory>

#include "quickSort.h"

int main(){
    std::vector<int> numbers{12, 45, 134, 56, 71, 1, 89, 74, 9, 3, 28, 31, 120, 104, 154, 200, 173, 134};
    std::unique_ptr<QuickSort> quickSort = 
            std::make_unique<QuickSort>(QuickSort(numbers));
    
    int mode = 0;
    quickSort->show(mode);
    quickSort->apply();

    mode = 1;
    quickSort->show(mode);

    std::vector<int> nums{31, 28, 120, 9, 104, 40, 154, 200, 173, 89};
    std::unique_ptr<QuickSort> sorter = 
            std::make_unique<QuickSort>(QuickSort(nums));
    
    mode = 0;
    sorter->show(mode);
    sorter->apply();

    mode = 1;
    sorter->show(mode);

  return 0;
}