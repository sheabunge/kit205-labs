
/**
 * Data type for a node in a binary search tree
 */
typedef struct bstNode {
	int data;
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
 * Print a visual representation of a binary search tree
 * @param self node to print
 */
void print_bst(BST *self);

BSTNodePtr create_bst_node(int value);
