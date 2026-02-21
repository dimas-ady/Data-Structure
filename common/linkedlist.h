#ifndef LINKEDLIST
#define LINKEDLIST

#define SLIST LinkedList
#define SL linkedList

typedef struct Node Node;

struct Node{
    int data;
    Node *link;
};

typedef struct{
    unsigned int size;
    Node *head;
} LinkedList;

void llist_push_back(SLIST *list, int data);

void llist_push_front(SLIST *list, int data);

void llist_pop_back(SLIST *list);

void llist_pop_front(SLIST *list);

void llist_insert_at(SLIST *list, int data, int pos);

int llist_remove_at(SLIST *list, int data);

int *llist_back(SLIST *list);

int *llist_front(SLIST *list);

int *llist_get_at(SLIST *list, int pos);

int llist_is_empty(SLIST *list);

void llist_free(SLIST *list);


#endif