#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {

	Graph G;

	scanf("%d", &G.V);
	G.edges = malloc(sizeof(G.edges) * G.V);
	printf("%d\n", G.V);

	for (int v = 0; v < G.V; v++) {
		int n_edges;
		scanf("%d", &n_edges);
		G.edges[v].head = NULL;

		printf("%d\n", n_edges);

		for (int e = 0; e < n_edges; e++) {
			EdgeNodePtr node = malloc(sizeof(EdgeNodePtr));
			scanf("%d,%d", &node->edge.to_vertex, &node->edge.weight);

			node->next = G.edges[v].head;
			G.edges[v].head = node;
		}
	}

	/* calculate in-degrees of all vertices */

	int in_degrees[G.V];
	for (int i = 0; i < G.V; i++) {
		in_degrees[i] = 0;
	}

	for (int v = 0; v < G.V; v++) {

		EdgeNodePtr current_edge = G.edges[v].head;

		while (current_edge != NULL) {
			in_degrees[current_edge->edge.to_vertex]++;
			current_edge = current_edge->next;
		}
	}

	for (int i = 0; i < G.V; i++) {
		printf("vertex %d has %d in-degrees\n", i, in_degrees[i]);
	}


	/* free memory */

	for (int v = 0; v < G.V; v++) {
		EdgeNodePtr current = G.edges[v].head;

		while (current != NULL) {
			EdgeNodePtr to_free = current;
			current = current->next;
			free(to_free);
		}
	}

	free(G.edges);

	return 0;
}
