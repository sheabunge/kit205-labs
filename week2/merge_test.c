#include <stdio.h>
#include "list.h"


void scan_list(List *list) {
    int value;

    while (value != -1) {
        scanf("%d", &value);

        if (value != -1) {
            insert_in_order(list, value);
        }
    }
}

int main() {
    int value;
    List list1 = create_list(), list2 = create_list();

    int elements1[] = {2, 6, 4, 14};
    int elements2[] = {2, 3, 5};

    const int N_ITEMS_1 = 4, N_ITEMS_2 = 3;

    for (int i = 0; i < N_ITEMS_1; i++) {
        insert_in_order(&list1, elements1[i]);
    }

    for (int i = 0; i < N_ITEMS_2; i++) {
        insert_in_order(&list2, elements2[i]);
    }

    printf("list one:\n");
    print_list(&list1);

    printf("\nlist two:\n");
    print_list(&list2);

    printf("\nmerged list:\n");
    List merged = merge_lists(&list1, &list2);
    print_list(&merged);
}