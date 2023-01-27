#include <iostream>
#include "ncurses.h"

typedef struct {
  unsigned int code;
  std::string name;
} action;

action keys[] = {
{KEY_BREAK, "Break key"},
{KEY_DOWN, "Arrow down"},
{KEY_UP, "Arrow up"},
{KEY_LEFT, "Arrow left"},
{KEY_RIGHT, "Arrow right"},
{KEY_HOME, "Home key"},
{KEY_BACKSPACE	Backspace"}
};

int main(){
  initscr();
  int input;
  raw();
  keypad(stdscr, TRUE);
  noecho();

  do {
    input = getch();
    for(int i=0; i<7; i++){
       if(input == keys[i].code){
          std::cout << " You\'ve pressed: " 
            << keys[i].name << "!\n";
       }
    }
  } while(input != 113); // q = 113

 
  endwin();

 return 0;
}
