#include <iostream>
#include <vector>

void swap(int* first, int* second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partition(std::vector<int>&data, int begin, int end){
    int pivot = data[begin];
    int count = 0;
    for(int i=begin+1; i<=end; i++){
        if(data[i] == pivot){
            count++;
        }
    }
    // put pivot element in its correct partition
    int pivotIndex = begin + count;
    swap(&data[pivotIndex], &begin);
    //sort left and right parts of pivot element
    int i = begin, j = end;
    while(i < pivotIndex && j < pivotIndex){
        while(data[i] <= pivot){
            i++;
        }
        while(data[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(&data[i++], &data[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(std::vector<int>&data, int begin, int end){
    if(begin > end){
        return;
    }
    int index = partition(data, begin, end);
    quickSort(data, begin, index-1);
    quickSort(data, index+1, end);
}

void sortAndShowRepeated(std::vector<int> data){
    int count = 0;
    int size = data.size();
    quickSort(data, 0, size-1);
    std::cout << "\n\033[1;36m Repeating elements are:\033[0m";
    for(int i=1; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(data[i] == data[j]){
                std::cout << "\033[1;32m " << data[i] << "\033[0m";
                count++;
            }
        }
    }
    if(count == 0){
       std::cout << "\n\t\033[1;32m[INFO]\033[0m \033[1;34mNo repeated elements have been found\033[0m\n" << std::endl;
    }
}

int main(){
    
    std::vector<int> arr{{10, 23, 56, 47, 23, 79, 47, 100, 2}};
    sortAndShowRepeated(arr);

    std::vector<int> arr2{{10, 56, 47, 79, 2}};
    sortAndShowRepeated(arr2);

  return 0;
}