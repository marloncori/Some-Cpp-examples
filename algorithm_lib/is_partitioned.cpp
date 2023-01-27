#include <iostream>
#include <vector>
#include <algorithm>

auto is_even(int n) -> bool {
   return (n % 2 == 0);
}

auto show_res(bool& result){
    if(result){
        std::cout << "\033[1;36m  --> Vector of values is partitioned!\033[0m\n" << std::endl;
    } 
    else {
        std::cout << "\033[1;31m  >>> Vector is NOT partitioned at all. <<< \033[0m\n" << std::endl;
    }
}

auto show_vector(std::vector<int>& arr, std::vector<int>::iterator& it, const char* c){
    std::string line("\n :::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
    std::cout << "\033[1;" << c << "m" << line << "  Here you are the vector members: \n  Numbers = {";
    for(it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "}." << "\033[1;" << c << "m" << line << std::endl;
}


auto main() -> int {
   std::vector<int> vec{{4, 2, 5, 3, 1, 2, 7, 10, 9, 17}};
   
   std::vector<int>::iterator itr;
   const char* c1 = "36", *c2 = "33";
   show_vector(vec, itr, c1);

   auto result = std::is_partitioned(vec.begin(), vec.end(), is_even);
   show_res(result);

   std::partition(vec.begin(), vec.end(), is_even);
   result = std::is_partitioned(vec.begin(), vec.end(), is_even);
 
   show_res(result);
   show_vector(vec, itr, c2);

   
  return 0;
}