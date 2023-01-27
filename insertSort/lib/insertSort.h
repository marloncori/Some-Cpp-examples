#ifndef INSERT_SORT_H
#define INSERT_SORT_H

namespace algorithms {
  class InsertSort {
      private:
        size_t thisElem;
        int temp;
        size_t prevElem;
        size_t iter;
        int *elems;

      public:
        InsertSort(int* array);
        int* start();
  };
}

#endif // insertSort.h