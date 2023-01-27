
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct Node {
    int data;
    struct Node *next;
};

/* insert at beginning 
  
  ( head is a global variable )
  STEP 1 - create a new node with given param value
  STEP 2 - check whether list is empty (head == NULL)
  STEP 3 - if it is, then set newNode->next equals NULL and head equals newNode
  STEP 4 - if it is not, then set newNode->next equals head and head equals newNode
*/
struct Node* insertAtBeginning(int value, struct Node* head);

/* insert at end
   STEP 1 - create a new node with value, and next=NULL
   STEP 2 - check whether list is empty (head==NULL)
   STEP 3 - if it is, set head=newNode
   STEP 4 - if it is not, define a node 
      pointer temp and initiliaze with head
   STEP 5 - keep moving the temp to its next node
      until it reacher to the last node in the list
      that is to say, untill temp->next = NULL
   STEP 6 - set temp->next to be equal to newNode
*/
int insertAtEnd(int value, struct Node* head);

/* insert at position
   STEP 1 - create a new node with value, and next=NULL
   STEP 2 - check whether list is empty (head==NULL)
   STEP 3 - if it is, set newNode->next=NULL, head=newNode
   STEP 4 - if it is not, define a node 
      pointer temp and initiliaze with head
   STEP 5 - keep moving the temp to its next node
      until it reaches to the node after which you wan to 
      insert the newNode(run a for-loop till position-1)
   STEP 6 - set newNode->next = temp->next and
            temp->next = newNode
*/
int insertAtPosition(int value, int pos, struct Node* head);

int removeFromBeginning(struct Node* head);
int removeFromEnd(struct Node* head);

int removePosition(int pos, struct Node* head);

void showData(struct Node* node);
void recursiveShow(struct Node* link);

#endif