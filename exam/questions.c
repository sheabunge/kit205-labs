#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "questions.h"

/**
 * Write a function to find the median (middle) value in a sorted linked list of integers.
 * For a list of n integers, the function should return the integer at position (n+1)/2.
 * @param self
 * @return
 */
int median(List *self) {
	ListNodePtr current = self->head;
	ListNodePtr middle = current;

	// return a dummy value if the list is empty
	if (middle == NULL) {
		return -1;
	}

	// loop through the entire list, keeping track of the index
	for (int i = 0; current->next != NULL; i++) {
		current = current->next;

		// if this is an alternate element, advance the middle pointer
		if (i % 2 == 1) {
			middle = middle->next;
		}
	}

	return middle->data;
}

/**
 * Write a function that takes a sorted array and returns a balanced BST.
 * @param a
 * @param n
 * @return
 */
BST array_to_bst_simple(int *a, int n) {
	BST tree;

	tree.root = NULL;

	// base case for recursion
	if (n <= 0) {
		return tree;
	}

	// find middle index of array
	int middle = n / 2;

	// set this as the root of the tree
	tree.root = malloc(sizeof *tree.root);
	tree.root->data = a[middle];

	// construct the left and right subtrees
	BST left_branch = array_to_bst_simple(a, middle);
	BST right_branch = array_to_bst_simple(a + middle + 1, n - middle - 1);

	// make them children of the root
	tree.root->left = left_branch.root;
	tree.root->right = right_branch.root;

	return tree;
}

/**
 * Write a function that takes a sorted array and returns a balanced BST.
 * first and last are indices indicating the sub-section of the array to be inserted
 * @param a
 * @param first
 * @param last
 * @return
 */
BST array_to_bst(int *a, int first, int last) {
	BST tree;
	tree.root = NULL;

	// base case for recursion
	if (first > last) {
		return tree;
	}

	// find the middle element of the list (weigh the tree to the left)
	int middle = (first + last + 1) / 2;

	// set this as the root of the tree
	tree.root = malloc(sizeof *tree.root);
	tree.root->data = a[middle];

	// construct the left and right subtrees from the remaining array parts
	BST left_branch = array_to_bst(a, first, middle - 1);
	BST right_branch = array_to_bst(a, middle + 1, last);

	// set these as the left and right children of the root node
	tree.root->left = left_branch.root;
	tree.root->right = right_branch.root;

	return tree;
}

/**
 * Given an adjacency list representation of a graph, calculate the in-degree of vertex v.
 * @param self
 * @param v
 * @return
 */
int in_degree(Graph *self, int v) {
	int count = 0;

	// loop through every vertex in the graph
	for (int i = 0; i < self->V; i++) {
		EdgeNodePtr current = self->edges[i].head;

		// check all edges of each vertex
		while (current != NULL) {

			// if the edge leads to the needle vertex, then increment the count
			if (current->edge.to_vertex == v) {
				count++;
			}

			current = current->next;
		}
	}

	return count;
}

/**
 * Given an adjacency list representation of a graph, calculate the out-degree of vertex v.
 * @param self
 * @param v
 * @return
 */
int out_degree(Graph *self, int v) {
	int count = 0;
	EdgeNodePtr current = self->edges[v].head;

	// loop through all edges leading out from the needle vertex
	while (current != NULL) {
		count++; // keep track of how many edges there are
		current = current->next;
	}

	return count;
}

/**
 * Write a function to zip two lists together.
 *
 * The zip function will return a new list that contains alternating values from the two input lists starting with the first.
 * Your function may assume the input lists are the same length, and should not alter the input lists.
 *
 * For example, the result of zipping the lists containing 1, 2, 3, 4 and 5, 6, 7, 8 would be the list containing 1, 5, 2, 6, 3, 7, 4, 8.
 *
 * @param l1
 * @param l2
 * @return
 */
List zip(List l1, List l2) {

	// create a new list
	List final;
	final.head = NULL;
	ListNodePtr last = NULL;

	// create a pointer for each of the lists
	ListNodePtr current1 = l1.head;
	ListNodePtr current2 = l2.head;

	bool second = false;

	// continue looping while there are any elements remaining
	while (current1 != NULL || current2 != NULL) {
		ListNodePtr current;

		// determine which list to fetch from for this iteration
		// if one list is exhausted, this will be the other one, otherwise it will
		// alternate between lists
		if (second || current1 == NULL) {
			current = current2;
			second = true;
		} else {
			current = current1;
			second = false;
		}

		// construct a new node instance
		ListNodePtr node = malloc(sizeof *node);
		node->next = NULL;
		node->data = current->data;

		// add it to the resulting list
		if (last == NULL) {
			final.head = node;
		} else {
			last->next = node;
		}

		// update the list tail to that the next node can be appended at the rear
		last = node;

		// advance the pointer for the list we just fetched from
		if (second) {
			current2 = current2->next;
		} else {
			current1 = current1->next;
		}

		// fetch from the other list on the next iteration
		second = ! second;
	}

	return final;
}

