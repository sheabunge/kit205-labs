#include <stdio.h>

void _swap(int *a, int *b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(int a[], int first, int last) {

	// can't sort invalid sequences
	if (first >= last) return;

	// find pivot
	int middle = (last - first) / 2;
	int pivot = last;

	if ((a[first] < a[middle] && a[middle] < a[last]) || (a[last] < a[middle] && a[middle] < a[first])) {
		// if the middle is between the first and last elements, make it the pivot
		pivot = middle;

	} else if ((a[middle] < a[first] && a[first] < a[last]) || (a[last] < a[first] && a[first] < a[middle])) {
		// otherwise, if the first element is between the middle and last, then make that the pivot
		pivot = first;
	}

	// switch the pivot with the last array element if necessary
	if (pivot != last) {
		_swap(&a[last], &a[pivot]);
	}

	int i = first;
	int j = last - 1;

	// continue until the pointers swap over
	while (i < j) {

		// work forwards from the first element until an value greater
		// than the pivot is discovered
		while (i < last && a[i] < a[last]) {
			i++;
		}

		// work backwards from the second-last element until a value smaller
		// than the pivot is discovered
		while (j >= first && a[j] > a[last]) {
			j--;
		}

		// if the two values are out of order, then swap them
		if (i < j) {
			_swap(&a[i], &a[j]);
		}
	}

	// finally, swap the pivot element back into the array at the appropriate position
	_swap(&a[i], &a[last]);

	// recursively sort the two subsequences
	quicksort(a, first, j);
	quicksort(a, i + 1, last);
}

int main() {

	const int N_NUMBERS = 12;
	int numbers[] = {5, 10, 9, 2, 5, 7, 4, 6, 8, 9, 11, 42};

	quicksort(numbers, 0, N_NUMBERS - 1);

	for (int i = 0; i < N_NUMBERS; i++) {
		printf("%d%s", numbers[i], i == N_NUMBERS - 1 ? "" : ", ");
	}

	return 0;
}
