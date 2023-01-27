#ifndef NODE_H
#define NODE_H

#include "hashTable.h"

struct Node {
    char* key;
    char* value;
    struct Node* next;
};

struct Node* createNode(char *key, char* value);
void insertNode(struct Hash* hash, char* key, char* value);

#endif