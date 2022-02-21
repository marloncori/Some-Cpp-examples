#include<memory>
#include<iostream>
#include<iomanip>

class Person{
    private:
        std::string name;
        std::string surname;
    
    public:
        Person(std::string_view nm, std::string_view sn) : 
            name(nm), surname(sn) {};
        ~Person() {};
        
        friend std::ostream& operator<<(std::ostream& os, const Person& p) {
            return os << "{ First name = " << std::setw(3) << p.name 
                    << "\n  Last name = " << std::setw(3) << p.surname << "}" ;
        }
};

int main(int argc, char** argv){
  
  std::unique_ptr<Person> person = std::make_unique<Person>("Marlon", "Couto");
  
  std::cout << *person << std::endl;
    
 return 0;
}
