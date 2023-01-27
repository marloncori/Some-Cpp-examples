#include <iostream>
#include "binary_search.h"

algorithm::BinarySearch::BinarySearch(){
    this->begin = 0;
    this->end = 0;
    this->element = 0;
}

algorithm::BinarySearch::~BinarySearch(){
    std::cout << "\n\t Thank you for using binary search." << std::endl;
}
            
int algorithm::BinarySearch::start(int numbers[], int left, int right, int query){
    this->begin = left;
    this->end = right;
    this->element = query;

    if(this->end >= this->begin) {
        int mid = begin + (end - begin) / 2;
    
        if(numbers[mid] == this->element){
            this->index = mid;
             return index;
        }
        if(numbers[mid] > this->element){
             return algorithm::BinarySearch::start(numbers, begin, mid-1, element);
        }

      return algorithm::BinarySearch::start(numbers, mid+1, end, element);
    }
  return -1;
}

void algorithm::BinarySearch::show(int result){
    (result == -1)
        ? std::cout << "\t Element is not present in array!"
        : std::cout << "\t " << this->element << " is present at index --> " << result << std::endl;
}
