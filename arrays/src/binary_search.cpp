#include <iostream>
#include <vector>

bool isEqual(int&, int&);
bool isLower(int&, int&);
int binarySearch(std::vector<int>&, int&);
void showResult(const int&);

int main(){
    std::vector<int> nums{{14, 78, 90, 23, 4, 32, 49}};
    int query = 23;

    auto result = binarySearch(nums, query);
    showResult(result);

    query = 3;
    
    result = binarySearch(nums, query);
    showResult(result);

    return 0;
}

bool isEqual(int& first, int& second){
    return first == second;
}


bool isLower(int& first, int& second){
    return first < second;
}

int binarySearch(std::vector<int>& arr, int& num){
    int size = arr.size();
    int mid, low = 0;
    int high = size - 1;

    while(low <= high){
        mid = low + (high - low) / 2; //to avoid overflow
        if(isEqual(arr[mid],num)){
            return mid;
        }
        else {
            if(isLower(arr[mid],num)){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
    }
    return -1;
}

void showResult(const int& val){
    if(val == -1){
        std::cout << "\033[1;36m\nThe result of binary search equals -1\033[0m: \033[1;32m" 
        << " No value has been found!\033[0m\n" << std::endl;    
    } else {
        std::cout << "\033[1;34m\nThe result of binary search is\033[0m: \033[1;36m" 
        << " element at index #" << val << ".\033[0m\n" << std::endl;
    }   
}