#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "number.h"

long value1 = 7;
long value2 = 12;

int main(void)
{
  num_t* num_A;
  if(setValue(num_A, value1) != 0)
  {
    printf("  An error has happened: %d\n", errno);
    exit(0);
  }
 
  num_t* num_B;
  if(setValue(num_B, value2) != 0)
  {
    printf("  An error has happened: %d\n", errno);
    exit(0);
  }
  
  isOdd(num_A);
  isEven(num_B);

  long fac_A = factorial(num_A->val);
  long fac_B = factorial(num_A->val);

  long values[2] = {fac_A, fac_B};
  for(int i = 0; i < 2; i++)
  {
    show_data(values[i]);
  }

 return 0;
}

