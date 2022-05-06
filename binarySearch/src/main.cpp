#include <iostream>
#include <errno.h>
#include <system_error>

#include "binarySearch.h"

int main(){

    std::string errorMsg(" >>> Searched element is not present in the array!");
    
    int numbersArray[10] = {10, 40, 20, 50, 30, 90, 70, 80, 5, 110};
    int queryElement = 40;
    int firstIndex = 0;

    int length = sizeof(numbersArray) / sizeof(numbersArray[0]);
    int lastIndex = length - 1;
    
    algorithm::BinarySearch* searcher;
    searcher = new algorithm::BinarySearch(
        firstIndex, lastIndex, queryElement
    );

    searcher->setResult(searcher->startSearch(
            numbersArray, 
                searcher->Begin(),
                    searcher->End(),
                        searcher->Query()
        )
    );

    if(searcher->showResult(searcher->getResult()) != 0){
        throw std::system_error(errno,
           std::system_category(), errorMsg);
    }
    
    return 0;
}
