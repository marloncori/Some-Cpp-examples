#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(std::vector<int>& arr, int begin, int end, int value){
    int pivotIndex = begin +(end-begin)/2;
    if(end > begin){
        if(arr[pivotIndex] == value){
           return pivotIndex;
        }
        if (arr[pivotIndex] > value){
            return binarySearch(arr, begin, pivotIndex-1, value);
        }
       return binarySearch(arr, pivotIndex+1, end, value); 
    }
}

bool compare(int m, int n) {
    return (m == n);
}

int main(){
    std::vector<int> nums{{3, 5, 7, 9, 18, 21}};
    int query = 9;
    bool res = std::binary_search(nums.begin(), nums.end(), query, compare);
    auto index = binarySearch(nums, 0, 5, query);

    if(res){
        std::cout << " The number " << query << " is present in array at index " << index << std::endl;
    }
    else {
        std::cout << " The searched number (" << query << ") is not present in vector." << std::endl;
    }

    query = 77;
    res = std::binary_search(nums.begin(), nums.end(), query, compare);
    index = binarySearch(nums, 0, 5, query);

    if(res){
        std::cout << " The number " << query << " is present in array at index " << index << std::endl;
    }
    else {
        std::cout << " The searched number (" << query << ") is not present in vector." << std::endl;
    }

  return 0;
}