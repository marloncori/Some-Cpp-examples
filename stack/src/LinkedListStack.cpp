#include <iostream>
#include <cstdlib>
#include <errno.h>
#include <system_error>

#include "LinkedListStack.h"

auto main() -> int {
   LinkedListStack* stack = new LinkedListStack();
   std::string line2("\n\033[1;34m-------------------------------------------------------\n\033[0m");
   for(int i = 1; i <= 100; i++){
       if(i % 7 == 0){
           std::cout << line2 << "\033[1;32m\t --> Element " << i << " pushed into Stack!\033[0m" << line2 << std::endl;
       }
       stack->push(i);
   }

   std::cout << line2 << " This was the number at the stop of the stack: " << stack->pop() << line2 << std::endl;
   std::cout << " \n Is the Stack empty? Answer: " << (stack->isEmpty() == 0 ? "FALSE!" : "TRUE.") << "\n" << std::endl;
   std::cout << line2 << std::endl;
   std::cout << " \n\t What is the Stack size now? SIZE: " << stack->getSize() << "\n" << std::endl;
   std::cout << line2 << std::endl;
    stack->show();

   for(int i = 100; i > 0; i--){
       if(i == 1) break;
      std::cout << line2 << "\033[1;32m\t xxxx deleted number: " << stack->pop() << " \033[0m" << line2 << std::endl;
   }
   stack->show();

  return 0;
}
