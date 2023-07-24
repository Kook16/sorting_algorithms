#include "sort.h"

/**
 * bubble_sort - sorts an array in ascendin ord the Bubble sort algorithm
 * @array: A pointer to the first element of the array
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t pass, j;
	int temp, swap = 1;

	if (array == NULL || size <= 1)
		return;
	for (pass = size - 1; pass >= 1 && swap; pass--)
	{
		swap = 0;
		for (j = 0; j <= pass - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = 1;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
