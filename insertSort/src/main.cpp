#include <iostream>
#include <memory>

#include "insertSort.h"

int main(){

    int nums[7] = {78, 56, 34, 9, 12, 83, 20};
    std::cout << "\n This is the UNSORTED array: \n{";
    for(int i=0; i<7; i++){
        std::cout << nums[i] << " ";
    }
    std::cout << "}\n";

    algorithms::InsertSort* insertSort = new algorithms::InsertSort(nums);
    
    float* result = insertSort->start();
    std::cout << "\n And this is the sorted array: \n{";
    for(int j=0; j<7; j++){
        std::cout << result[j] << " ";
    }
    std::cout << "}\n";

    //delete insertSort;
    //delete[] result;

    return 0;
}