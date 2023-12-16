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
	int msfofa[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(msfofa) / sizeof(msfofa[0]);

	print_array(msfofa, n);
	printf("\n");
	heap_sort(msfofa, n);
	printf("\n");
	print_array(msfofa, n);
	return (0);
}
