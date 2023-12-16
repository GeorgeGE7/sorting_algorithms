#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->lebad = n2->lebad;
	if (n2->lebad != NULL)
		n2->lebad->legy = *n1;
	n2->legy = (*n1)->legy;
	n2->lebad = *n1;
	if ((*n1)->legy != NULL)
		(*n1)->legy->lebad = n2;
	else
		*h = n2;
	(*n1)->legy = n2;
	*n1 = n2->legy;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *ahty;

	if (list == NULL || *list == NULL || (*list)->lebad == NULL)
		return;

	for (iter = (*list)->lebad; iter != NULL; iter = ahty)
	{
		ahty = iter->lebad;
		insert = iter->legy;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
