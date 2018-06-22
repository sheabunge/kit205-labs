#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort(char **a, int first, int last) {
	int i, j;
	char *temp;

	// begin at second value in array (first is already sorted)
	for (i = first + 1; i <= last; i++) {
		temp = a[i]; // current value

		// begin at portion of array already sorted and
		// work backwards to find position to insert current value
		j = i - 1;
		while (j >= first && strcmp(temp, a[j]) < 0) {
			// shuffle value down one position
			a[j + 1] = a[j];
			--j;
		}

		// insert value
		a[j + 1] = temp;
	}
}

void quicksort(char **a, int first, int last) {
	char *temp;

	/* can't sort invalid sequences */
	if (first >= last) {
		return;
	}

	/* use insertion sort for small sequences */
	if (last - first < 10) {
		insertion_sort(a, first, last);
		return;
	}

	// find pivot
	int middle = (last - first) / 2;
	int pivot = last;

	if (strcmp(a[first], a[middle]) < 0 && strcmp(a[middle], a[last]) < 0 ||
	    strcmp(a[last], a[middle]) < 0 && strcmp(a[middle], a[first]) < 0) {
		pivot = middle;
	} else if (strcmp(a[middle], a[first]) < 0 && strcmp(a[first], a[last]) < 0 ||
		strcmp(a[last], a[first]) < 0 && strcmp(a[first], a[middle]) < 0) {
		pivot = first;
	}

	if (pivot != last) {
		temp = a[last];
		a[last] = a[pivot];
		a[pivot] = temp;
	}

	int i = first;
	int j = last - 1;

	while (i < j) {
		while (i < last && strcmp(a[i], a[last]) < 0) {
			i++;
		}

		while (j >= first && strcmp(a[j], a[last]) > 0) {
			j--;
		}

		if (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	temp = a[i];
	a[i] = a[last];
	a[last] = temp;

	quicksort(a, first, j);
	quicksort(a, i + 1, last);
}

int main() {
	char **strings;
	char buffer[100];

	int n;

	printf("Number of strings: ");
	scanf("%d", &n);

	strings = malloc(n * sizeof(char *));

	/* Fill the array */

	for (int i = 0; i < n; i++) {
		scanf("%s", buffer);

		strings[i] = (char *) malloc(strlen(buffer) + 1);
		strcpy(strings[i], buffer);
	}

	/* Sort the array */
	quicksort(strings, 0, n - 1);

	/* Print the array */

	printf("\nArray contents:\n");

	for (int i = 0; i < n; i++) {
		printf("%s\n", strings[i]);
	}

	/* Free memory */

	for (int i = 0; i < n; i++) {
		free(strings[i]);
	}

	free(strings);

	return 0;
}