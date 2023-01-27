#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

void adorn();
struct Node* create_list(struct Node*, int);
void list_operations(struct Node*, int);
void process_list(struct Node*);

int main(void)
{

    struct Node* head = NULL;
    head = create_list(head, 0);
    show_data(head);
    process_list(head);
        
    struct Node* linked_list = NULL;
    linked_list = create_list(linked_list, 1);
    show_data(linked_list);
    process_list(linked_list);
    
    return 0;
}

void adorn()
{
    printf("\n\t----------------------------------\n");
    printf("\n\t --- L I N K E D  -- L I S T ---\n");
    printf("\n\t----------------------------------\n");
}

struct Node* create_list(struct Node* head, int mode)
{
    int total, data, position;
    adorn();
    printf("\n\t   How many nodes will you create? \n");
    printf("\n\t  Total: ");
    scanf("%d", &total);
    for(int i=0; i<total; i++)
    {
        printf("\n\t\t %d. Enter element: ", (i+1));
        scanf("%d", &data);
        if(mode == 0){
            head = insert_front(head, data);
        } else {
            printf("\n\t\t Tell us where to insert it.\n");
            printf("\n\t\t --> Position: ");
            scanf("%d", &position);
            if(position == 1){
                head = insert_front(head, data);
            } else{
                head = insert_position(head, position, data);
            }
        }
    }
    return head;
}

void list_operations(struct Node* link, int option){
    switch(option){
        case 1:
            remove_node(link);
            break;
        case 2:
            recursive_reverse(link);
            break;
        case 3:
            recursive_show(link);
            break;
        case 4:
            show_data(link);
            break;
        case 5:
            printf("\n\t You have decided to end program.\n");
            break;
        default:
            printf("\n\t >>> INVALID OPTION. Try again! <<< \n");
            process_list(link);
            break;
    }
}

void process_list(struct Node* link){
    int counter = 0;
    int option;

    do{
        counter++;
        printf("\n\t   Which operation would you like to do? \n");
        printf("\n\t    [ 1 ] delete node    [ 2 ] reverse list \n\t    [ 3 ] print resursively  [ 4 ] show data \n\t    [ 5 ] end program");
        printf("\n\t\t  >>> Option: ");
        scanf("%d", &option);
        if(option == 5) {
            printf("\n\n\t Thank you. Goodbye!\n");
            break;        
        }
        list_operations(link, option);
 
    } while( counter < 4);
     adorn();
}