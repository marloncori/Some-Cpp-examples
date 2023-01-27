#include <stdio.h>
#include "nodes.h"

int main(){
    struct Node* first = create(2023, NULL);
    struct Node* second = create(1789, first);
    struct Node* third = create(2145, second);
    struct Node* fourth = create(1056, third);

    show(&fourth);

    free(fourth);
    return 0;
}