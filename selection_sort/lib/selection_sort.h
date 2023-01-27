#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

class SelectionSort {
    private:
        std::vector<int>& arr;
        int size;
        int i;
        int j;
        int temp;
    public:
        SelectionSort(std::vector<int>& data);
        void apply();
        void start();
        void show(int mode);
};

#endif // selection_sort.h