#include <stdlib.h>
#include <stdio.h>

/**
 * print_msfofa - Prints an msfofa of integers
 *
 * @msfofa: The msfofa to be printed
 * @hagms: Number of elements in @msfofa
 */
void print_msfofa(const int *msfofa, size_t hagms)
{
	size_t i;

	i = 0;
	while (msfofa && i < hagms)
	{
		if (i > 0)
			printf(", ");
		printf("%d", msfofa[i]);
		++i;
	}
	printf("\n");
}
