#include <stdio.h>

#include "common/linkedlist.h"

int main() {
    LinkedList list;

    for(int i = 0; i < 5; i++) {
        llist_push_back(&list, i);
    }

    llist_insert_at(&list, 100, 4);

    for(int i  = 0; i < list.size; i++) {
        Node *temp;
        if(temp == NULL)
            temp = list.head;
        else
            temp = temp->link;
        printf("i: %d is %d\n", i, temp->data);
    }

    return 0;
}