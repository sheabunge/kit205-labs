#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * Print the contents of a list
 * @param self
 */
void print_list(List *self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf("%s", current->data);
		current = current->next;

		if (current != NULL)
			printf(", ");
	}
	printf("\n");
}

/**
 * Insert a new element at the front of a list
 * @param self
 * @param data
 */
void insert_at_front(List *self, char *data) {
	ListNodePtr new_node = malloc(sizeof *new_node);

	new_node->data = malloc((strlen(data) + 1) * sizeof(char)); // -- allocate just enough memory for newNode->data (malloc)
	strcpy(new_node->data, data); // -- copy string from parameter into newNode->data (strcpy)

	new_node->next = self->head;
	self->head = new_node;
}

/**
 * Remove an element from a list
 * @param self
 * @param data
 */
void delete_list_item(List *self, char *data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) {
		if (strcmp(current->data, data) == 0) {
			if (prev == NULL) {        // front of list
				self->head = current->next;
				free(current->data);
				free(current);
				current = self->head;
			} else {                    // middle of list
				prev->next = current->next;
				free(current->data);
				free(current);
				current = prev->next;
			}
		} else {
			prev = current;
			current = current->next;
		}
	}
}

/**
 * Remove an entire list
 * @param self
 */
void destroy_list(List *self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;
		current = current->next;
		free(to_free->data);
		free(to_free);
	}
	self->head = NULL;
}