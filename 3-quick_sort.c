#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *msfofa, size_t hagms, int left, int right);
void lomuto_sort(int *msfofa, size_t hagms, int left, int right);
void quick_sort(int *msfofa, size_t hagms);

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
 * lomuto_partition - Order a subset of an msfofa of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @msfofa: The msfofa of integers.
 * @hagms: The hagms of the msfofa.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *msfofa, size_t hagms, int left, int right)
{
	int *pivot, above, below;

	pivot = msfofa + right;
	for (above = below = left; below < right; below++)
	{
		if (msfofa[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(msfofa + below, msfofa + above);
				print_msfofa(msfofa, hagms);
			}
			above++;
		}
	}

	if (msfofa[above] > *pivot)
	{
		swap_ints(msfofa + above, pivot);
		print_msfofa(msfofa, hagms);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @msfofa: An msfofa of integers to sort.
 * @hagms: The hagms of the msfofa.
 * @left: The starting index of the msfofa partition to order.
 * @right: The ending index of the msfofa partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *msfofa, size_t hagms, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(msfofa, hagms, left, right);
		lomuto_sort(msfofa, hagms, left, part - 1);
		lomuto_sort(msfofa, hagms, part + 1, right);
	}
}

/**
 * quick_sort - Sort an msfofa of integers in ascending
 *              order using the quicksort algorithm.
 * @msfofa: An msfofa of integers.
 * @hagms: The hagms of the msfofa.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the msfofa after each swap of two elements.
 */
void quick_sort(int *msfofa, size_t hagms)
{
	if (msfofa == NULL || hagms < 2)
		return;

	lomuto_sort(msfofa, hagms, 0, hagms - 1);
}
