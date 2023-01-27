#ifndef JUMP_SEARCH_H_
#define JUMP_SEARCH_H_

#include <array>

class JumpSearch {
    private:
       std::string errorMsg;
       std::array<int, 8> numbers;
       int query;
       int size;
    public:
       JumpSearch(std::array<int, 8> numbers, int query, int size);
       ~JumpSearch();
       void newQuery(int value);
       int start();
       void showResult(int index);
};

#endif // jumpSearch.h