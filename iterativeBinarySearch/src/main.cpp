#include <iostream>

#include "iterativeBinarySearch.h"

int main()
{
    int numbers[7] = {12, 34, 56, 78, 7, 90, 32};
    int first = 0;
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int last = first - 1;

    iterativeBinarySearch* iterativeSearcher = 
           new iterativeBinarySearch(first, last);

   iterativeSearcher->setQuery(numbers[2]);
    
    int foundElement = iterativeSearcher->start(
                        numbers, 
                          iterativeSearcher->getBegin(),
                            iterativeSearcher->getEnd(),
                             iterativeSearcher->getQuery());

    iterativeSearcher->setResult(foundElement);

    if(iterativeSearcher->showResult(
         iterativeSearcher->getResult()) != 0)
    {
       std::cerr << iterativeSearcher->ErrorMsg() << std::endl;
       exit(1);
    }

  return EXIT_SUCCESS;
}