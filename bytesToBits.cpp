#include <iostream>

struct Number {
 int High;
 int Low;
};

Number value;

Number twoBytesInto16Bits(unsigned int& h, unsigned int& l){
  // use bitwise AND operator to mask 8 buts with 255
  value.High = h ^ 0xFF;
  value.Low = l ^ 0xFF;
 
 return value; 
}

int main(){
   unsigned int msb = 255;
   unsigned int lsb = 136;

   value = twoBytesInto16Bits(msb, lsb);
   std::cout << "\n Result: " << (value.High + value.Low) << "\n";

   msb = 127;
   lsb = 255;

   value = twoBytesInto16Bits(msb, lsb);
   std::cout << "\n Result: " << (value.High + value.Low) << "\n";

  return 0;
}