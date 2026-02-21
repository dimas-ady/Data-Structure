#include <stdlib.h>
#include "dynamic_array.h"

#define INT_SIZE sizeof(int)

void darray_init(DynamicArray *DA) {
    DA->size = 0;
    DA->capacity = 1;
    
    DA->array = malloc(DA->capacity * INT_SIZE);
}

int darray_realloc(DynamicArray *DA) {  
    DA->capacity *= 2;
    DA->array = realloc(DA->array, DA->capacity * INT_SIZE);
}

void darray_push_back(DynamicArray *DA, int data) {
    if(DA->array == NULL)
        darray_init(DA);
    
    if(DA->size > DA->capacity)
        darray_realloc(DA);
    
    DA->array[DA->size] = data;
    DA->size++;
}

void darray_pop_back(DynamicArray *DA) {
    if(DA->size == 0 || DA->array == NULL)
        return;
    else {
        DA->size--;
    }
}

int *darray_front(DynamicArray *DA) {
    if(DA->size > 0)
        return &DA->array[0];
    else
        return NULL;
}

int *darray_back(DynamicArray *DA) {
    if(DA->size > 0)
        return &DA->array[DA->size--];
    else
        return NULL;
}

int *darray_get_at(DynamicArray *DA, int pos) {
    if(pos > DA->size)
        return NULL;
    else
        return &DA->array[pos]; 
}

void darray_set_at(DynamicArray *DA, int pos, int data) {
    if(pos > DA->size)
        return;
    else {
        DA->array[pos] = data;
    }
}

int darray_is_empty(DynamicArray *DA) {
    return DA->size? 1 : 0;
}

void darray_free(DynamicArray *DA) {
    free(DA->array);
}