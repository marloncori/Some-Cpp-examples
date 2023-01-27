#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Input vector
    std::vector<int> v{{ 10, 20, 30, 30, 30, 40, 50 }};
  
    // Print vector
    std::cout << " --> Vector contains: {";
    for(auto& i : v){
        std::cout << " " << i << " ";
    }
    std::cout << "} \n" << std::endl;
  
    std::vector<int>::iterator low1, low2, low3;
    low1 = std::lower_bound(v.begin(), v.end(), 30);
        low2 = std::lower_bound(v.begin(), v.end(), 35);  
            low3 = std::lower_bound(v.begin(), v.end(), 55);
    
    std::cout << " ---> Lower bound for element 30 at index: " << (low1 - v.begin()) << std::endl;
        std::cout << "\t ---> Lower bound for element 35 at index: " << (low2 - v.begin()) << std::endl;
            std::cout << "\t\t ---> Lower bound for element 55 at index: " << (low3 - v.begin()) << std::endl;
    
    return 0;
}