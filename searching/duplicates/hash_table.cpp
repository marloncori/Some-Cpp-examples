
#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>

void showRepeated(std::vector<int>& data){

    int count = 0;
    int size = data.size();
    std::unordered_set<int> hs;
    std::cout << "\n\033[1;36m Repeating elements are:\033[0m";
    for(int i=0; i<size; i++){
        if(std::find(hs.begin(), hs.end() data[i]) != hs.end()){
            std::cout << "\033[1;32m " << data[i] << "\033[0m";
            count++;
        }
        else {
            hs.insert(data[i]);
        }
    }
    if(count == 0){
       std::cout << "\033[1;32m[INFO]\033[0m\033[1;36mNo repeated elements have been found\033[0m\n" << std::endl;
    }
}

int main(){
    
    std::vector<int> arr{{10, 23, 56, 47, 23, 79, 100, 2}};
    showRepeated(arr);

    std::vector<int> arr2{{10, 56, 47, 79, 2}};
    showRepeated(arr2);

  return 0;
}
