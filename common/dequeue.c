#include <stdlib.h>
#include "dequeue.h"

int dequeue_is_empty(Dequeue *dequeue) {
    return (dequeue->head == NULL && dequeue->tail == NULL);
}

void deqeueue_push_front(Dequeue *dequeue, int data) {
    DequeueNode *new_node = malloc(sizeof(DequeueNode));
    new_node->data = data;

    if(dequeue_is_empty(dequeue)) {
        dequeue->size = 0;
        dequeue->head = new_node;
        dequeue->tail = new_node;
    } else {
        new_node->next = dequeue->head;
        dequeue->head->prev = new_node;
        dequeue->head = new_node;
    }
    dequeue->size++;
}

void deqeueue_push_back(Dequeue *dequeue, int data) {
    DequeueNode *new_node = malloc(sizeof(DequeueNode));
    new_node->data = data;

    if(dequeue_is_empty(dequeue)) {
        dequeue->size = 0;
        dequeue->head = new_node;
        dequeue->tail = new_node;
    } else {
        new_node->prev = dequeue->tail;
        dequeue->tail->next = new_node;
        dequeue->tail = new_node;
    }
    dequeue->size++;
}

int *dequeue_front(Dequeue *dequeue) {
    if(!dequeue_is_empty(dequeue))
        return &dequeue->head->data;
    else
        return NULL;
}

int *dequeue_back(Dequeue *dequeue) {
    if(!dequeue_is_empty(dequeue))
        return &dequeue->tail->data;
    else
        return NULL;

}

void dequeue_pop_front(Dequeue *dequeue) {
    DequeueNode *front = dequeue->head;
    dequeue->head = front->next;
    if(dequeue->head != NULL)
        dequeue->head->prev = NULL;

    free(front);
    dequeue->size--;

    if(dequeue->head == NULL) {
        dequeue->tail = NULL;
        dequeue->size = 0;
    }
}

void dequeue_pop_back(Dequeue *dequeue) {
    DequeueNode *back = dequeue->tail;
    dequeue->tail = back->prev;
    if(dequeue->tail != NULL)
        dequeue->tail->next = NULL;

    free(back);
    dequeue->size--;

    if(dequeue->tail == NULL) {
        dequeue->head = NULL;
        dequeue->size = 0;
    }

}
