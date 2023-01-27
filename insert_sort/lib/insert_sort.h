#ifndef INSERT_SORT_H_
#define INSERT_SORT_H_

#include <vector>

class InsertSort {
    private:
        std::vector<int>& arr;
        size_t size;
        bool isGreater(int first, int second);
    public:
        InsertSort(std::vector<int>& data);
        void start();
        void show(int mode);
};

#endif // insert_sort.h