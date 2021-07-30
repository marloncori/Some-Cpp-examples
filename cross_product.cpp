#include <iostream>
#define n 3

using namespace std;

void crossProduct(int v_A[], int v_B[], int c_P[]) {
   c_P[0] = v_A[1] * v_B[2] - v_A[2] * v_B[1];
   c_P[1] = -(v_A[0] * v_B[2] - v_A[2] * v_B[0]);
   c_P[2] = v_A[0] * v_B[1] - v_A[1] * v_B[0];
}

int main() {

   system("color 1e");
   int v_A[] = { 7, 6, 4 };
   int v_B[] = { 2, 1, 3 };
   int c_P[n];

   cout << "\n\n\tCross product:";
   crossProduct(v_A, v_B, c_P);

   for (int i = 0; i < n; i++)
      cout << c_P[i] << " ";

   system("pause");
   return 0;
}
