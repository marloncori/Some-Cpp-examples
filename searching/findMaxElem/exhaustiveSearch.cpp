#include <iostream>
#include <vector>

int getMaxElem(std::vector<int>&data){
    int size = data.size(), count;
    int max = data[0], maxCount = 1;
    for(int i=0; i<size; i++){
        count = 1;
        for(int j = i+1; j<size; j++){
            if(data[i] == data[j]){
                count++;
            }
        }
        if(count > maxCount){
            max = data[i];
            maxCount = count;
        }
    }
    return max;
}

void test(){
    std::vector<int> nums{{12, 47, 89, 63, 2, 51, 37 }};
    auto max = getMaxElem(nums);
    std::cout << "\033[1;35m\n The greatest number in array is: " << max << ".\033[0m" << std::endl;

    std::vector<int> nums2{{-78, 54, 23, 1, 99, -12}};
    max = getMaxElem(nums2);
    std::cout << "\033[1;34m\n And the greatest number in array2 is: " << max << ".\033[0m" << std::endl;    
}

int main(){

    test();

    return 0;
}