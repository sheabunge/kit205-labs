#include <stdio.h>
#include "list.h"

void option_insert(List *self) {
    int value;

    printf("Value to insert: ");
    scanf("%d", &value);

    insert_at_front(self, value);
}

void option_delete(List *self) {
    int value;

    printf("Value to delete: ");
    scanf("%d", &value);

    delete_list(self, value);
}

void option_print(List *self) {
    print_list(self);
}

void option_reverse(List *self) {
    *self = reverse_list(self);
}

/**
 * Display a menu of possible options
 * @param options amount of options to display
 * @param labels  list of option labels
 */
void print_menu(int options, char *labels[]) {
    printf("Options: \n");

    for (int i = 0; i < options; i++) {
        printf("%d\t%s\n", i, labels[i]);
    }

    printf("\n");
}

int main() {
    List my_list = create_list();
    int quit = 0;
    int option;

    const int N_OPTIONS = 5;

    char* options[] = {
            "quit",
            "insert value",
            "delete from list",
            "print list",
            "reverse list"
    };

    while (! quit) {
        print_menu(N_OPTIONS, options);
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 0:
                quit = 1;
                break;

            case 1:
                option_insert(&my_list);
                break;

            case 2:
                option_delete(&my_list);
                break;

            case 3:
                option_print(&my_list);
                break;

            case 4:
                option_reverse(&my_list);
                break;

            default:
                printf("Invalid option\n");
        }

        printf("\n");

    }

    destroy_list(&my_list);

    return 0;
}
