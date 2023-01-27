#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "singlyLinkedList.h"


struct Node* firstTest(struct Node* root){
    int number = 49;
    struct Node* newNode = insertAtBeginning(number, root);
    if(newNode == NULL){
         printf("\033[1;32m !!! Node has not been created, value not inserted !!!!\n\033[0m");
         perror("\033[1;34m --> Something went wrong:\033[0m \033[1;32m%s\n\033[0m", strerror(errno));
         exit(0);
    }
    free(root);

    number = 12;
    struct Node* newRoot = insertAtBeginning(number, newNode);
    if(newRoot == NULL){
         printf("\033[1;32m !!! Node has not been created, value not inserted !!!!\n\033[0m");
         perror("\033[1;34m --> Something went wrong:\033[0m \033[1;32m%s\n\033[0m", strerror(errno));
         exit(0);
    }
    free(newNode);

  return newRoot;
 }

struct Node* secondTest(struct Node* root){
    int value = 35;
    int pos = 1;
    if(insertAtPosition(value, pos, root) != 0){
         printf("\033[1;32m !!! Node has not been created, value not inserted !!!!\n\033[0m");
         perror("\033[1;34m --> Something went wrong:\033[0m \033[1;32m%s\n\033[0m", strerror(errno));
         exit(0);
    }
    value = 40;
    pos = 2;
    if(insertAtPosition(value, pos, root) != 0){
         printf("\033[1;32m !!! Node has not been created, value not inserted !!!!\n\033[0m");
         perror("\033[1;34m --> Something went wrong:\033[0m \033[1;32m%s\n\033[0m", strerror(errno));
         exit(0);
    }

    value = 7;
    pos = 1;
    if(insertAtPosition(value, pos, root) != 0){
         printf("\033[1;32m !!! Node has not been created, value not inserted !!!!\n\033[0m");
         perror("\033[1;34m --> Something went wrong:\033[0m \033[1;32m%s\n\033[0m", strerror(errno));
         exit(0);
    }

  return root;
}

int thirdTest(struct Node* root){
    if(removeFromBeginning(root) != 0){
         printf("\033[1;32m !!! Node has not been created, value not inserted !!!!\n\033[0m");
         perror("\033[1;34m --> Something went wrong:\033[0m \033[1;32m%s\n\033[0m", strerror(errno));
         return -1;
    }
  return 0;
}

int fourthTest(struct Node* root){
    int pos = 2;
    if(removePosition(pos, root) != 0){
         printf("\033[1;32m !!! Node has not been created, value not inserted !!!!\n\033[0m");
         perror("\033[1;34m --> Something went wrong:\033[0m \033[1;32m%s\n\033[0m", strerror(errno));
         return -1;
    }
    pos = 1;
    if(removePosition(pos, root) != 0){
         printf("\033[1;32m !!! Node has not been created, value not inserted !!!!\n\033[0m");
         perror("\033[1;34m --> Something went wrong:\033[0m \033[1;32m%s\n\033[0m", strerror(errno));
         return -1;
    }
  return 0;
}


int main(void){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* newHead = firstTest(head);

    if(newHead == NULL) {
        perror("\033[1;34m --> An error has happened ==>>\033[0m \033[1;32m%s\n\033[0m", strerror(errno));       
    }
    else {
        printf("\n\033[1;33m>>>\033[0m \033[1;32mFIRST\033[0m \033[1;36mTEST has been successfully accomplished!\033[0m \033[1;33m<<<\n\033[0m");       
    }
    
    struct Node* newRoot = secondTest(newHead);
    if(newRoot == NULL) {
        perror("\033[1;34m --> An error has happened ==>>\033[0m \033[1;32m%s\n\033[0m", strerror(errno));       
    }
    else {
        printf("\n\033[1;33m>>>\033[0m \033[1;35mSECOND\033[0m \033[1;36mTEST has been successfully accomplished!\033[0m \033[1;33m<<<\n\033[0m");       
    }
    printf("\n This your linked list: ");
    /*if(thirdTest(newRoot) != 0) {
        perror("\033[1;34m --> An error has happened ==>>\033[0m \033[1;32m%s\n\033[0m", strerror(errno));       
    }
    else {
        printf("\n\033[1;33m>>>\033[0m \033[1;32mTHIRD\033[0m \033[1;36mTEST has been successfully accomplished!\033[0m \033[1;33m<<<\n\033[0m");       
    }*/
   
    if(fourthTest(newRoot) != 0) {
        perror("\033[1;34m --> An error has happened ==>>\033[0m \033[1;32m%s\n\033[0m", strerror(errno));       
    }
    else {
        printf("\n\033[1;33m>>>\033[0m \033[1;32mFOURTH\033[0m \033[1;36mTEST has been successfully accomplished!\033[0m \033[1;33m<<<\n\033[0m");       
    }
   
   //free(newRoot);  
  return 0;
}