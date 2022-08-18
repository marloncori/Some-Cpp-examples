#include <iostream>
#include <windows.h>

int iterator = 0;

template<typename T>
void println(const T &msg);

void delay(long time);
void setup();
void function3();
void function2(std::string text, int value2);
void function1(void (*func2)(std::string msg, int val), std::string msg, int val, void (*func3)(), long value);
void loop();

int main(){
  setup();

  while(1){
     loop();
     delay(1000);
  }

 return 0;
}

template<typename T>
void println(const T &msg) {
  std::cout << " ---------------------------- " << std::endl;
  std::cout << " \t" << msg << std::endl;
  std::cout << " ---------------------------- " << std::endl;
}

void delay(long time){
   Sleep(time);
}

void setup() {
  println(" Program is starting...");

}

void function3() {    
    println("func3");
}

void function2(std::string text, int value2) {
    
    println(text);
    println(value2);
}

void function1(void (*func2)(std::string msg, int val), std::string msg, int val, void(*func3)(), long time){     
     (*func2)(msg, val);
     delay(time);
     (*func3)();
     delay(time);      
}


void loop() {
    const char* words[9] = {"Jesus", "Christ", "is", "the", "Lord", "and", "He", "is", "coming back"};
    function1(function2, words[iterator], 7, function3, 2000);
    iterator++;
    if(iterator == 9){
      iterator = 0;
    }
}
