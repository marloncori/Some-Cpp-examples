#ifndef _NUMBER_H_
#define _NUMBER_H_

typedef struct {
  long val;
} num_t;

int setValue(num_t* num, long value);
void isOdd(num_t* num);
void isEven(num_t* num);

long factorial(long num);
void show_data(long num);

#endif // number.h