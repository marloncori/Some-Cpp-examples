#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

namespace algorithm {
    class BinarySearch { 
        private:
            int begin;
            int end;
            int element;
            int index;

        public:
            BinarySearch();
            ~BinarySearch();
            int start(int[], int, int, int);
            void show(int);

    };
}

#endif