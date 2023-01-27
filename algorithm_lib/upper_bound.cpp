#include <algorithm> // for lower_bound, upper_bound and sort
#include <iostream>
#include <vector> // for vector
 
using namespace std;
 
int main() {
    int gfg[] = { 5, 8, 7, 7, 8, 5, 5, 8 };
 
    vector<int> v(gfg, gfg + 8); // 5 8 7 7 8 5 5 8
 
    sort(v.begin(), v.end()); // 5 5 5 7 7 8 8 8
 
    // Print vector
    std::cout << " --> Vector contains: {";
    for(auto& i : v){
        std::cout << " " << i << " ";
    }
    std::cout << "} \n" << std::endl;
  
    vector<int>::iterator lower, upper;
    lower = lower_bound(v.begin(), v.end(), 5);
    upper = upper_bound(v.begin(), v.end(), 5);
 
    cout << "\n  lower_bound for 5 at position "
         << (lower - v.begin() + 1) << "\n";
    cout << "\t upper_bound for 5 at position "
         << (upper - v.begin() + 1) << "\n";
 
    return 0;
}