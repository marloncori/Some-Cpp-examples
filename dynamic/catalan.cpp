
#include <iostream>

bool equals_zero(unsigned int& num){
    return (num == 0);
}
unsigned int catalan(unsigned int n){
    if(equals_zero(n)){
        return 1;
    }
    unsigned int sum = 0;
    for(unsigned int i = 0; i<n/2; i++){
        sum += catalan(i) * catalan(n-1-i);
    }
    sum *= 2;
    if(n % 2){
      unsigned int c = catalan(n/2);
      sum += c*c;
    }
   return sum;
}

int main() {   
    
  for(int i=0; i<20; i++){
     auto res = catalan(i);
     std::cout << "\n" << (i+1) << ") \033[1;36m catalan2(number) = " << res << "\n\033[0m" <<std::endl;
  }

  return 0;
}