#include <iostream>
#include "insertSort.h"

algorithms::InsertSort::InsertSort(int* array)
 : elems(array) {}


int* algorithms::InsertSort::start(){
    size_t length = sizeof(elems) / sizeof(elems[0]);
    for(iter = 0; iter < length; iter++){
        thisElem = iter;
        prevElem = thisElem - 1;
        temp = elems[thisElem];
        while(thisElem > 0 && elems[prevElem] > temp){
            elems[thisElem] = elems[prevElem];
            thisElem--;
            prevElem = thisElem - 1;
        }
        elems[thisElem] = temp;
    }
    return elems;
}
