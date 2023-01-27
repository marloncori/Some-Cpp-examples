#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <cstdlib>

namespace algorithm {
   class BinaryTree {
       private:
          int key;
          algorithm::BinaryTree* rightNode;
          algorithm::BinaryTree* leftNode;
          algorithm::BinaryTree* parentNode;

       public:         
          algorithm::BinaryTree* insert(algorithm::BinaryTree* node, int key);
          bool isEmpty() const;

          void preOrder(algorithm::BinaryTree* node);
          algorithm::BinaryTree* search(algorithm::BinaryTree* node, int key);
          
          int findMin(algorithm::BinaryTree* node);
          int findMax(algorithm::BinaryTree* node);          
          int successor(algorithm::BinaryTree* node);
          int predecessor(algorithm::BinaryTree* node);
          
          algorithm::BinaryTree* remove(algorithm::BinaryTree* node, int key); 
   };
}

#endif // BinaryTree.h