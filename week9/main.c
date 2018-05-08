#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph input_graph() {
	Graph G;

	/* read in number of vertices */
	scanf("%d", &G.V);
	G.edges = malloc(sizeof(G.edges) * G.V);

	for (int v = 0; v < G.V; v++) {
		int n_edges;
		scanf("%d", &n_edges);
		G.edges[v].head = NULL;

		for (int e = 0; e < n_edges; e++) {
			EdgeNodePtr node = malloc(sizeof(EdgeNodePtr));
			scanf("%d,%d", &node->edge.to_vertex, &node->edge.weight);

			node->next = G.edges[v].head;
			G.edges[v].head = node;
		}
	}

	return G;
}

void destroy_graph(Graph *G) {

	for (int v = 0; v < G->V; v++) {
		EdgeNodePtr current = G->edges[v].head;

		while (current != NULL) {
			EdgeNodePtr to_free = current;
			current = current->next;
			free(to_free);
		}
	}

	free(G->edges);
}

double calc_pagerank(Graph G, int vertex, double d_factor) {
	double sum = 0;

	for (int j = 0; j < G.V; j++) {
		double out_degree = 0;
		double linking = 0;

		EdgeNodePtr current_edge = G.edges[j].head;

		while (current_edge != NULL) {
			out_degree++;

			if (current_edge->edge.to_vertex == vertex) {
				linking++;
			}

			current_edge = current_edge->next;
		}

		sum += linking / out_degree;
	}

	return (1 - d_factor) + d_factor * sum;
}

void array_fill(double *array, int length, double value) {
	for (int i = 0; i < length; i++) {
		array[i] = value;
	}
}

char format_vector(int vector) {
	return (char) (65 + vector);
}

int main() {
	Graph G = input_graph();

	const int ITERATIONS = 4;
	const double DAMP_FACTOR = 0.5;

	double pageranks[G.V];
	array_fill(pageranks, G.V, 1);

	int outgoing_edges[G.V];
	for (int v = 0; v < G.V; v++) {
		EdgeNodePtr current_edge = G.edges[v].head;
		outgoing_edges[v] = 0;
		printf("vertex %c:", format_vector(v));

		while (current_edge != NULL) {
			printf(" %c", format_vector(current_edge->edge.to_vertex));
			outgoing_edges[v]++;
			current_edge = current_edge->next;
		}

		printf("\n");
	}

	printf("\n");

	for (int iter = 0; iter < ITERATIONS; iter++) {
		double sums[G.V];
		array_fill(sums, G.V, 0);

		/* calculate the sum component for each page */
		for (int page = 0; page < G.V; page++) {
			EdgeNodePtr current = G.edges[page].head;

			while (current != NULL) {
				sums[current->edge.to_vertex] += pageranks[page] / outgoing_edges[page];
				current = current->next;
			}
		}

		/* update the page ranks */
		for (int page = 0; page < G.V; page++) {
			pageranks[page] = DAMP_FACTOR + DAMP_FACTOR * sums[page];
			printf("%f  ", pageranks[page]);
		}

		printf("\n");
	}

	destroy_graph(&G);

	return 0;
}
