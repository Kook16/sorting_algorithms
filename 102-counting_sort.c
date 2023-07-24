#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: A pointer to the array
 * @size: size of the array
 */

void counting_sort(int *array, size_t size) {
	int i, k;
	int *b_array, *counting_array;

	if (size <= 1 || array == NULL)
		return;
	k = array[0];
	/* Find the maximum element in the array */
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	/* Allocate and initialize counting_array */
	counting_array = (int *)malloc((k + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	for (i = 0; i <= k; i++)
		counting_array[i] = 0;

	/* Count the occurrences of each element */
	for (i = 0; i < (int)size; i++)
		/* Cast size to int for comparison */
		counting_array[array[i]]++;

	/* Compute the cumulative count */
	for (i = 1; i <= k; i++)
		counting_array[i] += counting_array[i - 1];

	/* Build the sorted array */
	b_array = (int *)malloc(size * sizeof(int));

	for (i = (int)size - 1; i >= 0; i--)
	{ /* Cast size to int for comparison */
		b_array[--counting_array[array[i]]] = array[i];
	}

	print_array(counting_array, k + 1);

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < (int)size; i++)
	{ /* Cast size to int for comparison */
		array[i] = b_array[i];
	}

	/* Free dynamically allocated memory */
	free(counting_array);
	free(b_array);
}
