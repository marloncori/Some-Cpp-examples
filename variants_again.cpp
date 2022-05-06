#include <string>
#include <iostream>
#include <variant>

struct SampleVisitor {
    void operator()(int i) const {
       std::cout << " int: " << i << "\n";
    }

   void operator()(float f) const {
       std::cout << " float: " << f << "\n";
    }

   void operator()(const std::string& s) const {
       std::cout << " string: " << i << "\n";
    }
};

int main(){
  std::variant<int, float, std::string> intFloatString;
  
  // try/catch and bad_variant_access
   try {
      auto f = std::get<float>(intFloatString);
      std::cout << " float: " << f << "\n";
   } catch(std::bad_variant_access&) {
      std::cout << " variant does not hold any value now." << std::endl;
   } 

   //visit
   std::visit(SampleVisitor{}, intFloatString);
   intFloatString = 11;
   std::visit(SampleVisitor{}, intFloatString);
   intFloatString = 22.0f;
   std::visit(SampleVisitor{}, intFloatString);
   intFloatString = " this a variant variable.";
   std::visit(SampleVisitor{}, intFloatString);

 return 0;
}