#include <iostream>
#include <memory>
#include <vector>
#include "insert_sort.h"

int main(){
    std::vector<int> nums{34, 78, 12, 100, 57, 67, 5};

    std::unique_ptr<InsertSort> insertSort = std::make_unique<InsertSort>(InsertSort(nums));

    int mode = 0;
    insertSort->show(mode);
    insertSort->start();
    
    mode = 1;
    insertSort->show(mode);
        
 
  return 0;
}