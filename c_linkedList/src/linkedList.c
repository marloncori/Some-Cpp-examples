#include<stdio.h>
#include<stdlib.h>

#include "linkedList.h"

struct Node* insert_front(struct Node* link, int value){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = link;
    link = temp;
    return link;
}

struct Node* insert_position(struct Node* link, int place, int value){
    
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if(place == 1){
        temp->next = link;
        link = temp;
        return link;
    }
    struct Node* temp2 = link;
    for(int i=0; i<place-2; i++){
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
    return temp2;
}

void remove_node(struct Node* link){
   int position;
   printf("\n\t Enter the position you want \n\t to move a node from: \n");
   printf("\n\t\t Option <<< ");
   scanf("%d", &position);
   struct Node* temp = link;
   if(position == 1){
       link = temp->next;
       free(temp);
       show_data(link);
       return;
   }
   for(int i=0; i<position-2; i++){
       temp = temp->next;
   }
   struct Node* temp2 = temp->next;
   temp->next = temp2->next;
   free(temp2);
   show_data(temp);
}

void recursive_reverse(struct Node* link){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(!link->next){
        temp->data = link->data;
        temp->next =  link->next;
        show_data(temp);
        return;
    }
    recursive_reverse(link->next);
    temp->next = link;
    link->next = NULL;
}

void show_data(struct Node* link){
    struct Node* temp = link;
    printf("\n\t This is your linked list: \n");
    printf("\n\t Nodes = {");
    while(temp){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf(" }.\n");
}

void recursive_show(struct Node* link){
    if(!link){
        return;
    }
    recursive_show(link->next);
    printf(" %d", link->data);
}