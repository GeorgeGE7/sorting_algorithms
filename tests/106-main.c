#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int msfofa[] = {100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13};
	size_t n = sizeof(msfofa) / sizeof(msfofa[0]);

	print_msfofa(msfofa, n);
	printf("\n");
	bitonic_sort(msfofa, n);
	printf("\n");
	print_msfofa(msfofa, n);
	return (0);
}
