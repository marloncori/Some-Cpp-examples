#ifndef ITERATIVE_BINARY_SEARCH_H
#define ITERATIVE_BINARY_SEARCH_H

class iterativeBinarySearch {
     private:
        int begin;
        int end;
        int query;
        int result;
        std::string errorMsg;

     public:
        iterativeBinarySearch(int being, int end);
        ~iterativeBinarySearch();
        int getBegin();
        int getEnd();
        void setQuery(int number);
        int getQuery();
        void setResult(int value);
        int getResult();
        std::string ErrorMsg();
        int start(int array[], int begin, int end, int query);
        int showResult(int index);
};

#endif // iterativeBinarySearch.h