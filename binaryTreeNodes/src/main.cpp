#include <iostream>
#include <random>

#include "binaryTreeNodes.h"

constexpr int MIN = 1;
constexpr int MAX = 10000;

int main()
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distr(MIN, MAX);

    auto root = new binaryTreeNodes(distr(eng));
    auto temp = root;

    auto iter = 100;
    while(iter > 0 )
    {
        auto val = distr(eng);
        if(val % 5 == 0)
        {
            temp->left = new binaryTreeNodes(distr(eng));
            temp = temp->left;
        } else if(val % 4 == 0){
            temp->right = new binaryTreeNodes(distr(eng));
            temp = temp->right;
        } else if(val % 6 == 0){
            temp->left = new binaryTreeNodes(distr(eng));
        } else if(val % 100 == 0){
            temp = root;
        } else if(val % 2 == 0){
            temp->right = new binaryTreeNodes(distr(eng));
        }
        iter -= 1;
    }
    std::cout << " >>> Size of binary tree: " << treeSize(root) << std::endl;
    std::cout << " >>> Height of binary tree: " << treeHeight(root) << std::endl;

    showTree(root);

    std::cin.get();   
    return EXIT_SUCCESS;
}