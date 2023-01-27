
#include <iostream>
#include <vector>

void swap(int *f, int *s){
    int tmp = *f;
    *f = *s;
    *s = tmp;
}

int partition(std::vector<int>&data, int begin, int end){
    int pivot = data[begin];
    int count = 0;
    for(int i = begin+1; i<=end; i++){
       if(data[i] == pivot){
	 count++;
       }
    }
    int pivotId = begin + count;
    swap(&data[pivotId], &begin);
    int i = begin, j = end;
    while(i < pivotId && j < pivotId){
        while(data[i] <= pivot){
            i++; 
        }
        while(data[j] > pivot){
            j--;
        }
        if(i < pivotId && j > pivotId){
            swap(&data[i++], &data[j--]);
        }
    }

   return pivotId;
}

void quickSort(std::vector<int>&data, int begin, int end){
    if(begin > end){
       return;
    }
    int index = partition(data, begin, end);
    quickSort(data, begin, index-1);
    quickSort(data, index+1, end);
}

int getMax(std::vector<int>data){
    int max = data[0], maxCount = 1;
    int current = data[0], currCount = 1;
    quickSort(data, 0, (data.size()-1));
    for(int i=1; i<data.size(); i++){
        if(data[i] == data[i-1]){
            currCount++;
        }
        else{
            currCount = 1;
            current = data[i];
        }
        if(currCount > maxCount){
            maxCount = currCount;
            max = current;
        }
    }
    return max;
}

void test(){
    std::vector<int> nums{{12, 47, 89, 120, 63, 2, 51, 37 }};
    auto max = getMax(nums);
    std::cout << "\033[1;32m\n The greatest number in array is: " << max << ".\033[0m" << std::endl;

    std::vector<int> nums2{{-78, 54, 23, 1, 99, 137, -12}};
    max = getMax(nums2);
    std::cout << "\033[1;33m\n And the greatest number in array2 is: " << max << ".\033[0m" << std::endl;    
}

int main(){

    test();

    return 0;
}