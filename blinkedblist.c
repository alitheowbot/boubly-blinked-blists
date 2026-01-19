/*
TODO:

Wrap this into list_init, list_insert, list_destroy

Add a delete-by-value function

Remove sentinels and compare designs

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* next;
    struct node* prev;
} node;

int main(void)
{
    node* head = malloc(sizeof(node));
    node* tail = malloc(sizeof(node));

    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;

    for (int i = 0; i < 3; i++) {
        node* n = malloc(sizeof(node));
        n->number = i;
        n->next = tail;
        n->prev = tail->prev;
        tail->prev->next = n;
        tail->prev = n;
    }

    for (node* ptr = head->next; ptr != tail; ptr = ptr->next) {
        if (ptr->next != NULL) {
            if (ptr->prev != NULL) {
                printf("%i\n", ptr->number);
            }
        }
    }

    node* ptr = head;
    while (ptr != NULL) {
        node* tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }

    return 0;
}