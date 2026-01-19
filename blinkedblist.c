/*
TODO:

Wrap this into list_init, list_insert, list_destroy

Add a delete-by-value function

------------
if the user enters 0 as their first node, the if statement in nodeInsertion overwrites it when making the next node

after u are done inserting, set tail->prev->next = NULL, and then tail = tail->prev


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* next;
    struct node* prev;
} node;

void nodeInsertion(node* head, node* tail, int value) {
    

    if (head->number == 0) {
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

int main(void)
{
    node* head = malloc(sizeof(node));
    node* tail = malloc(sizeof(node));

    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;

    head->number = 0;
    tail->number = 0;

// CONSTRUCTION ZONE ---- DO NOT SPEED
// TODO: 
// Convert this code to be dynamic, rather than static.
/*
    for (int i = 0; i < 3; i++) {
        if (head->number == INT_MAX) {
            head->number = i;
        }
        else if (i == 2) {
            tail->number = i;
        }
        else {
            
        }
}*/
    

    //TODO:
    //Make this keep going until the user is all done
    printf("Enter value: ");
    int value = 0;
    int ask = scanf("%d", &value);

    nodeInsertion(head, tail, value);

    printf("Enter value: ");
    value = 0;
    ask = scanf("%d", &value);

    nodeInsertion(head, tail, value);

    printf("Enter value: ");
    value = 0;
    ask = scanf("%d", &value);

    nodeInsertion(head, tail, value);

    printf("Enter value: ");
    value = 0;
    ask = scanf("%d", &value);

    nodeInsertion(head, tail, value);

    // -----

    tail->prev->next = NULL;
    free(tail);
    tail = tail->prev;


// END WORK ZONE


    for (node* ptr = head; ptr != NULL; ptr = ptr->next) {
        printf("%i\n", ptr->number);
    }

    printf("REVERSE REVERSE!\n");

    for (node* ptr = tail; ptr != NULL; ptr = ptr->prev) {
        printf("%i\n", ptr->number);
    }

    node* ptr = head;
    while (ptr != NULL) {
        node* tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }

    return 0;
}