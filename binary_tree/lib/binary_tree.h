#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include<iostream>
//declare the binary tree node
struct BinaryTreeNode 
{
    int data;
    struct BinaryTreeNode *left, *right;
};

//create a new node
BinaryTreeNode* newNode(int key);
bool isEmpty(BinaryTreeNode* node);

std::ostream& operator<<(std::ostream& output, const struct BinaryTreeNode* node);
//perform inorder traversal of BTN
void inOrder(BinaryTreeNode* root);
BinaryTreeNode* insert(BinaryTreeNode* node, int key);

BinaryTreeNode* minValueNode (BinaryTreeNode* node);
BinaryTreeNode* deleteNode(BinaryTreeNode* root, int key);

#endif // binary_tree.h