#include <iostream>
#include "BinaryTree.h"

algorithm::BinaryTree* algorithm::BinaryTree::insert(algorithm::BinaryTree* node, int key){
   if(node->isEmpty()){
       node = new algorithm::BinaryTree();
       node->key = key;
       node->leftNode = nullptr;
       node->rightNode = nullptr;
       node->parentNode = nullptr;
   }
    else if(node->key < key){
        node->rightNode = insert(node->rightNode, key);
        node->rightNode->parentNode = node;
   }
    else {
        node->leftNode = insert(node->leftNode, key);
        node->leftNode->parentNode = node;
    }

    return node;
 }

bool algorithm::BinaryTree::isEmpty() const{
    return this == NULL;
}

void algorithm::BinaryTree::preOrder(algorithm::BinaryTree* node){
    if(node->isEmpty()){
        return;
    }
    std::cout << "   Binary Tree: \n\t " << node->parentNode << std::endl;
    preOrder(node->rightNode);
    preOrder(node->leftNode);
    
}

algorithm::BinaryTree* algorithm::BinaryTree::search(algorithm::BinaryTree* node, int key){ 
    if(node->isEmpty()){
        return nullptr;
    }
     else if(node->key == key){
         return node;
    } 
     else if(node-> key < key){
       return search(node->rightNode, key);   
    }
     else {
       return search(node->leftNode, key);     
     }
}

int algorithm::BinaryTree::findMin(algorithm::BinaryTree* node){
    if(node->isEmpty()){
        return -1;
    }
     else if(node->leftNode->isEmpty()){
         return node->key;
    }
     else {
        findMin(node->leftNode);
    }
}

int algorithm::BinaryTree::findMax(algorithm::BinaryTree* node){
   if(node->isEmpty()){
        return -1;
    }
     else if(node->rightNode->isEmpty()){
         return node->key;
    }
     else {
        findMin(node->rightNode);
    }
}

int algorithm::BinaryTree::successor(algorithm::BinaryTree* node){
    if(!node->rightNode->isEmpty()){
        return findMin(node->rightNode);
    }
}

int algorithm::BinaryTree::predecessor(algorithm::BinaryTree* node){
   if(!node->leftNode->isEmpty()){
        return findMax(node->leftNode);
    }
}

algorithm::BinaryTree* algorithm::BinaryTree::remove(algorithm::BinaryTree* node, int key){

       node = algorithm::BinaryTree::search(node, key);     
       if(node->isEmpty()){
           return nullptr;
       }

       if(node->key == key){
           if(node->leftNode->isEmpty() && node->rightNode->isEmpty()){
               node = nullptr;             
           }
            else if(node->leftNode->isEmpty() && !node->rightNode->isEmpty()){
                node->rightNode->parentNode = node->parentNode;
                node = node->rightNode;
           }
            else if(!node->leftNode->isEmpty() && node->rightNode->isEmpty()){
                node->leftNode->parentNode = node->parentNode;
                node = node->leftNode;
           }           
            else {
                node->key = key;
                int successorKey = algorithm::BinaryTree::successor(node);
                node->key = successorKey;
                node->rightNode = remove(node->rightNode, successorKey);
           }
       } 
        else if(node->rightNode->key < key){
            node->rightNode = remove(node->rightNode, key);
       } 
         else {
            node->leftNode = remove(node->leftNode, key);
       }

       return node;
} 