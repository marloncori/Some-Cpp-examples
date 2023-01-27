#include <iostream>
#include <vector>
#include <limits>

typedef std::vector<unsigned int> vec;
typedef unsigned int uint;
void neatPrint(vec& v, const vec& len, uint max, int n){
    int penalty;
    for(int i=0; i<n; i++){
        penalty = max - len[i];
        v[i] = std::min(v[i], 
          (i-1 < 0 ? 0 : v[i-1] + (1 << penalty)));
        for(int j=i-1; j>=0; j--){
            penalty -= (len[j] + 1);
            if(penalty < 0){
                break;
            }
            v[i] = std::min(v[i], 
              (j-1 < 0 ? 0 : v[j-1] + (1 << penalty)));
        }
    }
}

void solveNeatPrint(const vec& len, uint max){
    int n = len.size();
    vec M(n, std::numeric_limits<uint>::max());
    neatPrint(M, len, max, n);
    std::cout << "\n\t {";
    for(int i=0; i<n; i++){
       std::cout << M[i] << " ";
    }
    std::cout << "}\n" << std::endl;
}

int main(){

    uint size = 10;
    vec nums{{2, 3, 4, 5, 6, 7, 9, 10, 11, 12}};
    solveNeatPrint(nums, size);

  return 0;
}