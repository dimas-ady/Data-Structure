#include <stdlib.h>
#include "stack.h"

int stack_is_empty(Stack *stack) {
    return (stack->top == NULL);
}

int stack_size(Stack *stack) {
    return stack->size;
}

void stack_push(Stack *stack, int data) {
    StackNode *new_node = malloc(sizeof(StackNode));
    new_node->data = data; 
    if(stack_is_empty(stack))
        stack->top = new_node;
    else {
        new_node->next = stack->top;
        stack->top = new_node;
    } 

    stack->size++;
}

void stack_pop(Stack *stack) {
    StackNode *top = stack->top;
    stack->top = top->next;

    stack->size--;
    free(top);
}

int stack_top(Stack *stack) {
    return stack->top->data;
}
