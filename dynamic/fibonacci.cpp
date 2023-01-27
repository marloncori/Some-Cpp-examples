#include <iostream>
#include <vector>
#include <map>

std::map<std::string, unsigned int> memo{};
auto fib(unsigned int n) -> unsigned int {
    std::string key = std::to_string(n);
    if(n <= 2 ) {
       return 1;
    }
    std::map<std::string, unsigned int>::iterator it = memo.find(key);
    if(it->first != key){
        memo[key] = fib(n - 1) + fib(n - 2);
    }
  return memo.at(key);
}

auto main() -> int {

    std::vector<unsigned int> range{};
    for(int i=1; i<50; i++){
        range.push_back(i);
    }

    for(auto& i : range){
        std::cout << fib(i) << " ";
    }
    std::cout << std::endl;

  return 0;
}