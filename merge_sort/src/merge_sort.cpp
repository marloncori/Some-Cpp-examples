#include <iostream>
#include <vector>

#include "merge_sort.h"

void MergeSort::merge(std::vector<int>& data, std::vector<int>& tempArr, 
             int lowerIndex, int middleIndex, int upperIndex){
    int lowerStart = lowerIndex;
    int lowerStop = middleIndex;
    int upperStart = middleIndex + 1;
    int upperStop = upperIndex;
    int counter = lowerIndex;

    while(lowerStart <= lowerStop && upperStart <= upperStop){
        if(data[lowerStart] < data[upperStart]){
            tempArr[counter++] = data[lowerStart++];
        }
        else {
            tempArr[counter++] = data[upperStart++];
        }
    }
    while(lowerStart <= lowerStop){
        tempArr[counter++] = data[lowerStart++];
    }
    while(upperStart <= upperStop){
        tempArr[counter++] = data[upperStart++];
    }

    for(int i = lowerIndex; i <= upperIndex; i++){
        data[i] = tempArr[i];
    }             
}

void MergeSort::sort(std::vector<int>& data, std::vector<int>& tempArr, 
             int lowerIndex, int upperIndex){
    if(lowerIndex >= upperIndex){
        return;
    }
    int middleIndex = (lowerIndex + upperIndex) / 2;
    sort(data, tempArr, lowerIndex, middleIndex);
    sort(data, tempArr, middleIndex+1, upperIndex);
    merge(data, tempArr, lowerIndex, middleIndex, upperIndex);
}

MergeSort::MergeSort(std::vector<int>& data) : data(data) {
    size = data.size();
}

void MergeSort::apply(){
    std::vector<int> tempArray(size);
    sort(data, tempArray, 0, size-1);

}

void MergeSort::show(int mode){
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