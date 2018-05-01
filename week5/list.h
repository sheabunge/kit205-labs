#pragma once

//typedef char *String;

/**
 * Linked list node
 */
typedef struct listNode {
	char *data;
	struct listNode *next;
} *ListNodePtr;

/**
 * Linked list
 */
typedef struct list {
	ListNodePtr head;
} List;

/**
 * Print the contents of a list
 * @param self
 */
void print_list(List *self);

/**
 * Insert a new element at the front of a list
 * @param self
 * @param data
 */
void insert_at_front(List *self, char *data);

/**
 * Remove an element from a list
 * @param self
 * @param data
 */
void delete_list_item(List *self, char *data);

/**
 * Remove an entire list
 * @param self
 */
void destroy_list(List *self);
