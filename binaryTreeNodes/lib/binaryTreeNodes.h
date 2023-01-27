#ifndef BINARY_TREE_NODES_H_
#define BINARY_TREE_NODES_H_

#include <iostream>


struct binaryTreeNodes
{
    int data;
    binaryTreeNodes* left;
    binaryTreeNodes* right;

    binaryTreeNodes() = default;
    explicit binaryTreeNodes(int d) : data(d)
    {
        left = nullptr;
        right = nullptr;
    }
};

int isEmpty(binaryTreeNodes *node);

std::ostream& operator<<(std::ostream& os, binaryTreeNodes* node);

int treeSize(binaryTreeNodes *leaf);

int treeHeight(binaryTreeNodes *leaf);

void showTree(binaryTreeNodes *node);

#endif // binaryTreeNodes.h