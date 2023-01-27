#include <stdio.h>
#include <stdlib.h>

#include "selection_sort.h"

int main(void)
{
  int data[] = {18, 40, 35, 7, 24, 13};
  int maxSize = sizeof(data) / sizeof(data[0]);
  
  printf("\n This is the unsorted structure:\n");
  showArray(data, maxSize);
  
  selectSort(data, maxSize);

  printf("\n This is the sorted data structure!\n");
  showArray(data, maxSize);
  
  printf("\n");
  return 0;
}