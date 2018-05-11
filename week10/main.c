#include <stdio.h>
#include <stdlib.h>

int knapsackValue(const int weights[], const int values[], int const capacity, const int items) {

	int **table = malloc(sizeof(int *) * (items + 1));

	for (int i = 0; i <= items; i++) {
		table[i] = malloc(sizeof(int) * (capacity + 1));

		for (int j = 0; j <= capacity; j++) {

			if (i == 0 || j == 0) {
				table[i][j] = 0;

			} else if (weights[i - 1] > j) {
				table[i][j] = table[i - 1][j];

			} else {
				int a = table[i - 1][j];
				int b = values[i - 1] + table[i - 1][j - weights[i - 1]];

				table[i][j] = a > b ? a : b;
			}
		}
	}

	int result = table[items][capacity];

	for (int i = 0; i < items; i++) {
		free(table[i]);
	}

	free(table);

	return result;
}

int main() {
	const int ITEMS = 10;
	int w[ITEMS] = {1, 1, 3, 3, 2, 4, 3, 6, 5, 7};
	int v[ITEMS] = {100, 150, 50, 25, 2, 15, 1000, 25, 55, 225};

	for (int i = 1; i <= 35; i++) {
		int value = knapsackValue(w, v, i, ITEMS);
		printf("max value with %d capacity is %d\n", i, value);
	}
	return 0;
}
