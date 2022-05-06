#include <iostream>
#include "binary_tree.h"

//create a new node
BinaryTreeNode* newNode(int key)
{
    BinaryTreeNode* temp = new BinaryTreeNode();
    temp->data = key;
    temp->left = temp->right = nullptr;
    std::cout << "  New node has been created! Node->data = " 
    << temp << std::endl;

    return temp;
}

bool isEmpty(BinaryTreeNode* node) {
    return node == nullptr;
}

std::ostream& operator<<(std::ostream& output, const struct BinaryTreeNode* node)
{
    output << node->data;
    return output;
}
//perform inorder traversal of BTN
void inOrder(struct BinaryTreeNode* root)
{
   if(!isEmpty(root))
   {
      inOrder(root->left);
      std::cout << " Node data: \n\t" 
           << root << std::endl;
      inOrder(root->right);
   } 
}

struct BinaryTreeNode* insert(BinaryTreeNode* node, int key)
{
    if(isEmpty(node))
    {
        return newNode(key);
    }
   
    if(key < node->data)
    {
       node->left = insert(node->left, key);     
    }
    else 
    {
       node->right = insert(node->right, key);     
    }

    return node;
}

BinaryTreeNode* minValueNode (struct BinaryTreeNode* node)
{
    BinaryTreeNode* current = node;
    while(current && !isEmpty(current->left))
    {
        current = current->left;
    }

    return current;
}

BinaryTreeNode* deleteNode(BinaryTreeNode* root, int key)
{
    if(isEmpty(root))
    {
        return root;
    }
    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data) 
    {
        root->right = deleteNode(root->right, key);
    }
    else 
    {
        if(isEmpty(root->left))
        {
            BinaryTreeNode* temp = root->right;
            free(root);
            return temp;

        } else if(isEmpty(root->right)) {
            BinaryTreeNode* temp = root->left;
            free(root);
            return temp;
        }

        BinaryTreeNode* temp = minValueNode(root->right);
        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}