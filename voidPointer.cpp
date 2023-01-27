#include <iostream>

enum VarType {
   SHORT,
   INT,
   LONG,
   FLOAT,
   DOUBLE,
   CHAR,
   STRING
};	

auto type = VarType::SHORT;
auto type2 = VarType::INT;
auto type3 = VarType::LONG;
auto type4 = VarType::FLOAT;
auto type5 = VarType::DOUBLE;
auto type6 = VarType::STRING;

auto show(void* ptr, const VarType& tp) -> void {
   switch(tp){
      case VarType::SHORT:
        std::cout << *((short*)ptr) << std::endl;
        break;
        
      case VarType::INT:
        std::cout << *((int*)ptr) << std::endl;
        break;

        case VarType::LONG:
        std::cout << *((long*)ptr) << std::endl;
        break;

      case VarType::FLOAT:
        std::cout << *((float*)ptr) << std::endl;
        break;

      case VarType::DOUBLE:
        std::cout << *((double*)ptr) << std::endl;
        break;

      case VarType::CHAR:
        std::cout << *((char*)ptr) << std::endl;
        break;

      default:
        std::cout << " Provided type not supported!" << std::endl;
        break;
   }
   free(ptr);  
}

auto main() -> int {

    short val {4}; int val2 {15};
    long val3 {123645}; float PI{3.14159};
    double val5 {9876.0021};

    show(&val, type);
      show(&val2, type2);
        show(&val3, type3);
            show(&PI, type4);
                show(&val5, type5);
    
    std::string binary("0b01010101");
    show(&binary, type6);

  return 0; 
}