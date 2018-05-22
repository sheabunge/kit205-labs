/* Skip Lists: A Probabilistic Alternative to Balanced Trees */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define SKIPLIST_MAX_LEVEL 6

typedef struct skipnode {
	int data;
	struct skipnode **next;
} *SkipNodePtr;

typedef struct skiplist {
	int level;
	SkipNodePtr header;
} Skiplist;


Skiplist create_skiplist();

void skiplist_insert(Skiplist *self, int data);

SkipNodePtr skiplist_find(Skiplist *self, int data);

void skiplist_print(Skiplist *self);

void skiplist_delete(Skiplist *self, int data);

