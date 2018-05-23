#include "skiplist.h"
#include <stdio.h>

const int STOP = 99;

int main() {
	Skiplist list = create_skiplist();

	int insert_data[] = {3, 6, 9, 2, 11, 1, 4, 8, 5, 7, 0, STOP};

	for (int i = 0; insert_data[i] != STOP; i++) {
		int levels = skiplist_insert(&list, insert_data[i]);

		printf("inserted %d (%d %s)\n", insert_data[i], levels, levels == 1 ? "level" : "levels");
		print_skiplist_levels(&list);
		printf("\n");
	}



	int find_data[] = {7, 10, STOP};

	for (int i = 0; find_data[i] != STOP; i++) {
		SkipNodePtr found = skiplist_find(&list, find_data[i]);

		if (found == NULL) {
			printf("cannot find %d\n", find_data[i]);
		} else {
			printf("found %d\n", found->data);
		}
	}

	int delete_data[] = {3, 7, 9, STOP};

	for (int i = 0; delete_data[i] != STOP; i++) {
		printf("\ndeleting %d\n", delete_data[i]);
		skiplist_delete(&list, delete_data[i]);
		print_skiplist_levels(&list);
	}

	return 0;
}
