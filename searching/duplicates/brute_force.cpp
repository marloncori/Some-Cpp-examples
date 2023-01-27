#include <iostream>
#include <vector>

void showRepeated(std::vector<int>& data){
    int count = 0;
    int size = data.size();
    std::cout << "\n\033[1;36m Repeating elements are:\033[0m";
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(data[i] == data[j]){
                std::cout << "\033[1;32m " << data[i] << "\033[0m";
                count++;
            }
        }
    }
    if(count == 0){
       std::cout << "\n\t\033[1;32m[INFO]\033[0m \033[1;34mNo repeated elements have been found\033[0m\n" << std::endl;
    }
}

int main(){
    
    std::vector<int> arr{{10, 23, 47, 56, 47, 23, 79, 2, 100, 2}};
    showRepeated(arr);

    std::vector<int> arr2{{10, 56, 47, 79, 2}};
    showRepeated(arr2);

  return 0;
}