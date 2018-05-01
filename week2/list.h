

typedef struct listNode {
    int data;
    struct listNode *next;
} *ListNodePtr;

typedef struct list {
    ListNodePtr head;
} List;


/**
 * Create a new instance of the List type
 * @return an empty list
 */
List create_list();

/**
 * Traverse a list and print its items to the screen
 * @param self
 */
void print_list(List *self);

/**
 * Insert a new element at the front of a list
 * @param self
 * @param data
 */
void insert_at_front(List *self, int data);

/**
 * Insert a new element in an ordered list
 * @param self
 * @param data
 */
void insert_in_order(List *self, int data);

/**
 * Delete an item from a list
 * @param self
 * @param data
 */
void delete_list(List *self, int data);

/**
 * Delete all items in a list
 * @param self
 */
void destroy_list(List *self);

/**
 * Reverse the order of elements in a list
 * @param self
 * @return reversed list
 */
List reverse_list(List *self);

/**
 * Merge two ordered lists into a single ordered list
 * @param self
 * @param other
 * @return merged list
 */
List merge_lists(List *self, List *other);