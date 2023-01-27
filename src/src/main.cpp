#include <iostream>
#include <memory>

#include "quick_sort.h"
using namespace arrange;

void showUnsorted(int nums[]){
    std::cout << " Unsorted array: {";
    for(int i=0; i<12; i++){
        std::cout << nums[i] << " " << std::endl;
    }
    std::cout << "} ." << std::endl;
}

int main(){
    
    int nums[] = {34, 12, 78, 23, 90, 43, 23, 99, 57, 5, 0, 9};
    showUnsorted(nums);

    std::unique_ptr<QuickSort> unordered_vector =  std::make_unique<QuickSort>(12);

    unordered_vector->quickSort(nums, 0, 11);
    unordered_vector->showResult(nums);

    return 0;
}