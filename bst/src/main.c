
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bstCleanup(void){
    char* line = "\033[1;32m\n\t========================================\n\033[0m";
    printf("%s", line);
    fflush(stdout);
    printf("\033[1;33m\t Program has successfully ended.\n\033[03m");
    printf("%s", line);
    fflush(stdout);
    exit(0);
}

void bstOperations(struct Node* treeNode, int option){
    int count = 0;
    int number = 0; 
    int counter = 0;
    char found = 'F';
   
    switch(option){
        case 1:
            printf("\033[1;35m\n\t Enter the new value for insertion.\n\033[0m");
            printf("\033[1;36m\t\t  new node --> \033[0m");
            fflush(stdout);
            scanf_s("%d\n", &number);
            insertNode(treeNode, number);
            break;
        case 2:
            printf("\033[1;34m\n\t See below your created binary tree.\n\033[0m");
            showNodes(treeNode, count+1);
            break;
        /*case 3:
            printf("\033[1;33m\n\t Enter the element you want\n\t to search in the binary tree.\n\033[0m");
            printf("\033[1;32m\t\t Query: \033[0m");
            scanf_s("%d\n", &number);
            switch(counter){
                case 1:
                    found = searchNode(treeNode, number);
                    break;
                case 2:
                    found = searchNode(node, number);
                    break;
                case 3:
                    found = searchNode(nextNode, number);
                    break;
                case 4:
                    found = searchNode(thirdNode, number);
                    break;
                case 5:
                    found = searchNode(fourth, number);
                    break;
                case 6:
                    found = searchNode(fifthNode, number);
                    break;
                case 7:
                    found = searchNode(sixthNode, number);
                    break;
                default:
                    printf("\n There is nothing to be searched.\n");
                    break;
            }
            if(found){
                printf("\033[1;34m\t\t Searched element \033[0m\033[1;31m\'" << number << "\'\033[0m\033[1;35mhas been found in the binary tree.\n\033[0m");
            }
            else{
                printf("\033[1;34m\t\t Searched element \033[0m\033[1;31m\'" << number << "\'\033[0m\033[1;35mhas not been found in the binary tree.\n\033[0m");
            }
            break;*/
        case 3:
            break;
    }
}

void bstHeader(void){
	printf("\n");
	printf("\033[1;36m\t    ---------------------------------\n\033[0m");
	printf("\033[1;35m\t    |  ~~  BINARY  SEARCH  TREE  ~~ |\n\033[0m");
    fflush(stdout);
	printf("\033[1;36m\t    ---------------------------------\n\033[0m");
}

int bstMenu(void){
    int opt = 0;
 	printf("\n");
 	printf("\033[1;35m\t ---------------------------------\n\033[0m");
    fflush(stdout); 
	printf("\033[1;34m\t |  Select one option from menu: |\n\033[0m");
	printf("\033[1;35m\t ---------------------------------\n\033[0m");
 	printf("\n");
     fflush(stdout);
	printf("\033[1;33m\t\t 1. Insert new node\n\033[0m");
	printf("\033[1;33m\t\t 2. Show all nodes\n\033[0m");
    fflush(stdout);
    printf("\033[1;33m\t\t 3. Look for a node\n\033[0m");
	printf("\033[1;33m\t\t 4. Exit application\n\033[0m");
    fflush(stdout);
	printf("\n");
	printf("\033[1;32m\t >>> Your option --> \033[0m");
    fflush(stdout);
    scanf_s("%d", &opt);
  return opt;
}

int main(void){
    int value = 15;
    struct Node* newNode = createNode(value);
  
    bstHeader();
    int option = bstMenu();
 
    while(option != 3){
        bstOperations(newNode, option);

        bstHeader();
        option = bstMenu();
    }
    if(option == 3){
        bstCleanup();
    }
 
    free(newNode);
  return 0;
}