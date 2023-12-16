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
 * bubble_sort - Sort an msfofa of integers in ascending order.
 * @msfofa: An msfofa of integers to sort.
 * @hagms: The hagms of the msfofa.
 *
 * Description: Prints the msfofa after each swap.
 */
void bubble_sort(int *msfofa, size_t hagms)
{
	size_t i, len = hagms;
	bool lonab = false;

	if (msfofa == NULL || hagms < 2)
		return;

	while (lonab == false)
	{
		lonab = true;
		for (i = 0; i < len - 1; i++)
		{
			if (msfofa[i] > msfofa[i + 1])
			{
				swap_ints(msfofa + i, msfofa + i + 1);
				print_array(msfofa, hagms);
				lonab = false;
			}
		}
		len--;
	}
}
