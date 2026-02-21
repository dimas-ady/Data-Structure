#ifndef STACK_H
#define STACK_H

typedef struct StructNode StructNode;

struct StackNode {
    int data;
    StackNode *next;
};

typedef struct {
    int size;
    StackNode *top;
} Stack;

int stack_is_empty(Stack *stack);

int stack_size(Stack *stack);

void stack_push(Stack *stack, int data);

void stack_pop(Stack *stack);

int stack_top(Stack *stack);

#endif