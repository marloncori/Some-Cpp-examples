
#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList.h"

struct Node* insertAtBeginning(int value, struct Node* head){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
        printf("\n\033[1;35mValue\033[0m \033[1;33mhas been inserted in\033[0m \033[1;32mnode!\033[0m\n");
    }
    else {
        newNode->next = head;
        head = newNode;
        printf("\n\033[1;35mValue\033[0m \033[1;33mhas been inserted in\033[0m \033[1;32mnode!\033[0m\n");
    }
  return head;
}

int insertAtEnd(int value, struct Node* head){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
      head = newNode;
      printf("\n\033[1;34m[insertAtEnd]\033[0m\n\t\033[1;35mValue\033[0m \033[1;33mhas been inserted in\033[0m \033[1;32mnode!\033[0m\n");   
      return 0;
    }
    else {
      struct Node* temp = head;
      while(temp->next != NULL){
         temp = temp->next;
         temp->next = newNode;
      }
      printf("\n\033[1;34m[insertAtEnd]\033[0m\n\t\033[1;35mValue\033[0m \033[1;33mhas been inserted in\033[0m \033[1;32mnode!\033[0m\n");
      return 0;   
    }
   return -1;
}

int insertAtPosition(int value, int pos, struct Node* head){
    int i = 0;
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head == NULL){
      newNode->next = NULL;
      head = newNode;
      printf("\n\033[1;34m[insertAtPosition]\033[0m\n\t\033[1;35mValue\033[0m \033[1;33mhas been inserted in\033[0m \033[1;32mnode!\033[0m\n");
      return 0;
    }
    else {
      struct Node* temp = head;
       for(i = 0; i < pos-1; i++){
         temp = temp->next;
       }
      newNode->next = temp->next;
      temp->next = newNode;
      printf("\n\033[1;34m[insertAtPosition]\033[0m\n\t\033[1;35mValue\033[0m \033[1;33mhas been inserted in\033[0m \033[1;32mnode!\033[0m\n");
      return 0;
    }
   return -1;
}

int removeFromBeginning(struct Node* head){
  if(head == NULL){
    printf("\n\033[1;34m[removeFromBeginning]\033[0m\n\t\033[1;35mLinked list\033[0m \033[1;33m is already\033[0m \033[1;32mempty!\033[0m\n");
    return 0;
  }
  else {
    struct Node* temp = head;
    if(head->next == NULL){
       head = NULL;
       free(temp);
       printf("\n\n\t\033[1;35mNode\033[0m \033[1;33mhas been deleted from the\033[0m \033[1;32mbeginning!\033[0m\n");
       return 0;
    }
    else {
       head = temp->next;
       free(temp);
       printf("\n\n\t\033[1;35mNode\033[0m \033[1;33mhas been deleted from the\033[0m \033[1;32mbeginning!\033[0m\n");
       return 0;
    }
  }
  return -1;
}

int removeFromEnd(struct Node* head){
   if(head == NULL){
      printf("\n\033[1;34m[removeFromBeginning]\033[0m\n\t\033[1;35mLinked list\033[0m \033[1;33m is already\033[0m \033[1;32mempty!\033[0m\n");    
      return 0;
   }
   else {
     struct Node* temp1 = head;
     struct Node* temp2;
     if(head->next == NULL){
        head = NULL;
     }
     else {
       while(temp1->next != NULL){
          temp2 = temp1;
          temp1 = temp1->next;
       }
       temp2->next = NULL;
     }
     free(temp1);
     printf("\n\033[1;35mNode\033[0m \033[1;33mhas been deleted from the\033[0m \033[1;32mlinked list end!\033[0m\n");
     return 0;
   }
  return -1;
}

int removePosition(int pos, struct Node* head){
  int i;
  int flag = 0;
  struct Node* temp1 = head;
  struct Node* temp2;
  if(pos == 1){
    head = temp1->next;
    free(temp1);
    printf("\n\033[1;35mNode\033[0m \033[1;33mhas been deleted from the\033[0m \033[1;32mindex %d\033[0m\n", pos);
    return 0;
  }
  else {
    for(i = 0; i<pos-1; i++){
       if(temp1->next != NULL){
          temp2 = temp1;
          temp1 = temp1->next;
       }
       else {
          flag = 1;
          break;
       }
    }
    if(flag == 0){
      temp2->next = temp1->next;
      free(temp1);
      printf("\n\033[1;35mNode\033[0m \033[1;33mhas been deleted from the\033[0m \033[1;32mindex %d\033[0m\n", pos);
      return 0;
    }
    else {
      printf("\n\033[1;35mPOSITION\033[0m \033[1;33mexceeds linked list\033[0m \033[1;32mSIZE!\033[0m\n");
      return -1;
    }
    return 0;
  }
  return -1;
}

void showData(struct Node* node){
    struct Node* temp = node;
    printf("\n\t This is your linked list: \n");
    printf("\n\t Nodes = {");
    while(temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf(" }.\n");
}

void recursiveShow(struct Node* link){
    if(link == NULL){
        return;
    }
    recursiveShow(link->next);
    printf(" %d ", link->data);
}