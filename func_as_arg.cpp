#include <iostream>
#include <functional>

void f(int i, int j) {
   std::cout << " The values are:\n\ti = " << i << "\n\tj = " << j << std::endl;
}

void run(std::function<void()> fn) {
   fn();
}

template<typename T>
void start(T const & fn) {
    fn();
}

int main(){

 int x = 7, y = 11;
 //invoke it with a lambda
 run([]() { f(1, 2); });

 std::cout << " ----------------------- " << std::endl;

 start([x, y]() { f(x, y); });
 
 return 0;
}