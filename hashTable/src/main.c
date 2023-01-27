#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#include "hashTable.h"
#include "Node.h"

void validate(struct Hash* hash, char* result, char* msg){
    char* name = "Marlon";
    char* word3 = "";
    if(strcmp(result, msg) == 0){
        printf("\n  %s. Try again.\n", msg);
        printf("\n  Provide us with the key for \n the related value to found.\n");
        printf("\n\t >> Key: ");
        scanf("%s", &word3);
        if(!word3){
            perror(" WARNING! An error happened: %s\n", strerror(errno));
            EXIT_FAILURE;
        }
        result = searchValue(hash, word3);
        if(!result){
            perror(" WARNING! An error happened: %s\n", strerror(errno));
            EXIT_FAILURE;
        }
        validate(hash, result, msg);
    } else {
        printf("\n   >> 1. key = %s : value = %s\n", word3, result);
        printf("\t Thank you, goodbye, master %s !\n", name);
    }
}

int takeUserInput(struct Hash* hash, char* word){
    char* name1 = "";
    char* word1 = "";
    printf("\n Now enter two words to be \n added to the hashTable: ");
    printf("\n\t Key: ");
    scanf("%s", &word1);
    if(!word1){
      perror(" WARNING! An error happened: %s\n", strerror(errno));
      return -1;
    }
    printf("\n\t Value: ");
    scanf("%s", &name1);
    if(!name1){
       perror(" WARNING! An error happened: %s\n", strerror(errno));
       return -1;
    }
    insertNode(hash, word1, name1);
    char* error_msg = "Not found!";

    printf("\n  Key and value successfully added!\n");
    printf("\n Now provide us with the key for \n the related value to found.\n");
    printf("\n\t >> Key: ");
    scanf("%s", &word);
    if(!word){
       perror(" WARNING! An error happened: %s\n", strerror(errno));
       return -1;
    }
    char* result = searchValue(hash, word);
    validate(hash, result, error_msg);

  return 0;
}

int main(void)
{
    struct Hash* hash = createHash();
    char* word = "hello", name = "Fabio";

    insertNode(hash, word, "hashTable");
    insertNode(hash, name, "Akita");

    char* result1 = searchValue(hash, word);
    if(!result1){
         perror(" WARNING! An error happened: %s\n", strerror(errno));
         EXIT_FAILURE;
    }

    char* result2 = searchValue(hash, name);
    if(!result2){
         perror(" WARNING! An error happened: %s\n", strerror(errno));
         EXIT_FAILURE;
    }
     
    printf("\n  >> 1. key = %s : value = %s\n", word, result1);
    printf("  >> 2. key = %s : value = %s\n", name, result2);
    printf("\n");

    char* word2 = "Jesus";
    char* name2 = "Marlon";

    insertNode(hash, word2, "Christ the Lord");
    insertNode(hash, name2, "Ribeiro");
    
    printf("\n  >> 1. key = %s : value = %s\n", word2, searchValue(hash, word2));
    printf("  >> 2. key = %s : value = %s\n", name2, searchValue(hash, name2));
    word2 = "";
    
    if( takeUserInput(hash, word2) < 0){
        perror(" WARNING! An error happened: %s\n", strerror(errno));
        EXIT_FAILURE;
    }
    
    return 0;
}