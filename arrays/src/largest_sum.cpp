/* Given an array of positive and negative 
 integer s ,find a contiguous subarray whose
 sum of elements is maximized
*/
#include <iostream>
#include <vector>

int maxSubArraySum(std::vector<int>&);
void showArray(std::vector<int>&, int&);
void showResult(int&);

int main(){
    std::vector<int> nums{{14, -78, 90, -23, 4, 32, -9, 100}};
    
    int mode = 0;
    showArray(nums, mode);

    auto max = maxSubArraySum(nums);
    showResult(max);

    return 0;
}


int maxSubArraySum(std::vector<int>& array){

    int size = array.size();
    int maxSoFar = 0, maxEndingHere = 0;
    for(int i=0; i<size; i++){
        maxEndingHere += array[i];
        if(maxEndingHere < 0){
            maxEndingHere = 0;
        }
        if(maxSoFar < maxEndingHere){
            maxSoFar = maxEndingHere;
        }
    }
    return maxSoFar;
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

void showResult(int& sum){
 std::cout << "\033[1;34m\n   This is the result:\033[0m \033[1;32m" << sum << ".\033[0m\n" << std::endl;   
 std::cout << "\033[1;36m--------------------------------\033[0m\n" << std::endl;
}