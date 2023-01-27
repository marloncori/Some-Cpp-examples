#include <future>
#include <iostream>
#include <functional>

int main(){
    std::function<int(int)> fib =
        [&](int n){
            if(n<=1) return 1;
           return fib(n-1)+(n-2);
        };
    
    std::future<int> promise = std::async(std::launch::async, fib, 10);
    std::cout << " This is the fibonacci of 10 first numbers:\n";
    std::cout << promise.get() << std::endl;
}