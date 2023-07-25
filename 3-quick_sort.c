#include "sort.h"

void q_sort(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);

/**
 * quic_sort - sorts an array of integers using quick sort
 * @array: Array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}

/**
 * qsort - recursive function to perform quicksort
 * @array: array to be sorted
 * @low: Starting index of the partion
 * @high: ending index of partition
 * @size: size of the array
 */

void q_sort(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		q_sort(array, low, pivot_index - 1, size);
		q_sort(array, pivot_index + 1, high, size);
	}
}


/**
 * lomuto_partition - this function returns the pos of the pivot element
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: Position of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int j, pivot = array[high];
	int i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - swaps two integers of the array
 * @a: first intger
 * @b: second integer
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
