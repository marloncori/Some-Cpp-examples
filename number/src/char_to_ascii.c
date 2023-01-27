#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#include "char_to_ascii.h"

char* get_string(char name[30], char buffer[30])
{
    memset(name, 0, sizeof(name));
    memset(buffer, 0, sizeof(buffer));
    printf("\n Enter a name, please: ");
    fgets(name, sizeof(name), stdin);
    Sleep(1);
    if(name != ""){
        strcpy(buffer, name);
    }

   return buffer;
}

void show_ascii(char buff[30])
{
    char* line = "#######################################";   
    printf("\n%s\n", line);
    printf(" You have written the following name: %s\n", buff);
    Sleep(1);
    printf("  This are the ASCII values of the characters:\n");
    Sleep(0.5);
    size_t n = strlen(buff); 
    if(n > 0 && buff[n-1] == '\n'){
        buff[n-1] = '\0';
        --n;
    }

    for(size_t i = 0; i < n; ++i){
        int value = (int)buff[i];
        printf("     >>> %c : %d \n", buff[i], value);
        Sleep(0.2); 
    }
    printf("\n The length of the name was: %zu characters\n", n);
    printf("\n%s\n", line);
}
