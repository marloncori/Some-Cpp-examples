#ifndef NODES_H_
#define NODES_H_

struct Node {
    long data;
    struct Node* previous;
};

struct Node* create(long value, struct Node* previous);
void show(struct Node** node);

#endif // nodes.h