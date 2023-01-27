#include <iostream>
#include <vector>

#include "selection_sort.h"

SelectionSort::SelectionSort(std::vector<int>& data) : arr(data){
     size = arr.size();
}

void SelectionSort::apply(){
    int max;
    for(i = 0; i < (size - 1); i++){
        max = 0;
        for(j = 1; j < (size - 1 - i); j++){
            if(arr[j] > arr[max]){
                max = j;
            }
        }
        temp = arr[size - 1 - i];
        arr[size - 1 - i] = arr[max];
        arr[max] = temp;
    }
}

void SelectionSort::start(){
    int min;
    for(i = 0; i < (size - 1); i++){
        min = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void SelectionSort::show(int mode) {
       std::string msg;
       switch(mode){
           case 0: msg = "unsorted"; break;
           case 1: msg = "sorted"; break;
           default: msg = ""; break;
       }
       std::cout << "\n   This is the " << msg << " array: \n\t{";
       for(size_t j = 0; j < size; j++){
           std::cout << arr[j] << " ";
       }
       std::cout << "}\n";
       std::cout << "--------------------------------" << std::endl;
}