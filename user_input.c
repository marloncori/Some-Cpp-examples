#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#define STRING_SIZE 20

unsigned int number;
char* line = "#######################################";
char buffer[STRING_SIZE];
char output[STRING_SIZE];
unsigned int counter;

char* get_info(unsigned int* value, char buffer[STRING_SIZE]);
void show_info(char buffer[STRING_SIZE]);

int main(void)
{
   counter = 0;

    printf("\n%s\n", line);
    printf("# Program is about to start... #\n");
    printf("%s\n", line);
    Sleep(1);

    do{
       counter++;
       strcpy(output, get_info(&number, buffer));
       show_info(output);
     }while(counter < 5);

    Sleep(1);
    printf("\n%s\n", line);
    printf("# Program execution has ended. #\n");
    printf("%s\n", line);
}

char* get_info(unsigned int* value, char buffer[STRING_SIZE])
{
    printf("\n Enter a number, please: ");
    scanf("%d", value);
    Sleep(1);
    if(value != NULL){
        itoa((int)*value, buffer, 10);
    }
    return buffer;
}

void show_info(char buffer[STRING_SIZE])
{
    printf("\n%s\n", line);
    printf(" You have chosen: %s\n", buffer);
    int num = atoi(buffer);
    switch(num){
      case 7:
         printf(" -> That is a beautiful number!\n");
         Sleep(1);
         break;
      case 35:
         printf(" -> That is Marlon\'s age!\n");
         Sleep(1);
         break;
      case 123567:
         printf(" WOW, that is a big number!");
         break;   
       default:
         printf(" Thanks for the help.");
         break; 
    }
}
