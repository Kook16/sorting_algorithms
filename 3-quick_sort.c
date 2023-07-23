#include "sort.h"
size_t position(int *array, int start, int end);

/**
 * quick_sort - sorts an array of integers in ascending order using\
the Quick sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	size_t start, end;

	start = 0;
	end = size - 1;
	if (start < end)
	{
		loc = position(array, start, end);
		quick_sort(array, start, loc -1);
		quick_sort(array, loc + 1, end);
		print_array(array, size);
	}
}

/**
 * position - returns the position of the pivot element
 * @start: index of the first ele
 * @end: index of the last ele
 * Return: Index of the pivot ele
 */

size_t position(int *array, int start, int end)
{
	size_t pivot;
	int temp;

	pivot = array[end];
	while (start < end)
	{
		while (array[start] <= pivot)
			start++;
		while (array[end] > pivot)
			end--;
		if (start < end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
		}
	}
	temp = pivot;
	pivot = array[start];
	array[start] = pivot;
	return start;
}
