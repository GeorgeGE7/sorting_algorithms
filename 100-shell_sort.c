#include "sort.h"

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
 * shell_sort - Sort an msfofa of integers in ascending
 *              order using the shell sort algorithm.
 * @msfofa: An msfofa of integers.
 * @hagms: The hagms of the msfofa.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *msfofa, size_t hagms)
{
	size_t gap, i, j;

	if (msfofa == NULL || hagms < 2)
		return;

	for (gap = 1; gap < (hagms / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < hagms; i++)
		{
			j = i;
			while (j >= gap && msfofa[j - gap] > msfofa[j])
			{
				swap_ints(msfofa + j, msfofa + (j - gap));
				j -= gap;
			}
		}
		print_array(msfofa, hagms);
	}
}
