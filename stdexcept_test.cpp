#include <iostream>
#include <cstdlib>
#include <system_error>
#include <errno.h>

int test_function1(const int&);
void test_function2 (const float&);

int main(){

    int val1 = NULL;
    float val2 {9.99};

    test_function1(val1);
    test_function2(val2);
}

int test_function1 (const int& number){
    if(number == NULL){
        throw std::system_error(errno,
                std::system_category(), " ERROR! The NUMBER variable cannot be null!");
        //return EXIT_FAILURE;
    }

    std::cout << "\n\t You have entered the following value: " << number << std::endl;
    return EXIT_SUCCESS;
}

void test_function2 (const float& number){
    if(number == NULL){
        throw std::invalid_argument(" ERROR! The NUMBER variable cannot be null!");
        //std::exit(EXIT_FAILURE);
    }

       std::cout << "\n\t And now you have typed the following value: " << number << std::endl;
       std::exit(EXIT_SUCCESS);
}