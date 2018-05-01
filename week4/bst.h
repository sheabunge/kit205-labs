
/**
 * Data type for a node in a binary search tree
 */
typedef struct bstNode {
	int data_item;
	struct bstNode *left;
	struct bstNode *right;
} *BSTNodePtr;

/**
 * Wrapper type for a binary search tree
 */
typedef struct bst {
	BSTNodePtr root;
} BST;


/**
 * Create a new instance of a binary search tree
 * @return empty tree
 */
BST create_bst();

/**
 * Locate specific node in a binary search tree
 * @param self
 * @param n value of node to locate
 * @return
 */
BSTNodePtr find_bst(BST *self, int n);

/**
 * Insert a value in a binary search tree
 * @param self
 * @param n value to insert
 */
void insert_bst(BST *self, int n);

/**
 * Remove a value from a binary search tree
 * @param self tree
 * @param n value to remove
 */
void delete_bst(BST *self, int n);

/**
 * Print a binary search tree using pre-order format
 */
void print_pre_order_bst(BST *tree);

/**
 * Print a binary search tree using in-order format
 */
void print_in_order_bst(BST *tree);

/**
 * Print a binary search tree using post-order format
 */
void print_post_order_bst(BST *tree);

/**
 * Calculate the height of a binary search tree
 * @param self tree
 * @return height of tree
 */
int bst_height(BST *self);