#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert_front(struct Node* link, int value);
struct Node* insert_position(struct Node* link, int place, int value);
void remove_node(struct Node* link);
void recursive_reverse(struct Node* link);
void show_data(struct Node* link);
void recursive_show(struct Node* link);

#endif // linkedList.h