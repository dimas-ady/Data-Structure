#include <stdlib.h>
#include "queue.h"

int queue_is_empty(Queue *queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

int queue_size(Queue *queue) {
    return queue->size;
}

void queue_push(Queue *queue, int data) {
    QueueNode *new_node = malloc(sizeof(QueueNode));
    new_node->data = data;

    if(queue_is_empty(queue)) {
        queue->size = 0;
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

void queue_pop(Queue *queue) {
    if(!queue_is_empty(queue)) {
        QueueNode *front = queue->front;
        queue->front = front->next;
        free(front);
    }
    if(queue->front == NULL)
        queue->rear = NULL;
    queue->size--;
}

int queue_front(Queue *queue) {
    return queue->front;
}
