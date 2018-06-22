#include "list.h"
#include "bst.h"
#include "graph.h"

/**
 * Question 25 (2015) and 21 (2017)
 * Write a function to find the median (middle) value in a sorted linked list of integers.
 * For a list of n integers, the function should return the integer at position (n+1)/2.
 */
int median(List *self);

/**
 * Question 26 (2015)
 *
 * Write a function that takes a sorted array and returns a balanced BST.
 */
BST array_to_bst_simple(int *a, int n);

/**
 * Question 22 (2017)
 *
 * Write a function that takes a sorted array and returns a balanced BST.
 *
 * The function must have the following prototype
 * (where first and last are indices indicating the sub-section of the array to be inserted):
 */
BST array_to_bst(int *a, int first, int last);

/**
 * Question 27 (2016) and 23 (2017)
 *
 * Given an adjacency list representation of a graph, calculate the in-degree of vertex v.
 */
int in_degree(Graph *self, int v);

/**
 * Question 27 (2016) and 23 (2017)
 *
 * Given an adjacency list representation of a graph, calculate the out-degree of vertex v.
 */
int out_degree(Graph *self, int v);

/**
 * Question 21 (2016)
 *
 * Write a function to zip two lists together.
 *
 * The zip function will return a new list that contains alternating values from the two input lists starting with the first.
 * Your function may assume the input lists are the same length, and should not alter the input lists.
 *
 * For example, the result of zipping the lists containing 1, 2, 3, 4 and 5, 6, 7, 8 would be the list containing 1, 5, 2, 6, 3, 7, 4, 8.
 */
List zip(List list1, List list2);

/**
 * Question 22 (2016)
 *
 * Write a function that calculates the number of nodes in a binary search tree that have only one child.
 * See exam paper for an example.
 */
int bst_count_single_parents(BST *self);

/**
 * Question 23 (2016)
 *
 * Given an adjacency list representation of an unweighted graph defined by the following structs
 * Write a function to print a breadth-first search of the graph staring at node 0.
 *
 * The function may assume the existence of a Queue data structure for integers.
 */
void bfs(Graph *self);

/**
 * Question 20 (2018)
 * @param self
 * @return
 */
List unzip(List *self);

/**
 * Question 21 (2018)
 * @param self
 * @param value
 * @return
 */
int search_tree(BST *self, int value);

/**
 * Question 22 (2018)
 * @param self
 * @param start
 */
void dfs(Graph *self, int start);
