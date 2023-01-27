#include <iostream>
#include <vector>

auto fib(unsigned int n) -> unsigned int {
    unsigned int a, b, sum;
    a = 0; b = 1; sum = a + b;
    if(n <= 1){
        return n;
    }
    for(unsigned int i = 2; i < n; ++i){
        a = b;
        b = sum;
        sum = a + b;
    }
   return sum;
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