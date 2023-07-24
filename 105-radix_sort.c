#include "sort.h"
void counting_sort_radix(int *array, size_t size, int pos);

/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 * @array: A pointer to the array
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max, i, pass;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	for (pass = 1; (max / pass) > 0; pass *= 10)
		counting_sort_radix(array, size, pass);
}

/**
 * counting_sort - implementing the counting sort algorithm
 * @array: A pointer to the array
 * @size: size of the array
 * @pos: position of a digit in a number
 */

void counting_sort_radix(int *array, size_t size, int pos)
{
	int *counting_array, *b_array;
	int i;

	counting_array = malloc(10 * sizeof(int));
	for (i = 0; i < 10; i++)
		counting_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		++counting_array[(array[i] / pos) % 10];
	for (i = 1; i < 10; i++)
		counting_array[i] += counting_array[i - 1];
	b_array = malloc(size * sizeof(int));
	for (i = (int)size - 1; i >= 0; i--)
		b_array[--counting_array[((array[i] / pos) % 10)]] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = b_array[i];
	print_array(array, size);

	free(counting_array);
	free(b_array);
}
