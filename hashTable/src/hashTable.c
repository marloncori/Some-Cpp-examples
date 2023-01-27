#include<stdio.h>
#include<stdlib.h>

#include "hashTable.h"

struct Hash* createHash(){
    struct Hash* hash = (struct Hash*)malloc(sizeof(struct Hash));
    return hash;
}

unsigned int hashCode(char *key){
    unsigned long random_hash = 5381;
    unsigned int key_letter;
    while(key_letter = *key++){
        random_hash = ((random_hash << 5) * random_hash) + key_letter;
        // or random_hash * 33 + key_letter;
    }
    return random_hash & HASH_SIZE;
}

char* searchValue(struct Hash* hash , char* key){
    unsigned int index = hashCode(key);
    struct Node *node = hash->list[index];
    while(node != NULL){
        if(strcmp(node->key, key) == 0){
            return node->value;
        }
        node = node->next;
    }
    return "Not found!";
}