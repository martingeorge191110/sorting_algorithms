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
