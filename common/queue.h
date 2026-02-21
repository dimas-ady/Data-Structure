#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode QueueNode;

struct QueueNode {
    int data;
    QueueNode *next;
};

typedef struct {
    QueueNode *front, *rear;
    unsigned int size;
} Queue;

int queue_is_empty(Queue *queue);

int queue_size(Queue *queue);

void queue_push(Queue *queue, int data);

void queue_pop(Queue *queue);

int queue_front(Queue *queue);

#endif