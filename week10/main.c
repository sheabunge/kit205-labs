#include <stdio.h>
#include <stdlib.h>

float knapsackValueSolution(int w[], int v[], int W, int n) {
	// make 2D array (array of arrays)
	int **A = malloc(n * sizeof *A); // or malloc(n * sizeof(int*))
	for (int i = 0; i < n; i++) {
		A[i] = malloc(W * sizeof *A[i]); // or malloc(n * sizeof(int))

		// the following initialisation is not necessary for this problem
		for (int j = 0; j < W; j++) {
			A[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) { // column (item number)
		for (int j = 0; j < W; j++) { // row (knapsack weight)
			if (w[i] <= j) { // item i would fit in the knapsack
				if (i == 0) { // first item so take it
					A[i][j] = v[i];
				} else {
					if (A[i - 1][j - w[i]] + v[i] > A[i - 1][j]) { // better to take this item
						A[i][j] = A[i - 1][j - w[i]] + v[i];
					} else { // better to leave this item
						A[i][j] = A[i - 1][j];
					}
				}
			} else { // doesn't fit
				if (i == 0) { // nothing fits yet
					A[i][j] = 0;
				} else { // this item doesn't fit so stick with previous best
					A[i][j] = A[i - 1][j];
				}
			}
		}
	}

	int result = A[n - 1][W - 1]; // remember this so we can free memory

	// free inner arrays first
	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	// then free array of arrays
	free(A);

	return result;
}


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
