#include<memory>
#include<iostream>

struct Incognito {
    int variable;

    Incognito (int var = 0) noexcept : variable(var) { }
    friend std::ostream& operator<<(std::ostream& os, const Incognito& v) {
        return os << "{ value = " << v.variable << " }";
    }
};

void printPtr(Incognito a, Incognito b){
    std::cout << " a = "<< a <<"\n b = " << b << std::endl;
}

void showPtr(std::unique_ptr<int> a, std::unique_ptr<int> b){
    std::cout << " a = "<< *a <<"\n b = " << *b << std::endl;
}

int main(int argc, char** argv){
   int x{7};
   int y{9};
    
  showPtr(std::make_unique<int>(x), std::make_unique<int>(y)); 

  std::unique_ptr<Incognito> v1 = std::make_unique<Incognito>(11);
  std::unique_ptr<Incognito> v2 = std::make_unique<Incognito>(13);
  
  printPtr(*v1, *v2);
    
 return 0;
}
