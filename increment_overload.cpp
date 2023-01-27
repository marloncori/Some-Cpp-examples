#include<iostream>
#include<memory>

class Count {
    private:
        int value;
        int previous;
        int next;
    public:
    //constructor to initialize count to 5
    Count(int v);
    //overload ++ when used as prefix
    void operator++();
    void display();
};

Count::Count(int v) : value(v) {}

void Count::operator++(){
    previous = value;
    ++value;
    next = value+1;
    std::cout << "\n Sensor reading counter incremented!" << std::endl;
}

void Count::display() {
    std::cout<< "Previous state: "<< previous << std::endl;
    std::cout<< "Current state: "<< value << std::endl;
    std::cout<< "Next state: "<< next << std::endl;
}

int main(){
    std::unique_ptr<Count> counter =
        std::make_unique<Count>(Count(10));
    //call the “void operator ++ ()” function
    ++*counter;
    counter->display();

 return 0;
}