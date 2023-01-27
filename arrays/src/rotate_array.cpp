#include <iostream>
#include <vector>

void swap(int*, int*);
void reverseArray(std::vector<int>&, int, int);

void rotateArray(std::vector<int>&, int&);
void showArray(std::vector<int>&, int&);

int main(){
    std::vector<int> nums{{14, 78, 90, 23, 4, 32, 49, 100}};
    
    int mode = 0;
    showArray(nums, mode);

    mode = 1;
    int position = 2;
   
    rotateArray(nums, position);
    showArray(nums, mode);

    return 0;
}

void swap(int* first, int* second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void reverseArray(std::vector<int>& arr, int start, int end){
    for(int i=start, j=end; i<j; i++, j--){
        swap(&arr[i], &arr[j]);
    }    
}

void rotateArray(std::vector<int>& arr, int& pos){
    int n = arr.size();
    reverseArray(arr, 0, pos-1);
    reverseArray(arr, pos, n-1);
    reverseArray(arr, 0, n-1);
}

void showArray(std::vector<int>& arr, int& mode){
    std::string msg;
     switch(mode){
        case 0: msg = "original"; break;
        case 1: msg = "rotated"; break;
        default: msg = ""; break;
     }
    std::cout << "\033[1;34m\n   This is the\033[0m \033[1;32m" << msg << "\033[0m \033[1;34marray: \n\t\033[1;33m{";
       for(size_t j = 0; j < arr.size(); j++){
           std::cout << arr[j] << " ";
       }
    std::cout << "}\033[0m\n";
    std::cout << "\033[1;36m--------------------------------\033[0m\n" << std::endl;
}