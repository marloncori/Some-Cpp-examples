
#include <iostream>
#include <vector>

void countShowRepeated(std::vector<int>& data){
    int counter = 0;
    int size = data.size();
    std::vector<int>count(size);
    for(int i=0; i<size; i++){
        count[i] = 0;
    }
    std::cout << "\n\033[1;36m Repeating elements are:\033[0m";
    for(int i=0; i<size; i++){
        if(count[data[i]] == 1){
            std::cout << "\033[1;32m " << data[i] << "\033[0m";
            counter++;
        }
        else {
            count[data[i]]++;
        }
    }
    if(counter == 0){
       std::cout << "\n\t\033[1;32m[INFO]\033[0m \033[1;34mNo repeated elements have been found\033[0m\n" << std::endl;
    }
}

int main(){
    
    std::vector<int> arr{{10, 23, 56, 47, 23, 79, 100, 79, 100, 2}};
    countShowRepeated(arr);

    std::vector<int> arr2{{10, 56, 47, 79, 2}};
    countShowRepeated(arr2);

  return 0;
}
