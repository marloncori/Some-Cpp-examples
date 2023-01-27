#include <iostream>
#include <errno.h>
#include <system_error>

#include "ArrayStack.h"

auto main() -> int {
   std::string line("\033[1;33m--------------------------------------------------\033[0m");  
   ArrayStack* stack = new ArrayStack(90);
 
   for(int i = 0; i < 90; i++){
       std::cout << line << std::endl;
       std::cout << "\n\033[1;36mElement " << i << " has been \n\tpushed to the Stack!\033[0m\n" << std::endl;
       std::cout << line << std::endl;
       stack->push(i);
   }
   /*for(int i = 0; i <= 15; i++){
       stack.pop();
   }*/
   stack->pushVariable(50);
   stack->print();
   stack->popVariable();
   stack->popVariable();
   
   std::cout << "\n" << line << std::endl;
   std::cout << " \n Is the Stack empty? Answer: " << (stack->isEmpty() == 0 ? "FALSE!" : "TRUE.") << "\n" << std::endl;
   std::cout << line << std::endl;
   std::cout << " \n\t What is the Stack size now? SIZE: " << stack->size() << "\n" << std::endl;
   std::cout << line << std::endl;
   stack->print();
  
  return 0;
}