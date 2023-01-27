#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "Node.h"

struct Node* createNode(char *key, char* value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
};

void insertNode(struct Hash* hash, char* key, char* value){
    unsigned int index = hashCode(key);
    struct Node *node = hash->list[index];
    if(node == NULL){
        hash->list[index] = createNode(key, value);
    } else {
        while(node){
            if(node->next == NULL){
                node->next = createNode(key, value);
                break;
            }
            node = node->next;
        }
    }
}