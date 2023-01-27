#include <iostream>
#include <vector>

int linearSearch(std::vector<int>&, int&);
void showResult(const int&);

int main(){
    std::vector<int> nums{{14, 78, 90, 23, 4, 32, 49}};
    int query = 90;

    auto result = linearSearch(nums, query);
    showResult(result);

    query = 3;
    
    result = linearSearch(nums, query);
    showResult(result);

    return 0;
}

int linearSearch(std::vector<int>& arr, int& num){
    for(int val=0; val<arr.size(); val++){
        if(num == arr[val]){
            return val;
        }
    }
    return -1;
}

void showResult(const int& val){
    if(val == -1){
        std::cout << "\033[1;36m\nThe result of sequential search equals -1\033[0m: \033[1;32m" 
        << " Value is not present in vector!\033[0m\n" << std::endl;    
    } else {
        std::cout << "\033[1;34m\nThe result of sequential search is\033[0m: \033[1;36m" 
        << "\n the search number has been found at\033[0m\n\033[1;33mindex number " << val << ".\033[0m\n" << std::endl;
    }   
}