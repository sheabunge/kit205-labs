
/**
 * Represents an edge in a graph
 */
typedef struct edge {
	int to_vertex;
	int weight;
} Edge;

/**
 * Represents a linked list node containing a graph edge
 */
typedef struct edgeNode {
	Edge edge;
	struct edgeNode *next;
} *EdgeNodePtr;

/**
 * Represents a linked list of edges
 */
typedef struct edgeList {
	EdgeNodePtr head;
} EdgeList;

/**
 * Represents a graph with vertices and edges
 */
typedef struct graph {
	int V;
	EdgeList *edges;
} Graph;

int get_vertex_index(char vertex);

char get_vertex_label(int vertex);

Graph create_graph(int vertices);

void add_edge(Graph *self, char from, char to, int weight);
