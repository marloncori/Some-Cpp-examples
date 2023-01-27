#include <iostream>
#include <memory>
#include <Windows.h>
#include <conio.h>

#include "binarySearchTree.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	

void showBinaryTree(Node* node, int count){
   if(node == NULL){
       return;
   }
   else{
       showBinaryTree(node->right, count+1);
       for(int i=0; i<count; i++){
           std::cout << "  ";
       }
       std::cout << node->data << std::endl;
       showBinaryTree(node->left, count+1);
   }
}

void cleanup(){
    std::string line("\n\t========================================\n");
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << line << std::endl; 
    SetConsoleTextAttribute(hConsole, 15);

    SetConsoleTextAttribute(hConsole, 12);
    std::cout << "\t Program has successfully ended." << std::endl;
    SetConsoleTextAttribute(hConsole, 15);
            
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << line << std::endl; 
    SetConsoleTextAttribute(hConsole, 15);
}

void operations(std::unique_ptr<BinaryTree> tree, int option){
    int number = 0; 
    Node* node = new Node(); 
    bool found = false;
    
    switch(option){
        case 1:
            std::cout << "\n\t Tell me the value to be added to Node." << std::endl;
            std::cout << "\t\t value --> ";
            std::cin >> number;    
            node = tree->createNode(number);
            break;
        case 2:
            std::cout << "\n\t Enter the new value for insertion." << std::endl;
            std::cout << "\t\t  new node --> ";
            std::cin >> number;
            tree->insertNode(node, number);
            break;
        case 3:
            std::cout << "\n\t See below your created binary tree." << std::endl;
            number = 0;
            showBinaryTree(tree->getNode(), number);
            break;
        case 4:
            std::cout << "\n\t Enter the element you want\n\t to search in the binary tree." << std::endl;
            std::cout << "\t\t Query: ";
            std::cin >> number;
             found = tree->searchNode(tree->getNode(), number);
            if(found){
                SetConsoleTextAttribute(hConsole, 14);
                std::cout << "\t\t Searched element \'" << number << "\' has been found in the binary tree." << std::endl;
                SetConsoleTextAttribute(hConsole, 15);
            }
            else{
                SetConsoleTextAttribute(hConsole, 9);
                std::cout << "\t\t Searched element \'" << number << "\' has not been found in the binary tree." << std::endl;
                SetConsoleTextAttribute(hConsole, 15);
            }
            break;
        case 5:
            break;
    }
}

void header(){
	SetConsoleTextAttribute(hConsole, 13);
	std::cout << std::endl;
	std::cout << "\t    ---------------------------------" << std::endl;
	std::cout << "\t    |  ~~  BINARY  SEARCH  TREE  ~~ |" << std::endl;
	std::cout << "\t    ---------------------------------" << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
}

int menu(){
    int opt = 0;
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << std::endl;
	std::cout << "\t ---------------------------------" << std::endl;
	std::cout << "\t |  Select one option from menu: |" << std::endl;
	std::cout << "\t ---------------------------------" << std::endl;
	std::cout << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "\t\t 1. Create a new node" << std::endl;
	std::cout << "\t\t 2. Insert new node" << std::endl;
	std::cout << "\t\t 3. Show all nodes" << std::endl;
    std::cout << "\t\t 4. Look for a node" << std::endl;
	std::cout << "\t\t 5. Exit application" << std::endl;
	std::cout << std::endl;
	std::cout << "\t >>> Your option --> ";
	std::cin >> opt;
  return opt;
}

int main(){

   header();
   auto option = menu();
   std::unique_ptr<BinaryTree> binaryTree =
       std::make_unique<BinaryTree>(BinaryTree());

   while(option < 5){
     operations(std::move(binaryTree), option);
     SetConsoleTextAttribute(hConsole, 10);
     std::cout << "\t\t Press any key to continue..." << std::endl; 
     SetConsoleTextAttribute(hConsole, 15);
     getch();
     system("cls");
     header();
     option = menu();
   }
   cleanup();

   return 0;
}