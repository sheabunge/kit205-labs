#include <stdlib.h>
#include <stdio.h>
#include "bst.h"


/**
 * Create a new instance of a binary search tree
 * @return empty tree
 */
BST create_bst() {
	BST tree;
	tree.root = NULL;
	return tree;
}

/**
 * Locate specific node in a binary search tree
 * @param self
 * @param n value of node to locate
 * @return
 */
BSTNodePtr find_bst_node(BSTNodePtr self, int n) {

	if (self == NULL || n == self->data_item) {
		return self;
	}

	if (n < self->data_item) {
		return find_bst_node(self->left, n);
	}
	return find_bst_node(self->right, n);
}

/**
 * Locate specific node in a binary search tree
 * @param self
 * @param n value of node to locate
 * @return
 */
BSTNodePtr find_bst(BST *self, int n) {
	return find_bst_node(self->root, n);
}

/**
 * Insert a new node into a binary search tree
 * @param self tree
 * @param n value to insert
 * @return modified tree
 */
BSTNodePtr insert_bst_node(BSTNodePtr self, int n) {
	/* check if found location, then insert */
	if (self == NULL) {
		self = malloc(sizeof *self);
		self->data_item = n;
		self->left = self->right = NULL;

	} else if (n < self->data_item) {
		self->left = insert_bst_node(self->left, n);
	} else if (n > self->data_item) {
		self->right = insert_bst_node(self->right, n);
	}

	return self;
}

/**
 * Insert a value in a binary search tree
 * @param self
 * @param n value to insert
 */
void insert_bst(BST *self, int n) {
	self->root = insert_bst_node(self->root, n);
}

/**
 * Find the minimum node in a given branch
 * @param self
 * @return
 */
BSTNodePtr min_node(BSTNodePtr self) {
	BSTNodePtr current = self;
	// while there is a left branch
	while (current->left != NULL) {
		// move down the branch
		current = current->left;
	}
	return current;
}

/**
 * Remove a node from a binary search tree
 * @param self tree
 * @param n value to remove
 * @return modified tree
 */
BSTNodePtr delete_bst_node(BSTNodePtr self, int n) {
	if (self != NULL) {
		if (self->data_item == n) {
			if (self->left != NULL && self->right != NULL) {
				BSTNodePtr successor = min_node(self->right);
				self->data_item = successor->data_item;
				self->right = delete_bst_node(self->right, self->data_item);

			} else {
				BSTNodePtr to_free = self;
				self = self->left ? self->left : self->right;
				free(to_free);
			}
		} else if (n < self->data_item) {
			self->left = delete_bst_node(self->left, n);
		} else {
			self->right = delete_bst_node(self->right, n);
		}
	}
	return self;
}

/**
 * Remove a value from a binary search tree
 * @param self tree
 * @param n value to remove
 */
void delete_bst(BST *self, int n) {
	self->root = delete_bst_node(self->root, n);
}

enum bst_order {PRE_ORDER, IN_ORDER, POST_ORDER};

/**
 * Print a binary search tree node in an ordered format
 */
void print_order_bst_node(BSTNodePtr self, enum bst_order order) {

	if (self == NULL) {
		printf("_");
	} else {
		printf("(");

		if (order == POST_ORDER || order == IN_ORDER) {
			print_order_bst_node(self->left, order);
		}

		if (order == POST_ORDER) {
			print_order_bst_node(self->right, order);
		}

		printf(" %d ", self->data_item);


		if (order == PRE_ORDER) {
			print_order_bst_node(self->left, order);
		}

		if (order == PRE_ORDER || order == IN_ORDER) {
			print_order_bst_node(self->right, order);
		}

		printf(")");
	}
}

/**
 * Print a binary search tree using pre-order format
 */
void print_pre_order_bst(BST *self) {
	print_order_bst_node(self->root, PRE_ORDER);
}

/**
 * Print a binary search tree using in-order format
 */
void print_in_order_bst(BST *self) {
	print_order_bst_node(self->root, IN_ORDER);
}

/**
 * Print a binary search tree using post-order format
 */
void print_post_order_bst(BST *self) {
	print_order_bst_node(self->root, POST_ORDER);
}

/**
 * Calculate the height of a binary search tree node
 * @param self
 * @return
 */
int bst_node_height(BSTNodePtr self) {

	if (self == NULL) {
		return 0;
	}

	int left_height = bst_node_height(self->left);
	int right_height = bst_node_height(self->right);

	return 1 + (left_height > right_height ? left_height : right_height);
}

/**
 * Calculate the height of a binary search tree
 * @param self tree
 * @return height of tree
 */
int bst_height(BST *self) {
	return bst_node_height(self->root);
}