#include <stdio.h>
#include <time.h>
#include <math.h>

/**
 * O(1 + n(3 + n(3 + 1)))
 * O(n^2)
 *
 * @param n
 * @return
 */
int f1(long n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            k++;
        }
    }
    return k;
}

/**
 * O(1 + n(3 + 4n + 4n))
 * O(n^2)
 *
 * @param n
 */
void f2(long n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            k++;
        }
        for (int t = 0; t < 10000; t++) {
            k++;
        }
    }
}

/**
 *
 * @param n
 */
void f3(long n) {
    if (n > 0) {
        f3(n / 2);
        f3(n / 2);
    }
}

void f4(long n) {
    if (n > 0) {
        f4(n / 2);
        f4(n / 2);
        f2(n);
    }
}

void f5(long n) {
    int k = 0;
    for (int i = 0; i < 10; i++) {
        int j = n;
        while (j > 0) {
            k++;
            j = j / 2;
        }
    }
}

void f6(long n){
    f2(n);
    f3(n);
    f5(n);
}

void f7(long n) {
    int k = 0;
    for (int i = 0; i < f1(n); i++) {
    }
    for (int j = 0; j < n; j++) {
        k++;
    }
}

const int N_FUNCTIONS = 7;
void (*FUNCTIONS[])(long n) = {(void *) f1, f2, f3, f4, f5, f6, f7};


void print_options() {
    printf("Options: \n");

    printf("0:\tquit\n");

    for (int i = 1; i <= N_FUNCTIONS; i++) {
        printf("%d:\tf%d()\n", i, i);
    }

    printf("\n");
}

long time_function(void (*function)(long), long n) {
    clock_t start = clock();
    (*function)(n);
    clock_t diff = clock() - start;
    return diff * 1000 / CLOCKS_PER_SEC;
}

void test_all(void (*function)(long)) {
    int tests[] = {5, 50, 500, 5000, 50000};

    printf("%ld\n", time_function(function, 1));
    printf("%ld\n", time_function(function, 2));

    for (int i = 0; i < 6; i++) {
        printf("%ld\n", time_function(function, tests[i]));
        printf("%ld\n", time_function(function, tests[i] * 2));
        printf("%ld\n", time_function(function, tests[i] * 4));
    }

    printf("\n\n");
}

int main() {
    int quit = 0;
    int option;
    long n;

    while (!quit) {
        print_options();
        printf("Enter option: ");
        scanf("%d", &option);

        if (option > 0 && option <= N_FUNCTIONS) {
            printf("Enter a value for n: ");
            scanf("%ld", &n);

            if (n < 0) {
                test_all(FUNCTIONS[option - 1]);
            } else {
                long msec = time_function(FUNCTIONS[option - 1], n);
                printf("Operation took %ld milliseconds\n\n", msec);
            }

        } else if (option == 0) {
            quit = 1;
        } else {
            printf("Invalid option\n");
        }

        printf("\n");

    }

    return 0;
}


