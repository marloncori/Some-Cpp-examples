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
  static_assert(std::variant_size_v<decltype(intFloatString)> == 3);

  // default initialized to the first alternative, should be 0
  std::visit(SampleVisitor{}, intFloatString);

  // index will the currently used type
  std::cout << " index = " << intFloatString.index() << std::endl;
  intFloatString = 100.0f;

  std::cout << " index = " << intFloatString.index() << std::endl;
  intFloatString = " Variant library is similar to Rust\'s Result";

  // try with get_if
  if(const auto intPtr(std::get_if<int>(&intFloatString)); intPtr) {  
       std::cout << " int number = " << *intPtr << std::endl;
  }
  else if (const auto floatPtr(std::get_if<float>(&intFloatString)); floatPtr){
        std::cout << " float!" << *floatPtr << "\n"; 
  }

  if(std::holds_alternative<int>(intFloatString)){
        std::cout << " The Variant holds an integer!" << std::endl;
  } else if(std::holds_alternative<float>(intFloatString)){
        std::cout << " The Variant holds a Float!" << std::endl;
  } else if(std::holds_alternative<float>(intFloatString)){
	std::cout << " The Variant holds a Stringt!" << std::endl;
  }
 
 return 0;
}