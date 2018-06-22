#include "graph.h"
#include <string.h>
#include <stdlib.h>

const char *LABELS = "abcdefghijklmnopqrstuvwxyz";

/**
 * Retrieve the index number for a given vertex label
 * @param vertex
 * @return
 */
int get_vertex_index(char vertex) {
	return (int) (strchr(LABELS, vertex) - LABELS);
}

/**
 * Retrieve the label for a given vertex index
 * @param vertex
 * @return
 */
char get_vertex_label(int vertex) {
	return LABELS[vertex];
}

/**
 * Initialise a graph instance
 * @param vertices number of vertices
 * @return
 */
Graph create_graph(int vertices) {
	Graph self;

	self.V = vertices;

	self.edges = malloc(self.V * sizeof *self.edges);

	for (int v = 0; v < self.V; v++) {
		self.edges[v].head = NULL;
	}

	return self;
}

/**
 * Add a new edge to a graph
 * @param self
 * @param from
 * @param to
 * @param weight
 */
void add_edge(Graph *self, char from, char to, int weight) {
	EdgeNodePtr edge = malloc(sizeof *edge);

	edge->edge.to_vertex = get_vertex_index(to);
	edge->edge.weight = weight;

	int from_vertex = get_vertex_index(from);
	edge->next = self->edges[from_vertex].head;
	self->edges[from_vertex].head = edge;
}
