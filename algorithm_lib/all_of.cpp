#include <iostream>
#include <vector>
#include <algorithm>

bool isOdd(int n) {
    return (n % 2 != 0);
}

int main(){
    std::vector<int> nums{{3, 5, 7, 13, 9, 21}};
    bool res = std::all_of(nums.begin(), nums.end(), isOdd);
    if(res){
        std::cout << " All the vector numbers are odd!" << std::endl;
    }
    else {
        std::cout << " At least one vector element is even!" << std::endl;
    }
  return 0;
}