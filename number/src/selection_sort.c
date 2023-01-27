#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second)
{
  int tmp = *first;
  *first = *second;
  *second = tmp;
}

int compare(int first, int second)
{
  return first < second ? 0 : -1;
}

void selectSort(int array[], int limit)
{
  for(int i=0; i<limit-1; ++i)
  {
     int index = i;
     for(int j= i+1; j<limit; ++j)
     {
        if(compare(array[j], array[index]) == 0)
        {
            index = j;
        }
     }
     swap(&array[index], &array[i]);
  }
}

void showArray(int my_arr[], int length)
{
  printf(" These are the array elements: [");
  for(int i=0; i<length; ++i)
  {
 
     printf(" %d ", my_arr[i]);
  }
  printf("]\n");
}
