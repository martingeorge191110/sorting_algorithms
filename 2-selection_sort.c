#include "sort.h"

/**
 * selection_sort - selection sort method
 *
 * @array: pointer to start of arrry
 * @size: size of the array
 *
 * Return: sorted array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, min_no, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_no = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_no])
			{
				min_no = j;
			}
		}
		if (min_no != i)
		{
			temp = array[min_no];
			array[min_no] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
