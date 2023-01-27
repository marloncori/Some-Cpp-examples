#include <iostream>
#include <array>
#include <vector>

#include "BinaryTree.h"
using namespace algorithm;

int main(){
   BinaryTree* root { new BinaryTree() };
    root = NULL;

   std::vector<BinaryTree*> nodes;
   std::array<int, 7> leaves {{15, 10, 20, 25, 8, 12, 5}};

   for(size_t i{0}; i<leaves.size(); ++i){
     nodes.push_back(root->insert(root, leaves[i]));
   }

   for(auto& node : nodes) {
       node->preOrder(node);
   }

   auto result = root->search(root, leaves.at(2));     
   auto minimum = root->findMin(root);
   auto maximum = root->findMax(root);

   std::cout << " Search result " << *result << std::endl;
   std::cout << " Minimum: " << *minimum << std::endl;
   std::cout << " Maximum: " << *maximum << std::endl;
   
   root->preOrder(
       root->remove(root, leaves.at(5)
       )
   );

   std::cin.get();
   return 0;
}