/**
 * @param self
 * @return
 */
List unzip(List *self) {

	List result;
	result.head = NULL;

	ListNodePtr result_tail = NULL;
	ListNodePtr current = self->head;

	while (current != NULL && current->next != NULL) {

		ListNodePtr next = current->next;

		current->next = next->next;
		next->next = NULL;

		if (result_tail == NULL) {
			result.head = next;
		} else {
			result_tail->next = next;
		}

		result_tail = next;
		current = current->next;
	}


	return result;
}

/**
 * @param self
 * @return
 */
int bst_node_count_single_parents(BSTNodePtr self) {
	int count = 0;

	// base case for recursion
	if (self != NULL) {

		// determine whether the root node only has a single child
		if ((self->left == NULL) == (self->right != NULL)) {
			count++;
		}

		// recursively check the left and right branches
		count += bst_node_count_single_parents(self->right);
		count += bst_node_count_single_parents(self->left);
	}

	return count;
}

/**
 * Write a function that calculates the number of nodes in a binary search tree that have only one child.
 * See exam paper for an example.
 * @param self
 * @return
 */
int bst_count_single_parents(BST *self) {
	return bst_node_count_single_parents(self->root);
}

/**
 * Given an adjacency list representation of an unweighted graph defined by the following structs
 * Write a function to print a breadth-first search of the graph staring at node 0.
 *
 * The function may assume the existence of a Queue data structure for integers.
 *
 * @param self
 */
void bfs(Graph *self) {

	// array for keeping track of which vertices have been added to the queue
	bool *discovered = malloc(self->V * sizeof *discovered);

	for (int i = 0; i < self->V; i++) {
		discovered[i] = false;
	}

	// create a new queue instance
	Queue queue;
	queue.front = queue.rear = NULL;

	// add the first node to the queue
	enqueue(&queue, 0);
	discovered[0] = true;

	int visits = 0;

	// continue looping until all nodes have been visited
	while (visits < self->V) {

		// dequeue the first node and mark it as visited
		int vertex = dequeue(&queue);
		visits++;

		// this will be the next in order, so display it
		printf("%c%s", get_vertex_label(vertex), visits == self->V ? "" : ",");

		// loop through the list of outgoing edges
		EdgeNodePtr current = self->edges[vertex].head;

		while (current != NULL) {
			int dest = current->edge.to_vertex;

			// if the destination vertex is undiscovered, enqueue it and mark it as discovered
			if (! discovered[dest]) {
				enqueue(&queue, dest);
				discovered[dest] = true;
			}

			current = current->next;
		}
	}

	// free allocated memory
	free(discovered);
}

/**
 * Helper for dfs() function
 * @param self
 * @param start
 * @param visited
 */
void dfs_helper(Graph *self, int start, int *visited) {

	if (visited[start]) {
		return;
	}

	visited[start] = true;

	printf("%c ", get_vertex_label(start));

	EdgeNodePtr current = self->edges[start].head;

	while (current != NULL) {
		int dest = current->edge.to_vertex;

		if (! visited[dest]) {
			dfs_helper(self, dest, visited);
		}

		current = current->next;
	}
}

/**
 * Perform a depth-first search of a graph
 * @param self
 * @param start
 */
void dfs(Graph *self, int start) {
	int *visited = malloc(self->V * sizeof *visited);

	for (int v = 0; v < self->V; v++) {
		visited[v] = false;
	}

	dfs_helper(self, start, visited);
	free(visited);
}

/**
 * Find the node with data closest to a given value in a tree node
 * @param self
 * @param value
 * @return
 */
int search_tree_node(BSTNodePtr self, int value) {

	int nearest = self->data;

	if (self->left != NULL) {
		int nearest_left = search_tree_node(self->left, value);

		if (abs(value - nearest_left) < abs(value - nearest)) {
			nearest = nearest_left;
		}
	}

	if (self->right != NULL) {
		int nearest_right = search_tree_node(self->right, value);

		if (abs(value - nearest_right) < abs(value - nearest)) {
			nearest = nearest_right;
		}
	}

	return nearest;
}

/**
 * Find the node with data closest to a given value in a tree
 * @param self
 * @param value
 * @return
 */
int search_tree(BST *self, int value) {
	return search_tree_node(self->root, value);
}
