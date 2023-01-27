#ifndef BST_H_
#define BST_H_

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value);
void insertNode(struct Node* node, int value);
void showNodes(struct Node* node, int count);

#endif // bst.h