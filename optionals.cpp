// Optionals in C++
#include <iostream>
#include <optional>

struct Point {
   Point(int a, int b) : x(a), y(b) { }
   int x;
   int y;
};

int main(){
  //empty 
  std::optional<int> maybeEmpty;
  std::optional<float> maybeFloat = std::nullopt;

  std::cout << maybeEmpty.value() << std::endl;
  std::cout << maybeFloat.value_or(30) << std::endl;

  //direct
  std::optional<int> maybeNumber(10);
  std::optional<int> maybeDeduced(20); // deduction guides 

  std::cout << *maybeNumber << std::endl;
  std::cout << *maybeDeduced << std::endl;

  //make optional
  auto maybeDouble = std::make_optional(3.0);
  auto maybeComplex = std::make_optional<std::complex<double>>(3.0, 4.0); 

  std::cout << maybeDouble.value() << std::endl;
  std::cout << maybeComplex.value_or(55) << std::endl;

  //in place
  std::optional<std::complex<double>> optionalInteger{std::in_place, 5.0, 7.0};

  //this will call vector with direct init of {1, 2, 3}
  std::optional<std::vector<int>> maybeVector(std::in_place, {1, 2, 3});

  std::cout << *optionalInteger << std::endl;
  std::cout << *maybeVector << std::endl;

  // copy, assign
  auto maybeCopyInt = maybeNumber;

  std::optional<Point> maybePoint{std::in_place, 0, 1};
  // vs
  std::optional<Point> maybePoint{{0, 1}};

  std::cout << maybeCopyInt.value() << std::endl;
  std::cout << maybePoint.value_or(34) << std::endl;

 return 0;
}