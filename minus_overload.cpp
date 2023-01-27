#include<iostream>
#include<memory>

class Test {
    private:
        int x;
        int y;
        int z;

    public:
        void getdata(const int& a, const int& b, const int& c);
        friend void operator-(Test& tester);
        friend std::ostream& operator<<(std::ostream& os, Test& tester);
};

void Test::getdata(const int& a, const int& b, const int& c) {
    x = a;
     y = b;
        z = c;
}

void operator-(Test& tester) {
   tester.x = -tester.x;
    tester.y = -tester.y;
     tester.z = -tester.z;
    std::cout << " Class elements have been turned \n into signed numbers now!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, Test& tester){
    os << "  Value of x --> " << tester.x << "\n "
        << "  Value of y --> " <<  tester.y << "\n   "
          << "  Value of z --> " << tester.z << "\n";
    return os;
}

int main() {

    std::unique_ptr<Test> tester1 = std::make_unique<Test>(Test());
    tester1->getdata(15,-25,30);

    std::cout << " For a positive tester1: \n\t" << *tester1 << std::endl;
    // apply overloaded operator
    -*tester1;
    std::cout << " For a negative tester1: \n\t" << *tester1 << std::endl;

    -*tester1;
    std::cout << " For a negative/positive tester1: \n\t" << *tester1 << std::endl;
  
   return 0;
}