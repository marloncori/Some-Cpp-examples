#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
// stack implementation using an array
class ArrayStack {
    private:
        static const int MIN_CAP{10};
        int* data;
        int stackTop{-1};
        int capacity;

    public:
        ArrayStack();
        ArrayStack(int maxCapacity);
        ~ArrayStack();
        virtual auto size() -> int;
        virtual auto isEmpty() -> bool;
        virtual auto top() -> int;
        virtual auto push(int value) -> void;
        virtual auto pushVariable(int value) -> void;
        virtual auto pop() -> int;
        virtual auto popVariable() -> int;
        virtual auto print() -> void;
};

ArrayStack::ArrayStack() : ArrayStack(MIN_CAP) {    
};

ArrayStack::ArrayStack(int maxCapacity){
    data = new int[maxCapacity];
    capacity = maxCapacity;
}

ArrayStack::~ArrayStack(){
    delete this;
}

auto ArrayStack::isEmpty() -> bool {
    return (stackTop == -1);
}

auto ArrayStack::size() -> int {
    return (stackTop + 1);
}

auto ArrayStack::print() -> void{
    std::cout << "\033[1;34mThis is the STACK data:\n  {\n";
    for(int i = stackTop; i > -1; i--){
        std::cout << "\033[0m\033[1;37m\t| " << data[i] << " |\033[0m" << std::endl;
    }
    std::cout << " }\n\033[0m" << std::endl;
}

auto ArrayStack::push(int value) -> void {
    if(size() == capacity){
        throw std::system_error(errno,
           std::system_category(), "\033[1;31m\t[StackOverflowException] Index out of bounds!\033[0m\n");
    }
    stackTop++;
    data[stackTop] = value;
}

auto ArrayStack::pushVariable(int value) -> void {
    if(size() == capacity){ 
        int* oldData = data;
        capacity = 2 * capacity;
        data = new int[capacity];
        for(int i=stackTop; i>-1; i--){
            data[i] = oldData[i];
        }
        delete[] oldData;
        std::cout << "   [INFO] Stack size has been doubled! " << std::endl;
    }
    stackTop++;
    data[stackTop] = value;
}

auto ArrayStack::pop() -> int {
    if(isEmpty()){
        throw std::system_error(errno,
            std::system_category(), "\033[1;31m\t[StackEmptyException] Stack is empty!!!\033[0m\n");
    }
    int topVal = data[stackTop];
    stackTop--;
    return topVal;
}

auto ArrayStack::popVariable() -> int {
    if(isEmpty()){
        throw std::system_error(errno,
            std::system_category(), "\033[1;31m\t[StackEmptyException] Stack is empty!!!\033[0m\n");
    }
    int topVal = data[stackTop];
    stackTop--;
    
    if(size() == capacity){
        int* oldData = data;
        capacity = capacity / 2;
        data = new int[capacity];
        for(int i=stackTop; i>-1; i--){
            data[i] = oldData[i];
        }
        delete[] oldData;
        std::cout << "   [INFO] Stack size has been RECUCED! " << std::endl;
    }
    return topVal;
}

auto ArrayStack::top() -> int {
    if(isEmpty()){
        throw std::system_error(errno,
           std::system_category(), "\033[1;31m\t[StackEmptyException] Stack is empty!!!\033[0m\n");
    }
    return data[stackTop];
}

#endif