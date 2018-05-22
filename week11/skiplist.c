#include "skiplist.h"

Skiplist create_skiplist() {
	Skiplist list;

	list.header = malloc(sizeof *list.header);
	list.header->data = 0;
	list.header->next = malloc(SKIPLIST_MAX_LEVEL * sizeof *list.header->next);

	for (int i = 0; i < SKIPLIST_MAX_LEVEL; i++) {
		list.header->next[i] = NULL;
	}

	list.level = SKIPLIST_MAX_LEVEL - 1;

	return list;
}

int rand_level() {
	int level = 1;

	while (rand() < RAND_MAX / 2 && level < SKIPLIST_MAX_LEVEL) {
		level++;
	}

	return level;
}

void skiplist_insert(Skiplist *self, int data) {
	int level = rand_level();


}

void skiplist_print(Skiplist *self) {
	SkipNodePtr current = self->header->next[0];

	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next[0];
	}

	printf("\n");
}


SkipNodePtr skiplist_find(Skiplist *self, int data) {
	SkipNodePtr current = self->header;

	for (int i = self->level; i >= 0; i--) {
		while (current->next[i] != NULL && current->next[i]->data != data) {
			current = current->next[i];
		}
	}

	return current->next[0];
}

void skiplist_delete(Skiplist *self, int data) {
	// TODO
}

