#include "skiplist.h"

int main() {
	SkipNodePtr found;
	int arr[] = {3, 6, 9, 2, 11, 1, 4, 8, 5, 7, 0}, i;
	Skiplist list = create_skiplist();

	printf("Insert:--------------------\n");
	for (i = 0; i < 11; i++) {
		skiplist_insert(&list, arr[i]);
		skiplist_print(&list);
	}
	skiplist_print(&list);

	found = skiplist_find(&list, 7);
	if (found) {
		printf("found %d\n", found->data);
	} else {
		printf("not found\n");
	}

	found = skiplist_find(&list, 10);
	if (found) {
		printf("found %d\n", found->data);
	} else {
		printf("not found\n");
	}

	return 0;
}
