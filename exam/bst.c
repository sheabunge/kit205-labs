#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Print a visual representation of a binary search tree node and its children
 * @param self node to print
 * @param indent indent level
 */
void print_bst_node(BSTNodePtr self, int indent) {
	if (self == NULL) {
		return;
	}

	print_bst_node(self->right, indent + 4);

	for (int i = 0; i < indent; i++) {
		printf(" ");
	}

	printf("%d\n", self->data);

	print_bst_node(self->left, indent + 4);
}

/**
 * Print a visual representation of a binary search tree
 * @param self node to print
 */
void print_bst(BST *self) {
	print_bst_node(self->root, 0);
}

BSTNodePtr create_bst_node(int value) {
	BSTNodePtr node = malloc(sizeof *node);

	node->right = node->left = NULL;
	node->data = value;

	return node;
}
