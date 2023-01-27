#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
   vector<string> v1 = {"One", "Two", "Three"};
   vector<string> v2 = {"one", "two", "three"};
   bool result;

   result = lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());

   if (result == true)
      cout << "v1 is less than v2." << endl;

   v1[0] = "two";

   result = lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());

   if (result == false)
      cout << "v1 is not less than v2." << endl;

   return 0;
}