#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct Node {
  int data;
  struct Node* next;
} node_t;

void pushFront(node_t** head, int value);
void insert(node_t** head, int value, int n);
void linkedList(node_t* head);
void getData(node_t* head);

#endif // linked_list.h