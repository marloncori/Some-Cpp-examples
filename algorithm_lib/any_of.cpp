#include <iostream>
#include <vector>
#include <algorithm>

bool isEven(int n) {
    return (n % 2 == 0);
}

int main(){
    std::vector<int> nums{{2, 3, 5, 7, 8, 6, 10, 13, 4, 21}};
    bool res = std::any_of(nums.begin(), nums.end(), isEven);

    if(res){
        std::cout << " At least one number in vector is even!" << std::endl;
    }
    else {
        std::cout << " Al the vector elements are odd, not even!" << std::endl;
    }
  return 0;
}