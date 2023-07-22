#include "sort.h"

/**
 * bubble_sort - sorts an array in ascendin ord the Bubble sort algorithm
 * @array: A pointer to the first element of the array
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = 1;
				temp = array[j];
				array[j] = array[j + 1];
				array[j] = temp;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
