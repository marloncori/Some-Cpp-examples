#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#include "char_to_ascii.h"

#define STR_SIZE 30

//void setup_vars();

char name[STR_SIZE];
char* line = "##########################################";
char buffer[STR_SIZE];
char output[STR_SIZE];
unsigned int counter;

int main(void)
{
    counter = 0;

    printf("\n%s\n", line);
    Sleep(0.2);
    printf(" >>> CHARACTERS TO ASCII VALUE CONVERTER <<< \n" );
    Sleep(0.2);    
    printf("  # Program is about to start... #\n");
    printf("%s\n", line);
    Sleep(1);

    do{
        ++counter;
        //setup_vars();
        strcpy(output, get_string(name, buffer));
        show_ascii(output);
     }while(counter < 5);

    Sleep(1);
    printf("\n%s\n", line);
    Sleep(0.2);
    printf("# Program execution has ended. #\n");
    Sleep(0.2);
    printf("%s\n", line);

  return 0;
}

/*void setup_vars(){
  memset(output, 0, sizeof(output));
  memset(name, 0, sizeof(name));
  memset(buffer, 0, sizeof(buffer));
}*/