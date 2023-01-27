#include "number.h"
#include <stdio.h>

int setValue(num_t* num, long value)
{
  num->val = value;
  return !num ? -1 : 0;
}

void isOdd(num_t* num)
{
  if((num->val % 2) != 0)
  {
    printf("  --> The number %ld is odd!\n", num->val);
  }
  else 
  {
    isEven(num);
  }
}

void isEven(num_t* num)
{
 if((num->val % 2) == 0)
  {
    printf("  --> The number %ld is even!\n", num->val);
  }
  else 
  {
    isOdd(num);
  }
}

long factorial(long num)
{
 return num > 1 
        ? (num * factorial (num - 1))
        : 1;
}

void show_data(long num)
{
   printf(" ==>>> This number\'s factorial  equals: %ld.\n", num);
}
