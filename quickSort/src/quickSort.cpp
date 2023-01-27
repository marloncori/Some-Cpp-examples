#include <iostream>
#include <vector>

#include "quickSort.h"


void QuickSort::swap(std::vector<int>& data, int first, int second){
       int temp  = data[first];
    data[first]  = data[second];
    data[second] = temp;
}

void QuickSort::partition(std::vector<int>& data, int lower, int upper){
     if(upper <= lower){
         return;
     }
     int pivot = data[lower];
     int start = lower;
     int stop  = upper;

     while(lower < upper){
         while(data[lower] <= pivot && lower < upper){
             lower++;
         }
         while(data[upper] > pivot && lower <= upper){
             upper--;
         }
         if(lower < upper){
             swap(data, upper, lower);
         }
     }
     swap(data, upper, start); // upper is the pivot position
     partition(data, start, upper-1); // pivot-1 : the upper 
                                    // for left sub array
     partition(data, upper+1, stop); // pivot+1 : the lower
                                   // for right sub array
}

QuickSort::QuickSort(std::vector<int>& data) : data(data) {
    size = data.size();
}

void QuickSort::apply(){
    partition(data, 0, size-1);
}

void QuickSort::show(int mode){
  std::string msg;
  switch(mode){
    case 0: msg = "unsorted"; break;
    case 1: msg = "sorted"; break;
    default: msg = ""; break;
  }
  std::cout << "\n   This is the " << msg << " array: \n\t{";
  for(size_t j = 0; j < size; j++){
     std::cout << data[j] << " ";
   }
   std::cout << "}\n";
   std::cout << "--------------------------------" << std::endl;
}