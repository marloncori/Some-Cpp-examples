
#include <iostream>
#include <vector>

bool equals_zero(unsigned int& num){
    return (num == 0);
}
unsigned int catalan(unsigned int n, std::vector<unsigned int>& table){
    if(equals_zero(n)){
        return 1;
    }
    for(unsigned int i = 0; i<n; i++){
        if(!table[i]){
            table[i] = catalan(i, table);
        }
        if(!table[n-1-i]){
            table[n-1-i] = catalan(n-1-i, table);
        }
        table[n] += table[i] * table[n-1-i];
    }
   return table[n];
}

int main() {
    std::vector<unsigned int> numbers{{2, 1, 3, 4, 5, 7, 9, 10}};
    
    auto res = catalan(numbers.size(), numbers);

    std::cout << "\n\033[1;34m catalan(nums.size(), nums) = " << res << "\n\033[0m" <<std::endl;
    
  return 0;
}