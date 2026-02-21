#ifndef DYNAMICARRAY
#define DYNAMICARRAY

#define DA dynamicArray

typedef struct {
    unsigned int size, capacity;
    int *array;
} DynamicArray;

void darray_push_back(DynamicArray *array, int data);

void darray_pop_back(DynamicArray *array);

int *darray_back(DynamicArray *array);

int *darray_front(DynamicArray *array);

int *darray_get_at(DynamicArray *array, int pos);

void darray_set_at(DynamicArray *array, int pos, int value);

int darray_is_empty(DynamicArray *array);

void darray_free_array(DynamicArray *array);

#endif