#include <iostream>
#include <vector>
#include <memory>

int partition(int arr[], int begin, int end){
    int pivot = arr[begin];
    int count = 0;

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

void showUnsorted(int arr[]){
    std::cout << "\n The unsorted list = {";
 
    for(int i = 0; i < 12; i++){
        std::cout << arr[i] << " " ;
    }
    std::cout << "}. " << std::endl;
}


void quickSort(int arr[], int begin, int end){
    if(begin > end){
        return;
    }
    //partitioning the vector
    int partitionIndex = partition(arr, begin, end);
    quickSort(arr, begin, partitionIndex-1);
    quickSort(arr, partitionIndex+1, end);

}

void showSorted(int arr[]){
    std::cout << "\n The sorted list = {";
    for(int i=0; i<12; i++){
        std::cout << arr[i] << " " ;
    }
    std::cout << "}. " << std::endl;
}
 
int main(){
    
    int nums[] = {34, 12, 78, 23, 90, 43, 23, 99, 57, 5, 0, 9};

    showUnsorted(nums);
    quickSort(nums, 0, (12-1));
    showSorted(nums);

    quickSort(nums, 0, (12-1));
    showSorted(nums);

    quickSort(nums, 0, (12-1));
    showSorted(nums);

    quickSort(nums, 0, (12-1));
    showSorted(nums);

    quickSort(nums, 0, (12-1));
    showSorted(nums);

     quickSort(nums, 0, (12-1));
    showSorted(nums);

    return 0;
}