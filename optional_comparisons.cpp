#include <iostream>
#include <optional>
#include <string>

int main(){
  std::optional<int> maybeEmpty;
  std::optional<int> maybeTwo(2);
  std::optional<int> maybeTen(10);

  std::cout <<  << std::boolalpha;
  std::cout << (maybeTen > maybeTwo) << std::endl;
  std::cout << (maybeTen < maybeTwo) << std::endl;

  std::cout << (maybeEmpty < maybeTwo) << std::endl;
  std::cout << (maybeEmpty == std::nullopt) << std::endl;
  std::cout << (maybeTen == 10) << "\n";

 return 0;
}