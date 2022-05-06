#include <iostream>
#include "binarySearch.h"

constexpr int BOTH_ARE_EQUAL   = 0;
constexpr int END_IS_BIGGER    = 1;
constexpr int QUERY_IS_SMALLER = 2;

algorithm::BinarySearch::BinarySearch(int begin, int end, int query) : 
  _begin(begin), _end(end), _query(query)
{
    std::cout << "\n  ::::::: The binary search is starting in some seconds... ::::::" << std::endl;
}

int algorithm::BinarySearch::compare(int first, int second){
    return second >= first ? END_IS_BIGGER 
            : second < first ? QUERY_IS_SMALLER 
            : first == second ? BOTH_ARE_EQUAL : -1;
}

int algorithm::BinarySearch::Begin()
{
   return _begin;
}

int algorithm::BinarySearch::End()
{
   return _end;
}

int algorithm::BinarySearch::Query()
{
   return _query;
}

void algorithm::BinarySearch::setResult(int value)
{
   _result = value;
}

int algorithm::BinarySearch::getResult()
{
    return _result;
}

int algorithm::BinarySearch::startSearch(int collection[10], int begin, int end, int query){
    if(compare(begin, end) == END_IS_BIGGER) 
    {
        int middle = begin+(end-begin)/2;

        if(compare(collection[middle], query) == BOTH_ARE_EQUAL)
        {
            return middle;
        } 
        
        if(compare(collection[middle], query) == QUERY_IS_SMALLER)
        {
            return startSearch(collection, begin, middle-1, query);
        }
       return startSearch(collection, middle+1, end, query);
    }
   return -1;
}

int algorithm::BinarySearch::showResult(int index) const 
{
    std::string line("\n\t----------------------------------------------\n");
    if(index == NULL || index < 0)
    {
        return -1;
    }

    std::cout << line << std::endl;
    std::cout << " \t  ---> You have tried to find: \'" << _query << "\'." << std::endl;
    std::cout << "\t   >>> The searched element has \n\t    been found at the index # " << index << std::endl;
    std::cout << line << std::endl;
  
   return 0;
}
