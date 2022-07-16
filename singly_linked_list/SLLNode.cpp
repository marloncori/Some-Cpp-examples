#include "SLLNode.h"

SLLNode::SLLNode(){
    next = 0;
}

SLLNode::~SLLNode(){
   delete this;
}

SLLNode::SLLNode(int value){
    data = value;
    next = 0;
}

SLLNode::SLLNode(int value, SLLNode* ptr){
    data = value;
    next = ptr;
}
