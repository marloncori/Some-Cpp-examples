#include <iostream>
#include <ctime>
#include <windows.h>

#include "fsm.h"

int main(int argc, char* argv[]){

  srand(time(NULL));
  FSM* finiteStateMachine = new FSM();

  std::cout << "_______________________________________" << std::endl;
  std::cout << "\033[1;34m   FINITE STATE MACHINE V1.0\033[0m" << std::endl;
  std::cout << "______________________________________" << std::endl;
  Sleep(1000);

  while(!finiteStateMachine->isCompleted()){
     finiteStateMachine->update();
       Sleep(1000);
  }

  std::cout << "_______________________________________" << std::endl;
  std::cout << "\033[1;34m   FINITE STATE MACHINE V1.0\033[0m" << std::endl;
  std::cout << "______________________________________" << std::endl;
  Sleep(1000);

  return 0;
}