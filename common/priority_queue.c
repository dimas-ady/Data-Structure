#include <stdlib.h>
#include "priority_queue.h"

int pqueue_is_empty(PriorityQueue *pqueue) {
    return pqueue->top == NULL;
}

void pqueue_push(PriorityQueue *pqueue, int data) {
    PQueueNode *new_node = malloc(sizeof(PQueueNode));
    new_node->data = data;

    if(pqueue_is_empty(pqueue)) {
        pqueue->size = 0;
        pqueue->top = new_node;
    } else {
        PQueueNode *temp_node = pqueue->top;
        if(new_node->data < temp_node->data) {
            new_node->next = temp_node;
            pqueue->top = new_node;
        } else {
            while(temp_node->next != NULL && 
                temp_node->next->data > new_node->data) {
                    temp_node = temp_node->next;
            }
            new_node->next = temp_node->next;
            temp_node->next = new_node;   
        }
    }
    pqueue->size++;
}

void pqueue_pop(PriorityQueue *pqueue) {
    PQueueNode *top = pqueue->top;
    pqueue->top = top->next;
    free(top);
    pqueue->size--;
}

int *pqueue_top(PriorityQueue *pqueue) {
    return &(pqueue->top->data);
}
