//------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>

//------------------------------------------------------------------------
struct TwoBytes {
   unsigned int High;
   unsigned int Low;
};

TwoBytes twoBytes;

//------------------------------------------------------------------------
TwoBytes split16BitsInto2Bytes(unsigned int& bits);
unsigned int twoSCompliment(const int& value, const unsigned int& bits);
int charPtrToInt(const char* input);

//------------------------------------------------------------------------

int main(int argc, char** argv){

  if(argc < 2){
    std::cerr << "\n WARNING: you have forgotten to provide needed data!\n\n  Usage:\n     ./roombaF <velocity> <radius>\n.";
    exit(1);
  }

  int velocity = charPtrToInt(argv[1]);
  unsigned int sixteenBits = 16;
  
  unsigned int newVel = twoSCompliment(velocity, sixteenBits);    
  twoBytes = split16BitsInto2Bytes(newVel);

  std::cout << "  The velocity set for Roomba will be: " << velocity << " mm/s, which is " << newVel << " after conversion.\n";
  std::cout << std::dec << "  Therefore the data te be sent equals " << twoBytes.High << "(HIGH BYTES) and " << twoBytes.Low << "(LOW BYTES)\n";

  unsigned int radius = charPtrToInt(argv[2]);
  twoBytes = split16BitsInto2Bytes(radius);

  std::cout << "\n  The turning radius is set Roomba as " << radius << " mm.\n";
  std::cout << std::dec << "   Therefore the data te be sent equals " << twoBytes.High << "(HIGH BYTES) and " << twoBytes.Low << "(LOW BYTES)\n";

  return 0;
}
//------------------------------------------------------------------------
TwoBytes split16BitsInto2Bytes(unsigned int& bits){
  // use bitwise AND operator to mask 8 buts with 255
  twoBytes.High = (bits >> 8) & 0xFF;
  twoBytes.Low =  bits & 0xFF;
 
 return twoBytes; 
}
//------------------------------------------------------------------------
unsigned int twoSCompliment(const int& value, const unsigned int& bits){
    unsigned int result = 0;
    if(value >= 0){
       result = value;
    }
    else {
       result = static_cast<unsigned int>((1 << bits) + value);
   }

  return result;
}

int charPtrToInt(const char* input){
   int output = 0;
   for(int index=0; input[index] != '\0'; index++){
       output = output * 10 + input[index] - '0';    
   }
   //or return input - 48 or retun input - '0' (for char)
  return output;
}
