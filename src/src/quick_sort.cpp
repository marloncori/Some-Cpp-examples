#include "quick_sort.h"
#include <iostream>

int arrange::QuickSort::partition(int arr[], int start, int finish){
    this->begin = start;
    this->end = finish;
    this->pivot = arr[begin];
    this->count = 0;
    for(int i=begin+1; i<=end; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    // put pivot element in its correct position
    int pivotIndex = begin + count;
    std::swap(arr[pivotIndex], arr[begin]);

    //sort left and right parts of pivot element
    int i = begin, j = end;
    while(i < pivotIndex && j <pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            std::swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

arrange::QuickSort::QuickSort(int size){
    this->size = size;
    std::cout << "\n Quick sorter created!" << std::endl;
}

arrange::QuickSort::~QuickSort(){
    std::cout << " Quick sort has ended." << std::endl;
}

void arrange::QuickSort::quickSort(int arr[], int begin, int end){
    if(begin > end){
        return;
    }
    //partitioning the vector
    int partitionIndex = partition(arr, begin, end);
    quickSort(arr, begin, partitionIndex-1);
    quickSort(arr, partitionIndex+1, end);
}

void arrange::QuickSort::showResult(int arr[]){
    std::cout << "\n The sorted list = {";
    for(int i=0; i<this->size; i++){
        std::cout << arr[i] << " " ;
    }
    std::cout << " }. " << std::endl;
}
 
