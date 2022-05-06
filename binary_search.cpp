#include <iostream>

int iterativeBinarySearch(int array[], int x, int low, int high) {  
	// Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int recursiveBinarySearch(int array[], int x, int low, int high) {  
  if (high >= low) {
     int mid = low + (high - low) / 2;

     // If found at mid, then return it
     if (array[mid] == x)
         return mid;

     // Search the left half
     if (array[mid] > x)
         return recursiveBinarySearch(array, x, low, mid-1);

     // Search the right half
     return recursiveBinarySearch(array, x, mid + 1, high);
   }
  return -1;
}


int main(void) {
 
  int array[] = {32, 43, 51, 67, 78, 84, 95};
  
  int query = 67;
  int beginning = 0;

  int size = sizeof(array) / sizeof(array[0]);
  int end = size - 1;
  int result = iterativeBinarySearch(array, query, beginning, end);
 
  if (result < 0)
     std::cout << "\n\t Element not found" << std::endl;
  else
     std::cout << "\n\t Element " << query << " is found at index " << result << std::endl;

  query = 95;
  result = recursiveBinarySearch(array, query, beginning, end);
 
  if (result < 0)
     std::cout << "\n\t Element not found" << std::endl;
  else
     std::cout << "\n\t Element " << query << " is found at index " << result << std::endl;

 return 0;
}
