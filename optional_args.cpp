#include <optional>
#include <iostream>
#include <string>

std::optional<int> parseInt(char* arg){
   try{
      return { std::stoi(std::string(arg)) };
   } catch(...) {
      std::cout << " cannot convert \'" << arg << "\' to int!\n";
   }

  return { };
}

int main(int argc, char* argv[]){

   if(argc >= 3){
       auto oFirst = parseInt(argv[1]);
       auto oSecond = parseInt(argv[2]);

       if(oFirst && oSecond) {
           std::cout << " Sum of " << *oFirst << " and " << *oSecond;
	   std::cout << " is : " << *oFirst + *oSecond << "\n";
       }
   }

 return 0;
}