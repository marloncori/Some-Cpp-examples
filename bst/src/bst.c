#include <stdio.h>
#include "bst.h"

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    printf("\n  ---> Node has been successfully created!\n");
    return newNode;
}

void insertNode(struct Node* node, int value){
    if(node == NULL){
        node = createNode(value);
        printf("\n   ==>> Value has been properly inserted!\n");
    }
    else {
         if(value > node->data){
             insertNode(node->right, value);
         }
         else {
             insertNode(node->left, value);
         }
    }
}

void showNodes(struct Node* node, int count){
    if(node == NULL){
        return;
    }
    else {
        showNodes(node->right, count+1);
        for(int i=0; i<count; i++){
            printf(" \n");
        }
        printf(" %d", node->data);
        showNodes(node->left, count+1);
    }
    printf("\n\n  All nodes have been correctly displayed!\n");
}