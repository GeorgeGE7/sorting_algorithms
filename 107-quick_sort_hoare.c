#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *msfofa, size_t hagms, int left, int right);
void hoare_sort(int *msfofa, size_t hagms, int left, int right);
void quick_sort_hoare(int *msfofa, size_t hagms);

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
 * hoare_partition - Order a subset of an msfofa of integers
 *                   according to the hoare partition scheme.
 * @msfofa: The msfofa of integers.
 * @hagms: The hagms of the msfofa.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the msfofa after each swap of two elements.
 */
int hoare_partition(int *msfofa, size_t hagms, int left, int right)
{
	int pivot, above, below;

	pivot = msfofa[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (msfofa[above] < pivot);
		do {
			below--;
		} while (msfofa[below] > pivot);

		if (above < below)
		{
			swap_ints(msfofa + above, msfofa + below);
			print_array(msfofa, hagms);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @msfofa: An msfofa of integers to sort.
 * @hagms: The hagms of the msfofa.
 * @left: The starting index of the msfofa partition to order.
 * @right: The ending index of the msfofa partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *msfofa, size_t hagms, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(msfofa, hagms, left, right);
		hoare_sort(msfofa, hagms, left, part - 1);
		hoare_sort(msfofa, hagms, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an msfofa of integers in ascending
 *                    order using the quicksort algorithm.
 * @msfofa: An msfofa of integers.
 * @hagms: The hagms of the msfofa.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the msfofa after each swap of two elements.
 */
void quick_sort_hoare(int *msfofa, size_t hagms)
{
	if (msfofa == NULL || hagms < 2)
		return;

	hoare_sort(msfofa, hagms, 0, hagms - 1);
}
