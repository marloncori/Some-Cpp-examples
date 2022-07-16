#include <iostream>
#include <system_error>
#include <errno.h>

#include "SLList.h"

SLList::SLList(){
    head = tail = 0;
    std::cout << "\t--> An empty Singly Linked List has been created." << std::endl;  
}

SLList::~SLList(){
  for(SLLNode *p; !isEmpty(); ){
    p = head->next;
    delete head;
    head = p;
  }
  std::cout << "\t--> The Singly Linked List has been wiped out from memory!" << std::endl;
}

bool SLList::isEmpty() const {
   return head == 0;
}

void SLList::pushToHead(int value){
   head = new SLLNode(value, head);
   if(tail == 0){
     tail = head;
   }
   std::cout << " [INFO] Value " << value << " has been pushed to Singly Linked List\'s head!" << std::endl;
}

void SLList::pushToTail(int value){
   if(tail != 0){
     tail->next = new SLLNode(value);
     tail = tail->next;
   }
   else {
     head = tail = new SLLNode(value);
   }
      std::cout << " [INFO] Value " << value << " has been pushed to Singly Linked List\'s tail!" << std::endl; 
}

int SLList::delFromHead(){
   if(isEmpty()){
     throw std::system_error(errno,
        std::system_category(), "Linked list is already empty!");
   }
   int value = head->data;
   SLLNode *tmp = head;
   if(head == tail){
      head = tail = 0;
   }
   else {
     head = head->next;
   }
   delete tmp;
   std::cout << " ==>> Data has been erased from Singly Linked List\'s head!" << std::endl;
   
  return value;
}

int SLList::delFromTail(){
    if(isEmpty()){
     throw std::system_error(errno,
        std::system_category(), "Linked list is already empty!");
    }
    int value = tail->data;
    if(head == tail){
       delete head;
       head = tail = 0;
    }
    else {
       SLLNode* tmp;
       for(tmp = head; tmp->next != tail; tmp = tmp->next){
          delete tail;
          tail = tmp;
          tail->next = 0;
       }
    }
  std::cout << " ==>> Data has been erased Singly Linked List\'s tail!" << std::endl;
  
  return value;
}

void SLList::deleteNode(int value){
   if(head != 0){
     if(head == tail && value == head->data){
        delete head;
        head = tail = 0;
     }
     else if(value == head->data){
       SLLNode *tmp = head;
       head = head->next;
       delete tmp;
     }
     else {
       SLLNode *pred, *tmp;
       for(pred = head, tmp = head->next;
            tmp != 0 && !(tmp->data == value);
             pred = pred->next, tmp = tmp->next);
       if(tmp != 0){
          pred->next = tmp->next;
          if(tmp == tail){
                tail = pred;
          }
          delete tmp;
       }
     }
   }
   std::cout << " ::: Node has been deleted from Singly Linked List :::" << std::endl;
}

bool SLList::isPresent(int value) const {
   SLLNode *tmp;
   for(tmp = head; tmp != 0 && !(tmp->data == value); tmp = tmp->next);
   return tmp != 0;
}
