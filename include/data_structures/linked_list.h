#ifndef OS_2_PROJECT_LINKED_LIST_H
#define OS_2_PROJECT_LINKED_LIST_H

typedef struct{
    int data;
    struct Node* next;
} Node;

typedef struct{
    Node* head;
} LinkedList;


void ll_insert(LinkedList* list, int data);

void ll_print(LinkedList* list);

#endif //OS_2_PROJECT_LINKED_LIST_H
