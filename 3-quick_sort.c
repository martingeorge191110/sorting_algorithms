#include "sort.h"

/**
 * quick_sort_helper - recursive helper function for quick sort
 *
 * @array: pointer to the array
 * @low: starting index of the array
 * @high: ending index of the array
 *
 * Return: Nothing
*/
void quick_sort_helper(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high);

		quick_sort_helper(array, low, pi - 1);
		quick_sort_helper(array, pi + 1, high);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for quick sort
 *
 * @array: pointer to the array
 * @low: starting index of the partition
 * @high: ending index (pivot)
 *
 * Return: the partition index
*/

int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = low;

	for (j; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_func(&array[i], &array[j]);
		}
	}
	swap_func(&array[i + 1], &array[high]);
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
	if (size < 2)
		return;

	quick_sort_helper(array, 0, size - 1);
}
