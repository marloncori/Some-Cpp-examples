#ifndef SLL_NODE_H
#define SLL_NODE_H

class SLLNode {
  public:
     SLLNode();
     ~SLLNode();
     SLLNode(int value);
     SLLNode(int value, SLLNode* ptr);
     
     int data;
     SLLNode* next;
};

#endif //SSLNode.h
