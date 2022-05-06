#include <iostream>
#include <optional>


int main(){
  std::optional<std::string> maybe_create_hello();
  
  if(auto ostr = maybe_create_hello(); ostr){
    std::cout << " ostring: " << *ostr << std::endl;
  }
   else {
    std::cout << " ostring is null\n!";  
  }

  return 0;
}

