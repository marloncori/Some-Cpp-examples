#include <iostream>
#include <map>

std::map<std::string, unsigned int> memo{};
auto gridTraveller(unsigned int m, unsigned int n) -> unsigned int {
    if(m == 1 && n == 1){
        return 1;
    }
    if(m == 0 || n == 0){
        return 0;
    }
    std::string key = std::to_string(std::min(m, n)) 
        + " , " + std::to_string(std::max(m, n));
    
    auto it = memo.find(key);
    if(it->first != key){
        memo[key] = gridTraveller(m, n-1) + gridTraveller(m-1, n);
    }
  return memo.at(key);
}

auto main() -> int {
    for(int i=1; i<10; i++){
        std::cout << gridTraveller(i, i+1) << std::endl;
    }

    return 0;
}