#ifndef PQUEUE_H
#define PQUEUE_H

typedef struct PQueueNode PQueueNode;

struct PQueueNode{
    int data;
    PQueueNode *next;
};

typedef struct {
    unsigned int size;
    PQueueNode *top;
} PriorityQueue;

int pqueue_is_empty(PriorityQueue *pqueue);

void pqueue_push(PriorityQueue *pqueue, int data);

void pqueue_pop(PriorityQueue *pqueue);

int *pqueue_top(PriorityQueue *pqueue);

#endif