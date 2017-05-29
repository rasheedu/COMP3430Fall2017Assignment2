

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node create_node(int data, Node next) {
    Node newNode = malloc(sizeof( struct NODE ));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = next;
    }
    return newNode;
}

LinkedList create_linked_list() {
    LinkedList list = malloc(sizeof(struct LINKEDLIST));
    if (list != NULL) {
        list->top = NULL;
        list->size = 0;
    }
    //TODO: Graceful error for NULL
    return list;
}

bool add_item(LinkedList list, int data) {
    bool success = false;
    if ( list != NULL ) {
        Node newNode = create_node(data, list->top);
        if (newNode != NULL) {
            list->top = newNode;
            success = true;
        }
    }
    return success;
}

bool remove_item(LinkedList list, int data) {
    bool success = false;
    if ( list != NULL && list->top != NULL ) {
        Node curr = list->top;
        if (curr->data == data) {
            list->top = curr->next;
            success = true;
            free(curr);
        } else {
            Node prev = curr;
            curr = curr->next;
            while (curr != NULL && ! success ) {
                if (curr->data == data) {
                    prev->next = curr->next;
                    success = true;
                    free(curr);
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
    }
    return success;
}

void print_items(LinkedList list) {
    if (list == NULL)
        return;
    Node curr = list->top;
    while (curr != NULL ) {
        printf(" < %d > | ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}