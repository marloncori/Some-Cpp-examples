#include <iostream>
#include <errno.h>
#include <system_error>

#include "jumpSearch.h"
 
JumpSearch::JumpSearch(std::array<int, 8> numbers, int query, int size) 
:  numbers(numbers), query(query), size(size) 
{
   errorMsg = "  ERROR: Searched element is not present in Array!"; 
   std::cout << "\n  The jump search is starting..." << std::endl;
}

void JumpSearch::newQuery(int value)
{
    query = value;
}

int JumpSearch::start()
{
  int step = std::sqrt(size);
  int prev = 0;
   while(numbers[std::min(step, size)-1] < query){
       prev = step;
       step += std::sqrt(size);   
   
       if(prev >= size){
         return -1;
       }
   }
    
   while(numbers[prev] < query){
	prev++;
        if(prev == std::min(step, size)){
           return -1;
        }    
   }

   if(numbers[prev] == query){
       return prev;
   }

  return -1;
}

void JumpSearch::showResult(int index)
{
  if(index < 0 ){
    throw std::system_error(errno,
            std::system_category(), errorMsg);
  }
   
   std::string line("\n ================================================\n"); 
   std::cout << line << "  You\'ve looked for the number " << query 
    << "\n   and it has been foud at index # " << index << line << std::endl;
}
