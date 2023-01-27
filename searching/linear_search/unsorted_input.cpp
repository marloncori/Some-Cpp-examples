#include <iostream>
#include <vector>

bool isEqual(int& first, int& second){
    return first == second;
}


bool isLower(int& first, int& second){
    return first < second;
}

int linearSearch(std::vector<int>& arr, int& num){
    int size = arr.size();
    bool found = false;
    int index = -1;

    for(int i=0; i<size; i++){
       if(isEqual(arr[i],num)){
            index = i;
            found = true;
       }
    }
    if(found){
        return index;
    }
  return index;
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

int main(){
    std::vector<int> nums{{14, 78, 90, 23, 4, 32, 49}};
    int query = 23;

    auto result = linearSearch(nums, query);
    showResult(result);

    query = 3;
    result = linearSearch(nums, query);
    showResult(result);

    return 0;

  return 0;  
}