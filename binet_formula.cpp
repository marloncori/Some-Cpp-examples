
#include <iostream>
#include <cmath>

long fibonacci(long n){
    return (1/std::sqrt(5))*(std::pow((1+std::sqrt(5))/2, n) - std::pow((1-std::sqrt(5))/2, n));
}

int main(){

    for(long i=0; i<20; i++){
        std::cout << " " << fibonacci(i) << " ";
    }

    return 0;
}