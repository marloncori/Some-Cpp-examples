#include <iostream>
#include "binarySearchTree.h"

Node* BinaryTree::createNode(int value){
    node = new Node();
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    std::string line("\n\t------------------------------------------\n");
    std::cout << line << "\t   Node has been created!" << line << std::endl;
  return node;
}

void BinaryTree::insertNode(Node* newNode, int value){
    if(newNode == NULL){
        newNode = createNode(value);
        node = newNode;
        std::string line("\n\t------------------------------------------\n");
        std::cout << line << "\t  Node insertion successful!" << line << std::endl;
    }
    else {
        rootValue = newNode->data;
        if(value > rootValue){
            insertNode(newNode->right, value);
        }
        else{
            insertNode(newNode->left, value);
        }
    }
}

Node* BinaryTree::getNode() const {
    return node;
}

bool BinaryTree::searchNode(Node* thisNode, int query) {
    if(thisNode == NULL){
        return false;
    }
    else if(thisNode->data == query){
        return true;
    }
    else if(query < thisNode->data){
        return searchNode(thisNode->left, query);
    }
    else {
        return searchNode(thisNode->right, query);
    }
}