#ifndef QUICK_SORT_H
#define QUICK_SORT_H

class QuickSort {
    private:
        std::vector<int>& data;
        int size;
        void swap(std::vector<int>& data, int first, int second);
        void partition(std::vector<int>& data, int lower, int upper);

    public:
        QuickSort(std::vector<int>& data);
        void apply();
        void show(int mode);
};

#endif // quickSort.h