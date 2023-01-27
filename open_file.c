#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    FILE *fptr = fopen("TS_problem.exe","r");
    if( !fptr )
    {
        printf("Error: %s\n", strerror(errno));
    }
    return(0);
}