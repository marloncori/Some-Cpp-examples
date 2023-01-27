#ifndef MERGE_INSERT_SORT_H
#define MERGE_INSERT_SORT_H

#include <iostream>
#include <cstring>

namespace sorting {

  template<typename T>
  void insertSort(T* arr, size_t start, size_t end){
      size_t i = 0, j = 0;
      T* ptrArr = arr;
      for(i = start; i < end; i++){
          T temp= ptrArr[i];
          for( j = i; j > start && temp < ptrArr[j-1]; j--){
              ptrArr[j] = ptrArr[j-1];
          }
          ptrArr[j] = temp;
      }
  }
  
  template<typename T>
  void merge(T* arr, size_t min, size_t max, size_t mid){
      size_t firstIndex = min;
      size_t secondIndex = mid + 1;

      T* ptr = arr;
      size_t size = sizeof(ptr) / sizeof(ptr[0]);
      int* tempArr = new int[size];

      for(size_t index = min; index <= max; index++){
          if(firstIndex <= mid &&
           (secondIndex < max || ptr[firstIndex] <= ptr[secondIndex])) {
               tempArr[index] = arr[firstIndex];
               firstIndex++;
           }
           else {
               tempArr[index] = arr[secondIndex];
               secondIndex++;
           }
      }
      memcpy(ptr + min, tempArr + min, (max - min) * sizeof(T));
      /*or: for(int index = min; index <= max; index++){
               ptr[index] = tempArr[index];
      }*/
  }
  template<typename T>
  void mergeSort(T* arr, size_t min, size_t max, size_t threshold){
      if((max - min) <= threshold){
          insertSort(arr, min, max);
      }
      else {
          size_t mid = (max + min) >> 1;
          mergeSort(arr, min, mid, threshold);
          mergeSort(arr, mid, max, threshold);
          merge(arr, min, max, mid);
      }
  }

  template<typename T>
  void showArray(T* arr, size_t size, int mode){
       std::string line("\n\n ===================================\n");
       std::string msg;
       switch(mode){
           case 0: msg = "unsorted"; break;
           case 1: msg = "sorted"; break;
           default: msg = ""; break;
       }
        std::cout << line << std::endl;
       std::cout << "\n This is the " << msg << " array: \n{";
       for(int j = 0; j < size; j++){
           std::cout << arr[j] << " ";
       }
       std::cout << "}\n";
       std::cout << line << std::endl;
   }
}

#endif // mergeInsertSort.h