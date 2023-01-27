#include <iostream>
#include <memory>
#include <windows.h>
#include "binary_search.h"

int main() {

    int num_arr[] = { 2, 3, 4, 10, 20, 30 };
    int length = sizeof(num_arr) / sizeof(num_arr[0]);
    int left = 0, right = length - 1;

    std::unique_ptr<algorithm::BinarySearch> binarySearch =
        std::make_unique<algorithm::BinarySearch>();


    for(int i = 0; i < length; i++){
        binarySearch->show(
            binarySearch->start(num_arr, left, right, num_arr[i])
        );
        Sleep(1000);
    }
  return 0;
}