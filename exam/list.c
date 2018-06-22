#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void print_list(List *self) {
	ListNodePtr current = self->head;

	printf("{");

	while (current != NULL) {
		printf("%d%s", current->data, current->next == NULL ? "" : ", ");
		current = current->next;
	}

	printf("}\n");
}

void list_prepend(List *self, int item) {
	ListNodePtr node = malloc(sizeof *node);

	node->next = self->head;
	node->data = item;

	self->head = node;
}

List array_to_list(const int *array, int length) {
	List list;
	list.head = NULL;

	for (int i = length - 1; i >= 0; i--) {
		list_prepend(&list, array[i]);
	}

	return list;
}


Queue create_queue() {
	Queue queue;
	queue.front = NULL;
	queue.rear = NULL;
	return queue;
}

void enqueue(Queue *self, int i) {
	ListNodePtr node = malloc(sizeof *node);
	node->data = i;
	node->next = NULL;

	if (self->front == NULL && self->rear == NULL) {
		self->front = self->rear = node;

	} else {
		self->rear->next = node;
		self->rear = node;
	}
}

int dequeue(Queue *self) {
	int data = -1;

	if (self->front != NULL) {
		ListNodePtr to_free = self->front;

		data = self->front->data;

		if (self->front->next == NULL) {

			self->front = NULL;
			self->rear = NULL;

		} else {
			self->front = self->front->next;
		}

		free(to_free);
	}

	return data;
}
