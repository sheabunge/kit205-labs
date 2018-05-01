
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"


/**
 * Create a new instance of the List type
 * @return an empty list
 */
List create_list() {
    List temp;
    temp.head = NULL;
    return temp;
}

/**
 * Traverse a list and print its items to the screen
 * @param self
 */
void print_list(List *self) {
    ListNodePtr current = self->head;

    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;

        if (current != NULL) {
            printf(", ");
        }
    }

    printf("\n");
}

/**
 * Insert a new element at the front of a list
 * @param self
 * @param data
 */
void insert_at_front(List *self, int data) {
    ListNodePtr node = malloc(sizeof *node);

    node->data = data;
    node->next = self->head;

    self->head = node;
}

/**
 * Insert a new element in an ordered list
 * @param self
 * @param data
 */
void insert_in_order(List *self, int data) {
    ListNodePtr current = self->head;
    ListNodePtr prev = NULL;

    ListNodePtr node = malloc(sizeof *node);
    node->data = data;
    node->next = NULL;

    while (current != NULL && current->data < data) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) { // inserting at front
        node->next = current;
        self->head = node;
    } else {
        node->next = current;
        prev->next = node;
    }
}

/**
 * Delete an item from a list
 * @param self
 * @param data
 */
void delete_list(List *self, int data) {
    ListNodePtr current = self->head;
    ListNodePtr prev = NULL;

    while (current != NULL) {

        /* check if we have found matching data */
        if (current->data == data) {

            /* check if at front of list */
            if (prev == NULL) {
                self->head = current->next;
                free(current);
                current = self->head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }

        } else {
            /* continue searching */
            prev = current;
            current = current->next;
        }
    }
}

/**
 * Delete all items in a list
 * @param self
 */
void destroy_list(List *self) {
    ListNodePtr current = self->head;

    /* traverse entire list */
    while (current != NULL) {
        ListNodePtr to_free = current;
        current = current->next;
        free(to_free);
    }

    /* reset the head of the list as the head node has been deleted */
    self->head = NULL;
}

/**
 * Reverse the order of elements in a list
 * @param self
 * @return reversed list
 */
List reverse_list(List *self) {
    List reverse = create_list();
    ListNodePtr current = self->head;

    while (current != NULL) {
        insert_at_front(&reverse, current->data);
        current = current->next;
    }

    return reverse;
}

/**
 * Merge two ordered lists into a single ordered list
 * @param self
 * @param other
 * @return merged list
 */
List merge_lists(List *self, List *other) {
    List result = create_list();

    /* copy elements from the first list into the new one */
    ListNodePtr current, clone, prev = NULL;

    ListNodePtr node_a = self->head;
    ListNodePtr node_b = other->head;
    bool merging_a; // used for keeping track of which list we are currently merging

    /* continue looping there are unvisited nodes in at least one list */
    while (node_a != NULL || node_b != NULL) {

        /* identify the node with the lower data */
        if (node_a == NULL) {
            merging_a = false;

        } else if (node_b == NULL) {
            merging_a = true;

        } else {
            merging_a = node_a->data < node_b->data;
        }

        current = merging_a ? node_a : node_b;

        /* create a new node to house the chosen data */
        clone = malloc(sizeof *clone);
        clone->data = current->data;
        clone->next = NULL;

        /* if this is the first node, set it as the head of the new list */
        if (prev == NULL) {
            result.head = clone;
        } else {
            /* otherwise, add this node to the existing chain */
            prev->next = clone;
        }

        prev = clone;

        /* advance the relevant current pointer */
        if (merging_a) {
            node_a = node_a->next;
        } else {
            node_b = node_b->next;
        }
    }

    return result;
}

List merge(List* list_a, List* list_b){
    List merged = create_list(); // result

    ListNodePtr tail = NULL; // tail points to the last result node
    ListNodePtr curr_a = list_a->head;
    ListNodePtr curr_b = list_b->head;

    if (curr_a == NULL) { // nothing to merge in a
        merged.head = curr_b;
        return merged;
    }
    if (curr_b == NULL) { // nothing to merge in b
        merged.head = curr_a;
        return merged;
    }

    if (curr_a->data <= curr_b->data) { // get started with first node
        merged.head = curr_a;
        tail = curr_a;
        curr_a = curr_a->next;
    } else {
        merged.head = curr_b;
        tail = curr_b;
        curr_b = curr_b->next;
    }

    while (curr_a !=NULL && curr_b !=NULL) {
        if (curr_a->data <= curr_b->data) {
            tail->next = curr_a;
            tail = curr_a;
            curr_a = curr_a->next;
        } else {
            tail->next = curr_b;
            tail = curr_b;
            curr_b = curr_b->next;
        }
    }

    if (curr_a == NULL) {
        tail->next = curr_b;
    } else {
        tail->next = curr_a;
    }
    return merged;
}
