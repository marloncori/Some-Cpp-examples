#include <iostream>
#include <utility>

std::pair<int, int> getUserInput();
void selectionSort(int size, int arr[]);
void showResult(int size, int array[]);

int main(){

   auto collection = getUserInput();
   selectionSort(collection.first, collection.second);
   showResult(collection.first, collection.second);

   return 0;
}

std::pair<int, int> getUserInput(){
   int arr[20], total;

   std::cout << "\n Enter the number of elements for the array\n";
   std::cout << "  Total: ";
   std::cin >> total;

   std::cout << "\n Now provide the numbers\n";
   for(int i=0; i<total; ++i){
       std::cout << "\t >> " << (i+1);
       std::cin >> arr[i];
   }
  return std::make_pair(total, arr[20]);
}

void selectionSort(int size, int arr[]){
    int pos, swap;

    for(int i=0; i<size-1; i++){
          pos = i;
       for(int j = i+1; j<size; j++){
             if(arr[pos] > arr[j]){
                 pos = j;
             }  
       }
        if(pos != i){
           swap = arr[i];
           arr[i]= arr[pos];
           arr[pos] = swap; 
        }
    }
}

void showResult(int size, int array[]){
    std::cout << "\n\tSorted Array: " << std::endl;
 
    for(int i=0; i<size; i++){
      printf(" -->> %d ", array[i]);
    }
}