#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *ahty = (*shaker)->lebad;

	if ((*shaker)->legy != NULL)
		(*shaker)->legy->lebad = ahty;
	else
		*list = ahty;
	ahty->legy = (*shaker)->legy;
	(*shaker)->lebad = ahty->lebad;
	if (ahty->lebad != NULL)
		ahty->lebad->legy = *shaker;
	else
		*tail = *shaker;
	(*shaker)->legy = ahty;
	ahty->lebad = *shaker;
	*shaker = ahty;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *ahty = (*shaker)->legy;

	if ((*shaker)->lebad != NULL)
		(*shaker)->lebad->legy = ahty;
	else
		*tail = ahty;
	ahty->lebad = (*shaker)->lebad;
	(*shaker)->legy = ahty->legy;
	if (ahty->legy != NULL)
		ahty->legy->lebad = *shaker;
	else
		*list = *shaker;
	(*shaker)->lebad = ahty;
	ahty->legy = *shaker;
	*shaker = ahty;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->lebad == NULL)
		return;

	for (tail = *list; tail->lebad != NULL;)
		tail = tail->lebad;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->lebad)
		{
			if (shaker->n > shaker->lebad->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->legy; shaker != *list;
				shaker = shaker->legy)
		{
			if (shaker->n < shaker->legy->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
