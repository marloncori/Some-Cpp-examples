#include <iostream>

#include "iterativeBinarySearch.h"

iterativeBinarySearch::iterativeBinarySearch(int being,
 int end) : begin(begin), end(end)
 {
     errorMsg = "\n\t WARNING! Searched element is not present in array!";

     std::cout << "\n\t The Binary Search is starting..." << std::endl;
 }

int iterativeBinarySearch::getBegin()
{
  return begin;
}

int iterativeBinarySearch::getEnd()
{
  return end;
}

void iterativeBinarySearch::setQuery(int number)
{
   std::cout << "\t   [QUERY: " << number << "]." << std::endl;
   query = number;
}

int iterativeBinarySearch::getQuery()
{
  return query;
}

void iterativeBinarySearch::setResult(int value)
{
   std::cout << "\t   (result: " << value << ")." << std::endl;
   result = value;
}

int iterativeBinarySearch::getResult()
{
   return result;
}

std::string iterativeBinarySearch::ErrorMsg()
{
   return errorMsg;
}

int iterativeBinarySearch::start(int array[], int begin, int end, int query)
{
    while(begin <= end)
    {
        int middle = begin + (end - begin) / 2;

        if(array[middle] == query)
        {
            std::cout << "\t   { m i d d l e  <--- " << middle << " }." << std::endl;
            return middle;
        }
     
        if(array[middle] < query)
        {
            begin = middle + 1;
        } else{
            end = middle - 1;
        }
     }
     
    return -1;
}

int iterativeBinarySearch::showResult(int index)
{
    std::string line("\n\t===================================\n");

    if(index == NULL || index < 0)
    {
        std::cout << "\t  OH NO!!!! :(  :(" << std::endl;
        return -1;
    }
 
    std::cout << line << std::endl;
    std::cout << "\t You tried to find: " << query << std::endl;
    std::cout << "\t >>> This is the result:\n\t Element found at index \'" 
       << index << "\'." << std::endl;
    std::cout << line << std::endl;

  return 0;
}