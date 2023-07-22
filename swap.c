#include "sort.h"

/**
 * swap - swaps two elements of the array
 * @array: A pointer to the first element of the array
 * @lb: An integer
 * @ub: An integer
 */

void swap(int *array, size_t lb, size_t ub)
{
	size_t temp;

	temp = array[lb];
	array[ub] = array[lb];
	array[lb] = temp;
}
