#include <iostream>
#include <vector>

int sumArray(std::vector<int>& arr);
void showSum(const int& val);

int main() {
    std::vector<int> nums{{14, 78, 90, 23, 4, 32}};

    auto result = sumArray(nums);
    showSum(result);

    return 0;
}

int sumArray(std::vector<int>& arr){
    int size = arr.size();
    int total = 0;
    for(auto val : arr){
        total += val;
    }
    return total;
}

void showSum(const int& val){
    std::cout << "\033[1;34m\nThe sum of the array members equals\033[0m: \033[1;36m" 
    << val << ".\033[0m" << std::endl;
}