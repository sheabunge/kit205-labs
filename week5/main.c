#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main() {
	int command = 1;
	HashTable table = create_hashtable(11);
	char buffer[100];

	while (command) {
		printf("1 = insert; 2 = remove; 3 = print: ");
		scanf("%s", buffer);
		command = (int) strtol(buffer, NULL, 10);

		switch (command) {
			case 1:
				printf("Value to insert: ");
				scanf("%s", buffer);
				hash_insert(&table, buffer);
				break;

			case 2:
				printf("Value to remove: ");
				scanf("%s", buffer);
				hash_remove(&table, buffer);
				break;

			case 3:
				hash_print(&table);
				break;

			default:
				break;
		}

		printf("\n");
	}

	hash_destroy(&table);
}