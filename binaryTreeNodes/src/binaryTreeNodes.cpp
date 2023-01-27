
#include <iostream>
#include <iomanip>

#include "binaryTreeNodes.h"

int isEmpty(binaryTreeNodes *node)
{
    return node == nullptr;
}

std::ostream& operator<<(std::ostream& os, binaryTreeNodes* node)
{
    os << "  Binary tree:\n" << std::setw(15) << node->data << "\n"
    << std::setw(13) << "/\n" << std::setw(11) << node->right << std::setw(17)
    << "\\ \n" << std::setw(19) << node->left;

    return os;
}

int treeSize(binaryTreeNodes *leaf)
{
    if(isEmpty(leaf))
    {
        return 0;
    }
    else 
    {
        return 1 + treeSize(leaf->left) + treeSize(leaf->right);
    }
}

int treeHeight(binaryTreeNodes *leaf)
{
    int lh, rh;

    if(isEmpty(leaf))
    {
        return -1;
    }
    else 
    {
        lh = treeHeight(leaf->left);
        rh = treeHeight(leaf->right);
        return 1 + (lh > rh ? lh : rh);
    }
}

void showTree(binaryTreeNodes *node)
{
    if(!isEmpty(node))
    {
        std::cout << node << std::endl;
    }
}

