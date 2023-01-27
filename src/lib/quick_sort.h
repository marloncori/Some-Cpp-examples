#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include <vector>

namespace arrange {
 class QuickSort {
     private:
         int size;
         int pivot;
         int begin;
         int end;
         int count;
         int partition(int[], int, int);

     public:
         QuickSort(int);
         ~QuickSort();
         void quickSort(int[], int, int);
         void showResult(int[]);
 };
}

#endif