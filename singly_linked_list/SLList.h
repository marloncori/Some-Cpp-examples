#ifndef SL_LIST_H
#define SL_LIST_H

#include "SLLNode.h"

class SLList {
   public:
     SLList();
     ~SLList();
     bool isEmpty() const;
     void pushToHead(int value);
     void pushToTail(int value);
     int  delFromHead();
     int  delFromTail();
     void deleteNode(int value);
     bool isPresent(int value) const;

   private:
     SLLNode *head;
	 SLLNode *tail;
};

#endif //SL_LIST_H
