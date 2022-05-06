
#include <iostream>
#include <array>

#include "binary_tree.h"

int main()
{
  struct BinaryTreeNode* root {nullptr};
  std::array<int, 8> values {{40, 30, 60, 55, 70, 25, 80, 10}};

  root = newNode(5);  
  for(auto& num : values)
  {
     root = insert(root, num); 
  }

  std::cout << " Binary Search Tree created\n\t(Inorder traversal): " << std::endl;
  inOrder(root);
  
  std::cout << "  Delete node no. 60 " <<std::endl;
  root = deleteNode(root, 60);

  std::cout << "  Inorder traversal for the modified\n\tBinary Search Tree:" <<std::endl;
  inOrder(root);
  
  return 0;
}