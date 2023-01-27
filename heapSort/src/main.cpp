#include <iostream>
#include <vector>
#include "heapSort.h"

int main()
{
    std::vector<int> arr = { 12, 11, 13, 5, 6, 22, 37, 49, 7};
    int length = arr.size();
  
    algorithm::ShowUnsorted(arr, length);
    auto result = algorithm::HeapSort(arr, length);
    algorithm::ShowSorted(result, length);
 
 return 0;
}