#include "sort.h"

/**
 * swap_func - swapping of two variable values
 *
 * @a: pointer to first variable
 * @b: pointer to second variable
 */

void swap_func(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quick_sort_helper - recursive helper function for quick sort
 *
 * @array: pointer to the array
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: array size
 *
 * Return: Nothing
*/
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for quick sort
 *
 * @array: pointer to the array
 * @low: starting index of the partition
 * @high: ending index (pivot)
 * @size: array size
 *
 * Return: the partition index
*/

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_func(&array[i], &array[j]);
			if (j != i)
				print_array(array, size);
		}
	}
	swap_func(&array[i + 1], &array[high]);
	if (j != i)
		print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort - quick sort for array
 *
 * @array: pointer to the array
 * @size: array size
 *
 * Return: Nothing
*/

void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}
