#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

int *range(int start, int stop) {
	int length = stop - start;

	if (length <= 0) {
		return NULL;
	}

	int *array = malloc(length * sizeof *array);

	for (int i = 0; i < length; i++) {
		array[i] = start + i;
	}

	return array;
}

void test_median(int len) {
	int *numbers = range(1, len + 1);

	List list;
	list.head = NULL;

	for (int i = len - 1; i >= 0; i--) {
		ListNodePtr node = malloc(sizeof *node);
		node->data = numbers[i];
		node->next = list.head;
		list.head = node;
	}

	int actual_median = numbers[((len + 1) / 2) - 1];

	if (actual_median == median(&list)) {
		printf("correct: median is %d", actual_median);
	} else {
		printf("incorrect: median is %d, not %d", actual_median, median(&list));
	}

	printf(" for {");

	ListNodePtr current = list.head;
	while (current != NULL) {
		ListNodePtr to_free = current;
		printf("%d%s", current->data, current->next == NULL ? "" : ", ");
		current = current->next;
		free(to_free);
	}

	printf("}\n");

	free(numbers);
	free(current);
}

void test_arrayToBST(int from, int length) {
	int* numbers = range(from, from + length);

	BST tree = array_to_bst_simple(numbers, length);

	print_bst(&tree);
	printf("----------\n");


	BST tree2 = array_to_bst(numbers, 0, length - 1);

	print_bst(&tree2);
	printf("----------\n\n");

}

void test_zip() {
	List list1;
	list1.head = NULL;

	for (int i = 8; i > 0; i--) {
		list_prepend(&list1, i);
	}

	printf("original:\t");
	print_list(&list1);

	List list2 = unzip(&list1);

	printf("part 1:\t\t");
	print_list(&list1);

	printf("part 2:\t\t");
	print_list(&list2);

	List zipped = zip(list1, list2);
	printf("zipped:\t\t");
	print_list(&zipped);

}

void print_graph(Graph *self) {

	for (int v = 0; v < self->V; v++) {
		printf("%c → ", get_vertex_label(v));

		EdgeNodePtr edge = self->edges[v].head;

		while (edge != NULL) {
			printf("%c ", get_vertex_label(edge->edge.to_vertex));
			edge = edge->next;
		}

		printf("\n");
	}
}


void test_bfs() {
	Graph graph = create_graph(9);

	char edges[17][3] = {"ad", "bf", "be", "bc", "ba", "cf", "dg", "db", "ei", "ef", "ed", "ec", "fi", "gh", "ge", "hi", "he"};

	for (int i = 0; i < 17; i++) {
		add_edge(&graph, edges[i][0], edges[i][1], 0);
	}

	bfs(&graph);
}

void test_dfs() {
	Graph graph = create_graph(9);

	char edges[16][3] = {"ad", "ab", "bf", "be", "bc", "cf", "dg", "de", "db", "ei", "ef", "fi", "gh", "ge", "hi", "he"};
	for (int i = 0; i < 16; i++) {
		add_edge(&graph, edges[i][0], edges[i][1], 0);
	}

	dfs(&graph, 0);
	// answer: a, b, c, f, i, e, d, g, h
}

void test_tree() {
	BST tree;
	tree.root = create_bst_node(6);
	BSTNodePtr root = tree.root;

	root->left = create_bst_node(2);
	root->left->left = create_bst_node(1);
	root->left->right = create_bst_node(3);
	root->left->right->right = create_bst_node(5);

	root->right = create_bst_node(8);
	root->right->right = create_bst_node(11);
	root->right->right->left = create_bst_node(9);
	print_bst(&tree);
	printf("\n");

	printf("\ntotal single parents: %d\n", bst_count_single_parents(&tree));

	const int value = 50;
	printf("nearest value to %d: %d", value, search_tree(&tree, value));
}

void test_in_out_degree() {

	Graph graph = create_graph(9);
	char edges[17][3] = {"ad", "bf", "be", "bc", "ba", "cf", "dg", "db", "ei", "ef", "ed", "ec", "fi", "gh", "ge", "hi", "he"};

	for (int i = 0; i < 17; i++) {
		add_edge(&graph, edges[i][0], edges[i][1], 0);
	}

	for (int v = 0; v < graph.V; v++) {
		printf("%d\t→\t%c\t←\t%d\n", in_degree(&graph, v), get_vertex_label(v), out_degree(&graph, v));
	}
}

int main() {
	return 0;
}
