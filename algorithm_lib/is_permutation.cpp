#include <iostream>
#include <vector>
#include <algorithm>

auto ignore_case(char& a, char& b) -> bool {
   return (std::tolower(a) == std::tolower(b));
}

auto show_res(bool& result){
    if(!result){
        std::cout << "\033[1;36m  --> Both vector doesn't contain the same elements.\033[0m\n" << std::endl;
    } 
    else {
        std::cout << "\033[1;31m  >>> Both vector DO contain the same elements. <<< \033[0m\n" << std::endl;
    }
}

auto show_vector(std::vector<char>& arr, std::vector<char>::iterator& it, const char* c){
    std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
    std::cout << "\033[1;" << c << "m" << line << "  Here you are the vector members: \n  Numbers = {";
    for(it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "}." << "\033[1;" << c << "m" << line << std::endl;
}


auto main() -> int {
   std::vector<char> v1 {{'A', 'B', 'C', 'D', 'E'}};
   std::vector<char> v2 {{'a', 'b', 'c', 'd', 'e'}};
   
   std::vector<char>::iterator itr;
   const char *c1 = "36", *c2 = "33";
   
   show_vector(v1, itr, c1);
   show_vector(v2, itr, c2);

   auto result = std::is_permutation(
       v1.begin(), v1.end(), v2.begin());

   show_res(result);

   result = std::is_permutation(
       v1.begin(), v1.end(), v2.begin(), ignore_case);
   
   show_res(result);

   
  return 0;
}