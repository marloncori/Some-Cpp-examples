#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

class LinkedListStack {
    private:
        struct Node {
            int data = 0;
            Node *next;
            Node(int val, Node* n);
        };
        Node* head;
        int stackSize;
    public:
        LinkedListStack();
        ~LinkedListStack();
        virtual auto getSize() -> int;
        virtual auto isEmpty() -> bool;
        virtual auto peek() -> int;
        virtual auto push(int value) -> void;
        virtual auto pop() -> int;
        virtual auto show() -> void;
};

LinkedListStack::LinkedListStack(){
    int stackSize = 0;
    head = nullptr;
}

LinkedListStack::~LinkedListStack(){
    delete this;
}

LinkedListStack::Node::Node(int val, Node* n){
    data = val;
    next = n;
}

auto LinkedListStack::getSize() -> int {
    return stackSize;
}

auto LinkedListStack::isEmpty() -> bool {
    return (stackSize == 0);
}

auto LinkedListStack::peek() -> int {
    if(isEmpty()){
        throw std::system_error(errno,
           std::system_category(), "\033[1;31m\n\t[LinkedListStackEmptyException] The Stack is empty!\033[0m\n");
    }
    return head->data;
}

auto LinkedListStack::push(int value) -> void {
    head = new Node(value, head);
    stackSize++;
}

auto LinkedListStack::pop() -> int {
    if(isEmpty()){
        throw std::system_error(errno,
           std::system_category(), "\033[1;31m\n\t[LinkedListStackEmptyException] The Stack is empty! \n\t\tThere is nothing to be showed!\033[0m\n");
    }
    int data = head->data;
    Node* oldNode = head;
    
    head = head->next;
    delete oldNode;
    stackSize--;
    
    return data;
}


auto LinkedListStack::show() -> void {
    std::string line("\n\033[1;32m:::::::::::::::::::::::::::::::::::::::::::::::::::::\n\033[0m");
    if(head == nullptr){
      std::cout << "\033[1;31m\n\t[LinkedListStackEmptyException] The Stack is empty! \n\t\tThere is nothing to be showed!\033[0m\n" << std::endl;
      exit(0);  
    }
    Node *temp = head;
    
    std::cout << line << "\033[1;33m This is the data of your LinkedListStack: \033[0m" << std::endl;
    while(temp != nullptr){
        std::cout << "\033[1;37m" << temp->data << "\033[0m \033[1;36m<<==\033[0m ";
        temp = temp->next;
    }
    std::cout << line << std::endl;
}

#endif