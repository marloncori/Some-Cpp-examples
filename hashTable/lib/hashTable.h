#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HASH_SIZE 100

#include "Node.h"

struct Hash {
    struct Node *list[HASH_SIZE];
};

struct Hash* createHash();
unsigned int hashCode(char *key);
char* searchValue(struct Hash* hash , char* key);

#endif // hashTable.h