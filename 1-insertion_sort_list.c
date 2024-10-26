#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 *								in ascending order using the Insertion sort algorithm
 * @list: Pointer points to the head of list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev, *next;

	if (!(*list))
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		while (temp->prev && temp->prev->n > temp->n)
		{
			prev = temp->prev;
			next = temp->next;

			if (prev->prev)
				prev->prev->next = temp;
			else
				 *list = temp;

			temp->prev = prev->prev;
			temp->next = prev;
			prev->prev = temp;
			prev->next = next;

			if (next)
				next->prev = prev;

			print_list(*list);
		}
		current = current->next;
	}
}
