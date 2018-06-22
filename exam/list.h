
typedef struct listNode {
	int data;
	struct listNode *next;
} *ListNodePtr;

typedef struct list {
	ListNodePtr head;
} List;


typedef struct queue {
	ListNodePtr front;
	ListNodePtr rear;
} Queue;




void enqueue(Queue *self, int i);

int dequeue(Queue *self);

Queue create_queue();

void print_list(List *self);

void list_prepend(List *self, int value);

List array_to_list(const int *array, int length);
