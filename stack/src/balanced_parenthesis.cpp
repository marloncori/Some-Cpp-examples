#include <iostream>
#include <sstream>
#include <utility>

#include "LinkedListStack.h"

auto analysis(LinkedListStack* stack, int mode) -> std::pair<bool, std::string> {
    auto val = stack->peek();
    char data = stack->pop();
    bool result;
    std::stringstream ss;

    switch(mode){
        case 1:
            if(val != '{') {
               ss << "\n\033[1;36m  [INFO] This was the stored data: " << data << " ...\033[0m";  
               result = false;
            }
            break;
        case 2:
            if(val != '[') {
               ss << "\n\033[1;36m  [INFO] This was the stored data: " << data << " ...\033[0m";  
               result = false;
            }
            break;
        case 3:
            if(val != '(') {
               ss << "\n\033[1;36m [INFO] This was the stored data: " << data << " ...\033[0m";  
               result = false;
            }
            break;
    }
  return std::make_pair(result, ss.str());
}

auto isBalancedParenthesis(const std::string& expn) -> std::pair<bool, std::string> {
    auto stack = new LinkedListStack();

    for(auto ch : expn){
        switch(ch){
            case '{':
            case '[':
            case '(':
                stack->push(ch);
                break;
            case '}':
                return analysis(stack, 1);
                break;
            case ']':
                return analysis(stack, 2);
                break;
            case ')':
                return analysis(stack, 3);
                break;
        }
    }
    delete stack;
    return std::make_pair(true, "True");
}

auto main () -> int {
   
   std::string expr("{()}[]");
   std::string line("\n\033[1;37m-------------------------------------------\033[0m\n");
   
   auto result = isBalancedParenthesis(expr);
   
   std::cout << line << "   Given the expression: " << expr << std::endl;
   std::cout << "   Are the parenthesis balanced? " << (result.first == 0 ? "\033[1;31mNo, they aren\'t.\033[0m\n" : "\033[1;34mYes, they are.\033[0m\n") << line << std::endl;
   std::cout << result.second << std::endl;

   return 0;
}