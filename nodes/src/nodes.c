#include <stdlib.h>
#include <stdio.h>
#include "nodes.h"

struct Node* create(long value, struct Node* previous){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(previous){
        newNode->previous = previous;
    }
    return newNode;
}

void show(struct Node** node){
    struct Node* iterator = *node;
    printf("\n\n");
    do{
        printf("The node value is: %d <<<---", iterator->data);
        iterator = iterator->previous;
    } while(iterator);
    printf("\n\n");

    free(iterator);
}