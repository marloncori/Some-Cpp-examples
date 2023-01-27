#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void pushFront(node_t** head, int value)
{
   node_t* temp = (node_t*)malloc(sizeof(node_t));
   (*temp).data = value;
   (*temp).next = NULL;
   if(*head)
   {
      temp->next = *head;
   }
   *head = temp;
}

void insert(node_t** head, int value, int n)
{
  node_t* temp = (node_t*)malloc(sizeof(node_t));
  (*temp).data = value;
  (*temp).next = NULL;
  if(n == 1)
  { 
    temp->next = *head;
    *head = temp;
    return;
  }
  node_t* temp2 = *head;
  for(int i=0; i<n-2; ++i)
  {
     temp2 = (*temp2).next;
  }
  (*temp).next = (*temp2).next;
  (*temp2).next = temp;
}

void linkedList(node_t* head)
{
  printf("  Linked list = [");
  while(head != NULL)
  {
    printf(" %d", (*head).data);
    head = (*head).next;  
  }
  printf(" ]\n");
}

void getData(node_t* head)
{
  int input, number, choice, index;
  printf("\n How many numbers would you like to \n insert in the linked list? \n");
  printf("  Total: ");
  scanf("%d", &input);
  for(int i=0; i<input; ++i)
  {
     printf(" >>> %d. Enter a value: ", (i+1));
     scanf("%d", &number);
     printf(" Where would you like to insert this value?n");
     printf("\n\t [ 1 ] at the beginning \n\t [ 2 ] at a specific index\n");
     printf("   Option: ");
     scanf("%d", &choice);
     switch(choice)
     {
        case 1:
           pushFront(&head, number);
           linkedList(head);
           break;
        case 2:
           printf("  --> Please tell us an index number: ");
           scanf("%d", &index);
           insert(&head, number, index);
           linkedList(head);
           break;
        default:
           printf("  Invalid option...\n");
           break;
    }
  }  
}
