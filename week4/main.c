#include <stdio.h>
#include <stdbool.h>
#include "bst.h"


void insert_data(BST *tree, int data[], int data_length) {

    for (int i = 0; i < data_length; i++) {
        insert_bst(tree, data[i]);
    }
}

void prompt_data(BST *tree) {
    int quit = false;
    int data;

    while (! quit) {
        printf("Enter some data: ");
        scanf("%d", &data);

        if (data == 0) {
            quit = true;
        } else {
            insert_bst(tree, data);
        }
    }
}

int main() {
    BST tree = create_bst();

    int tree_data[] = {6, 3, 9, 2, 7, 4, 8, 11, 14, 1, 17, 15};

    insert_data(&tree, tree_data, 12);

    print_pre_order_bst(&tree);
    printf("\n");
    print_in_order_bst(&tree);
    printf("\n");
    print_post_order_bst(&tree);
    printf("\n");

    printf("height: %d", bst_height(&tree));

    return 0;
}