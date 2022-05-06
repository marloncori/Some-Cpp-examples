#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

namespace algorithm {
    class BinarySearch {
        private:
           int _begin;
           int _end;
           int _query;
           int _result;

        public:
          BinarySearch(int begin, int end, int query);
          ~BinarySearch();
          int compare(int first, int second);
          int Begin();
          int End();
          int Query();
          void setResult(int value);
          int getResult();
          int startSearch(int collection[10], int begin, int end, int query);
          int showResult(int index) const;
    };
}

#endif // binarySearch.h