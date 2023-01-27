#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>

namespace algorithm {

 void Swap(int first, int second);
 
 void Heapify(std::vector<int> array, int size, int index);
 
 std::vector<int> HeapSort(std::vector<int> array, int size);
 
 void ShowUnsorted(std::vector<int> array, int size);
 
 void ShowSorted(std::vector<int> array, int size);
 
 }

 #endif // heapSort.h