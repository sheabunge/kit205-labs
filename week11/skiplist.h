/* Skip Lists: A Probabilistic Alternative to Balanced Trees */

#define SKIPLIST_MAX_LEVEL 6

typedef struct skipnode {
	int data;
	struct skipnode **next;
} *SkipNodePtr;

typedef struct skiplist {
	int level;
	SkipNodePtr header;
} Skiplist;


/**
 * Create a new instance of a skip list
 * @return
 */
Skiplist create_skiplist();

/**
 * Insert a new value into a skip list
 * @param self
 * @param data
 * @return number of levels used by the new node
 */
int skiplist_insert(Skiplist *self, int data);

/**
 * Print all values stored in a skip list
 * @param self
 */
void print_skiplist(Skiplist *self);

/**
 * Print a multi-levelled representation of a skip list
 * @param self
 */
void print_skiplist_levels(Skiplist *self);

/**
 * Find a value in a skip list
 * @param self
 * @param data
 * @return
 */
SkipNodePtr skiplist_find(Skiplist *self, int data);

/**
 * Delete a value from a skip list
 * @param self
 * @param data
 */
void skiplist_delete(Skiplist *self, int data);

/**
 * Free all data occupied by a skip list
 * @param self
 */
void destroy_skiplist(Skiplist *self);
