#include "sort.h"

/**
 * bubble_sort - sorts an array in ascendin ord the Bubble sort algorithm
 * @array: A pointer to the first element of the array
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t pass, j, swap;
	int temp;

	for (pass = size; pass > 0 && swap; pass--)
	{
		swap = 0;
		for (j = 0; j <= pass - 1; j++)
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
	}
}
