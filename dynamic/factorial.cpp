#include <iostream>
#include <vector>
#include <map>

auto factorial(unsigned long n) -> unsigned long {
    std::map<std::string, unsigned long> memo{};
    std::string key = std::to_string(n);
    if(n == 0 ) {
       return 1;
    }
    
    std::map<std::string, unsigned long>::iterator it = memo.find(key);
    if(it->first != key){
        memo[key] = factorial(n-1) * n;
    }
  return memo.at(key);
}


auto main() -> int {

    std::vector<unsigned long> range{};
    for(unsigned long i=1; i<30; i++){
        range.push_back(i);
    }

    for(auto& i : range){
        std::cout << "  Factorial --> " << i+1 << "! = " << factorial(i) << "\n";
    }
    std::cout << std::endl;

  return 0;
}