#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

class MergeSort {
    private:
        std::vector<int>& data;
        size_t size;
        void merge(std::vector<int>& data, std::vector<int>& tempArr, 
             int lowerIndex, int middleIndex, int upperIndex);
        void sort(std::vector<int>& data, std::vector<int>& tempArr, 
             int lowerIndex, int upperIndex);

    public:
        MergeSort(std::vector<int>& data);
        void apply();
        void show(int mode);
};

#endif // merge_sort.h