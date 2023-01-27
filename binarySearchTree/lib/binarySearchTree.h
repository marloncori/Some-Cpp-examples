#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
    private:
        Node* node;
        int rootValue;
    public:
        BinaryTree() = default;
        Node* createNode(int value);
        void insertNode(Node* newNode, int value);
        Node* getNode() const;
        bool searchNode(Node* node, int query);
};

#endif // binarySearchTree.h