#include <iostream>
#include <array>

#include "jumpSearch.h"

int main(){
  std::array<int, 8> numbers = {25, 45, 78, 96, 32, 14, 9, 51};
  int query = 9;

  int size = 8;
  JumpSearch* searcher = new JumpSearch(
       numbers, query, size
  );
  
  int index = searcher->start();
     searcher->showResult(index);
  
  return EXIT_SUCCESS;
}