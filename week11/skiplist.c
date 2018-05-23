#include "skiplist.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Create a new node for insertion into a skip list
 * @param data    node data
 * @param levels  number of levels for the node to span
 * @return
 */
SkipNodePtr create_skip_node(int data, int levels) {
	SkipNodePtr node = malloc(sizeof *node);
	node->data = data;

	node->next = malloc(levels * sizeof *node->next);

	for (int i = 0; i < levels; i++) {
		node->next[i] = NULL;
	}

	return node;
}

/**
 * Create a new instance of a skip list
 * @return
 */
Skiplist create_skiplist() {
	Skiplist list;

	list.header = create_skip_node(0, SKIPLIST_MAX_LEVEL);
	list.level = SKIPLIST_MAX_LEVEL - 1;

	return list;
}

/**
 * Generate a random number of levels
 * @return
 */
int rand_level() {
	int level = 1;

	while (rand() < RAND_MAX / 2 && level < SKIPLIST_MAX_LEVEL) {
		level++;
	}

	return level;
}

/**
 * Insert a new value into a skip list
 * @param self
 * @param data
 * @return number of levels used by the new node
 */
int skiplist_insert(Skiplist *self, int data) {
	int levels = rand_level();
	SkipNodePtr node = create_skip_node(data, levels);

	for (int i = levels - 1; i >= 0; i--) {
		SkipNodePtr current = self->header;

		while (current->next[i] != NULL && data > current->next[i]->data) {
			current = current->next[i];
		}

		node->next[i] = current->next[i];
		current->next[i] = node;
	}

	return levels;
}

/**
 * Print all values stored in a skip list
 * @param self
 */
void print_skiplist(Skiplist *self) {
	SkipNodePtr current = self->header->next[0];

	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next[0];
	}

	printf("\n");
}

/**
 * Print a multi-levelled representation of a skip list
 * @param self
 */
void print_skiplist_levels(Skiplist *self) {

	for (int i = self->level; i >= 0; i--) {
		SkipNodePtr current = self->header->next[i];
		SkipNodePtr base = self->header->next[0];

		while (base != NULL) {

			if (current != NULL && base->data == current->data) {
				printf("%d ", current->data);
				current = current->next[i];
			} else {
				printf("- ");
			}

			base = base->next[0];
		}
		printf("\n");
	}
}

/**
 * Find a value in a skip list
 * @param self
 * @param data
 * @return
 */
SkipNodePtr skiplist_find(Skiplist *self, int data) {
	SkipNodePtr current = self->header;

	for (int i = self->level; i >= 0; i--) {
		while (current->next[i] != NULL && current->next[i]->data != data) {
			current = current->next[i];
		}
	}

	return current->next[0];
}

/**
 * Delete a value from a skip list
 * @param self
 * @param data
 */
void skiplist_delete(Skiplist *self, int data) {
	SkipNodePtr target = NULL;

	for (int i = self->level; i >= 0; i--) {
		SkipNodePtr current = self->header;

		while (current->next[i] != NULL && current->next[i]->data != data) {
			current = current->next[i];
		}

		if (current->next[i] != NULL) {
			target = current->next[i];
			current->next[i] = current->next[i]->next[i];
		}
	}

	free(target);
}

/**
 * Free all data occupied by a skip list
 * @param self
 */
void destroy_skiplist(Skiplist *self) {
	SkipNodePtr current = self->header->next[0];
	SkipNodePtr next;

	while (current != NULL) {
		next = current->next[0];

		free(current->next);
		free(current);

		current = next;
	}

	free(self->header->next);
	free(self->header);
	free(self);
}
