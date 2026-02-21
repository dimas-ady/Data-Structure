#include <stdlib.h>
#include "linkedlist.h"

void llish_init(SLIST *list, int data) {
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;
    list->head = temp;
    list->size++;
}

void llist_push_back(SLIST *list, int data) {
    if(llist_is_empty(list))
        llish_init(list, data);
    else {
        Node *node = list->head;
        while(node->link != NULL) {
            node = node->link;
        }
        if(node->link == NULL) {
            Node *temp = malloc(sizeof(Node));
            temp->data = data;
            temp->link = NULL;
            node->link = temp;
        }
        list->size++;
    }
}

void llist_push_front(SLIST *list, int data) {
    if(llist_is_empty(list)) {
        llish_init(list, data);
        return;
    }
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->link = list->head;
    list->head = new;
    list->size++;
}

void llist_pop_back(SLIST *list) {
    if(list->head == NULL) {
        list->size = 0;
        return;
    }
    else {
        Node *node = list->head;
        Node *prevNode;
        while(node->link != NULL) {
            prevNode = node;
            node = node->link;
        }
        if(node->link == NULL)
            prevNode->link = NULL;
        list->size--;
    }
}

void llist_pop_front(SLIST *list) {
    if(list->head == NULL) {
        list->size = 0;
        return;
    } else {
        Node *front = list->head;
        list->head = front->link;

        free(front);
    }
    list->size--;
}

void llist_insert_at(SLIST *list, int data, int pos) {
    if(pos > list->size)
        return;
    else {
        if(pos == 0) {
            llist_push_front(list, data);
        } else if (pos == list->size - 1) {
            llist_push_back(list, data);
        } else {
            Node *new = malloc(sizeof(Node));
            new->data = data;
            Node *temp = list->head;
            for(int i = 0; i < pos - 1; i++) {
                temp = temp->link;
            }
            new->link = temp->link;
            temp->link = new;
            list->size++;
        }
    }
}

int llist_remove_at(SLIST *list, int data) {
    Node *prevNode;
    Node *nextNode;
    Node *temp = list->head; 
    for(int i = 0; i < list->size; i++) {
        prevNode = temp;
        temp = temp->link;
        nextNode = temp->link;
        if(temp->data == data) {
            prevNode->link = nextNode;
            free(temp);
            list->size--;
            return 1;
        }
    }
    return 0;
}

int *llist_back(SLIST *list) {
    Node *temp = list->head;
    for(int i = 0; i < list->size; i++) {
        temp = temp->link;
    }
    return &temp->data;
}

int *llsit_front(SLIST *list) {
    return &list->head->data;
}

int *llist_get_at(SLIST *list, int pos) {
    Node *temp = list->head;
    for(int i = 0; i < pos; i++)
        temp = temp->link;
    return &temp->data;
}

int llist_is_empty(SLIST *list) {
    return (list->size < 1);
}

void llist_free(SLIST *list) {
    Node *prev;
    Node *temp = list->head;
    for(int i = 0; i < list->size; i++) {
        prev = temp;
        temp = temp->link;
        free(prev);
    }
}