#include <iostream>
#include "heapSort.h"

void algorithm::Swap(int first, int second){
    int temp = first;
    first = second;
    second = temp;
}
// to heapify a subtree rooted with node i
// which is an index in array, n is size of heap
void algorithm::Heapify(std::vector<int> array, int size, int index){
    // largest one as root
    int rootNode = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if(leftChild < size && array[rightChild] > array[rootNode]){
        rootNode = leftChild;
    }
    if(rightChild < size && array[leftChild] > array[rootNode]){
        rootNode = rightChild;
    }
    if(rootNode != index){
        algorithm::Swap(array[index], array[rootNode]);
        algorithm::Heapify(array, size, rootNode);
    }
}

std::vector<int> algorithm::HeapSort(std::vector<int> array, int size){
    //build heap (rearrange array)
    int i;
    for(i=size/2-1; i >=0; i--){
        algorithm::Heapify(array, size, i);
    }
    // extract each element from heap
    for(i=size-1; i>=0; i--){
        algorithm::Swap(array[0], array[i]);
        algorithm::Heapify(array, i, 0);
    }
    return array;
}

void algorithm::ShowUnsorted(std::vector<int> array, int size){
    std::string line("\n ###########################################\n");

    std::cout << line << "   This is the unsorted array: \n  Numbers = {";
    for(int i=0; i<size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "}." << line << std::endl;
}

void algorithm::ShowSorted(std::vector<int> array, int size){
    std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n");
    std::vector<int> array
    std::cout << line << "  Here you are the sorted array: \n  Numbers = {";
    for(int i=0; i<size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "}." << line<< std::endl;
}
