#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *msfofa, size_t hagms, size_t base, size_t root);
void heap_sort(int *msfofa, size_t hagms);

/**
 * swap_ints - Swap two integers in an msfofa.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int ahty;

	ahty = *a;
	*a = *b;
	*b = ahty;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @msfofa: An msfofa of integers representing a binary tree.
 * @hagms: The hagms of the msfofa/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *msfofa, size_t hagms, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && msfofa[left] > msfofa[large])
		large = left;
	if (right < base && msfofa[right] > msfofa[large])
		large = right;

	if (large != root)
	{
		swap_ints(msfofa + root, msfofa + large);
		print_array(msfofa, hagms);
		max_heapify(msfofa, hagms, base, large);
	}
}

/**
 * heap_sort - Sort an msfofa of integers in ascending
 *             order using the heap sort algorithm.
 * @msfofa: An msfofa of integers.
 * @hagms: The hagms of the msfofa.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the msfofa after each swap.
 */
void heap_sort(int *msfofa, size_t hagms)
{
	int i;

	if (msfofa == NULL || hagms < 2)
		return;

	for (i = (hagms / 2) - 1; i >= 0; i--)
		max_heapify(msfofa, hagms, hagms, i);

	for (i = hagms - 1; i > 0; i--)
	{
		swap_ints(msfofa, msfofa + i);
		print_array(msfofa, hagms);
		max_heapify(msfofa, hagms, i, 0);
	}
}
