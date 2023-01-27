// Optionals in C++
#include <iostream>
#include <optional>

int main(){
  std::optional<int> oint = 10;
  std::cout << " oint: " << *oint << '\n' << std::endl;

  std::optional<std::string> oStr("optionals in C++");
  try {

  } catch(const std::bad_optional_access& err) {
     std::cout << err.what() << "\n" << std::endl;
  }

  std::optional<double> maybeDouble; //empty
  std::cout << " optional double: " << maybeDouble.value_or(33) << std::endl;

 return 0;
}