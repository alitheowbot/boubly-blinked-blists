/*
TODO:

QOL: 

add list_destroy

add a delete-by-value function

------------
TECHNICAL: 

malloc fail check 

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* next;
    struct node* prev;
} node;

void nodeInsertion(node* head, node* tail, int value) {
    

    if (head->number == INT_MAX) {
        head->number = value;
    }
    else {
        node* n = malloc(sizeof(node));


        n->number = value;
        n->next = tail;
        n->prev = tail->prev;
        tail->prev->next = n;
        tail->prev = n;
    }
}

void nodeInitialization(node* head, node* tail) {
    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;

    head->number = INT_MAX;
    tail->number = 0;
}

int main(void)
{
    // Initializing our first list of nodes
    node* head = malloc(sizeof(node));
    node* tail = malloc(sizeof(node));
    nodeInitialization(head, tail);


    printf("Enter value: ");
    int value = 0;
    int ask = scanf("%d", &value);

    nodeInsertion(head, tail, value);

    while (value != -1) {
        printf("Enter value: ");
        value = 0;
        ask = scanf("%d", &value);

        if (value != -1)
            nodeInsertion(head, tail, value);
    }

    tail->prev->next = NULL;
    free(tail);
    tail = tail->prev;

    // Prints from head
    for (node* ptr = head; ptr != NULL; ptr = ptr->next) {
        printf("%i\n", ptr->number);
    }

    printf("REVERSE REVERSE!\n");

    // Prints from tail
    for (node* ptr = tail; ptr != NULL; ptr = ptr->prev) {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node* ptr = head;
    while (ptr != NULL) {
        node* tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }

    return 0;
}