#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: A pointer to the array
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int i, k;
	int *b_array, *counting_array;

	if (size <= 1 || array == NULL)
		return;
	k = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	counting_array = (int *)malloc((k + 1) * sizeof(int));
	if (counting_array == NULL)
		return;
	for (i = 0; i <= k; i++)
		counting_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		counting_array[array[i]]++;
	for (i = 1; i <= k; i++)
		counting_array[i] += counting_array[i - 1];
	print_array(counting_array, k + 1);
	b_array = (int *)malloc(size * sizeof(int));
	for (i = (int)size - 1; i >= 0; i--)
		b_array[--counting_array[array[i]]] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = b_array[i];
	free(counting_array);
	free(b_array);
}
