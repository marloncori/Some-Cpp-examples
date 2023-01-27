
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <cstdlib>

namespace algorithms {
   template<typename T>
   void merge(T* arr, size_t left, size_t mid, size_t right){
       size_t i, j, k;
       size_t leftSize = mid - left + 1;
       size_t rightSize = right - mid;

       T* leftHalf = new T[leftSize];
       T* rightHalf = new T[leftSize];
        for(i = 0; i < leftSize; i++){
            leftHalf[i] = arr[left + i];
        }
        for(j = 0; j < rightSize; j++){
            rightHalf[j] = arr[mid + 1 + j];
        }
        i = 0, j = 0, k = left;

        while(i < leftSize || j < rightSize) {
            if(j >= rightSize || (i < leftSize && leftHalf[i] <= rightHalf[j])){
                arr[k] = leftHalf[i];
                i++;
            }
            else {
                arr[k] = rightHalf[i];
                j++;
            }
            k++;
        }
       delete[] leftHalf;
       delete[] rightHalf;
   }
   
   template<typename T>
   void mergeSort(T* arr, size_t left, size_t right){
       if(left < right){
           size_t mid = left + (right - left) / 2;
           mergeSort(arr, left, mid);
           mergeSort(arr, mid+1, right);
           merge(arr, left, mid, right);
       }
   }

   template<typename T>
   void showArray(T* arr, size_t size, int mode){
        std::string line("\n ==================================\n");
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

#endif // mergeSort.h