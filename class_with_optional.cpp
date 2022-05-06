#include <iostream>
#include <optional>
#include <string>

class Username {
   public:
      explicit UserName(const std::string& str) : _name(str){
         std::cout << " Username::UserName(\'";
         std::cout << _name << "\')\n";
      }
      ~UserName() {
         std::cout << " Username::UserName(\'";
         std::cout << _name << "\')\n";
      }

   private:
      std::string _name;
};

int main(){
  std::optional<UserName> maybeEmpty;

  //emplace
  maybeEmpty.emplace("Steve");
  std::cout << " Old optional name: " << maybeEmpty.value() << std::endl;

  // calls ~Steve and creates new Mark;
  maybeEmpty.emplace("Mark"); 
  std::cout << " New optional name: " << maybeEmpty.value_or("Marlon") << std::endl;

  maybeEmpty.reset();
  std::cout << " Resetted optional name: " << *maybeEmpty << std::endl;
 
  maybeEmpty.emplace("Fred");
  std::cout << " Resetted optional name: " << maybeEmpty.value() << std::endl;
 
  oEmpty = UserName("Joe");
  std::cout << " Resetted optional name: " << oEmpty << std::endl;
 
 return 0;
}