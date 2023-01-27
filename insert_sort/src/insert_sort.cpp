#include <vector>
#include <iostream>
#include "insert_sort.h"


bool InsertSort::isGreater(int first, int second)
{
    return first > second;
}

InsertSort::InsertSort(std::vector<int>& data) : arr(data) 
{
    size = arr.size();       
}

void InsertSort::start()
{
    size_t j = 0; 
    int temp = 0;
    for(size_t i = 0; i < size; i++){
        temp = arr[i];
        for(j = i; j > 0 && isGreater(arr[j-1], temp); j--){
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

void InsertSort::show(int mode) {
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