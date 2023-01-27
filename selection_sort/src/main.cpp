#include <vector>
#include <memory>

#include "selection_sort.h"

int main(){
    std::vector<int> numbers{12, 45, 134, 56, 71, 1, 89, 74, 9, 3, 28, 31, 120, 104, 154, 200, 173, 134};
    std::unique_ptr<SelectionSort> selectionSort = 
            std::make_unique<SelectionSort>(SelectionSort(numbers));
    
    int mode = 0;
    selectionSort->show(mode);
    selectionSort->apply();

    mode = 1;
    selectionSort->show(mode);

    std::vector<int> nums{31, 28, 120, 9, 104, 40, 154, 200, 173, 89};
    std::unique_ptr<SelectionSort> selectionSorter = 
            std::make_unique<SelectionSort>(SelectionSort(nums));
    
    mode = 0;
    selectionSorter->show(mode);
    selectionSorter->start();

    mode = 1;
    selectionSorter->show(mode);

  return 0;
}