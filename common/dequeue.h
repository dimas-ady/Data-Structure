#ifndef DEQUEUE_H
#define DEQUEUE_H

typedef struct DequeueNode DequeueNode;

struct DequeueNode{
    int data;
    DequeueNode *next, *prev;
};

typedef struct {
    unsigned size;
    DequeueNode *head, *tail;
} Dequeue;

int dequeue_is_empty(Dequeue *dequeue);

void deqeueue_push_front(Dequeue *dequeue, int data);

void deqeueue_push_back(Dequeue *dequeue, int data);

int *dequeue_front(Dequeue *dequeue);

int *dequeue_back(Dequeue *dequeue);

void dequeue_pop_front(Dequeue *dequeue);

void dequeue_pop_back(Dequeue *dequeue);

#endif