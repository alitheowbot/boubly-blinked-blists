/*
TODO:

QOL: 

add list_init, list_destroy

add a delete-by-value function

------------
TECHNICAL: 

if the user enters 0 as their first node, the if statement in nodeInsertion overwrites it when making the next node

after u are done inserting, set tail->prev->next = NULL, and then tail = tail->prev

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

int main(void)
{
    node* head = malloc(sizeof(node));
    node* tail = malloc(sizeof(node));

    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;

    head->number = INT_MAX;
    tail->number = 0;


// CONSTRUCTION ZONE ---- DO NOT SPEED

// Update 2/9/2026: i dont know what i meant with converting this code below. I dont see what is the use of it when i have the function nodeInsertion?
//                  Maybe i already converted it but forgot to delete this comment.

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




// END CONSTRUCTION ZONE

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