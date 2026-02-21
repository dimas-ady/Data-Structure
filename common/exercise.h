#ifndef EXERCISE_H
#define EXERCISE_H

#include <stdio.h>
#include "dynamic_array.h"
#include "linkedlist.h"

void print_element(int *data) {
    printf("%d\n", *data);
}

static inline void for_each_element(LinkedList *list, void (*f)(int *)) {
    Node *node;
    for(int i = 0; i < list->size; i++) {
        if(i == 0)
            node = list->head;
        else
            node = node->link;
        f(&(node->data));
    }
}

#endif