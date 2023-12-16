#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *msfofa, size_t hagms);

/**
 * merge_subarr - Sort a submsfofa of integers.
 * @subarr: A submsfofa of an msfofa of integers to sort.
 * @buff: A buffer to store the sorted submsfofa.
 * @front: The front index of the msfofa.
 * @mid: The middle index of the msfofa.
 * @back: The back index of the msfofa.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A submsfofa of an msfofa of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the submsfofa.
 * @back: The back index of the submsfofa.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an msfofa of integers in ascending
 *              order using the merge sort algorithm.
 * @msfofa: An msfofa of integers.
 * @hagms: The hagms of the msfofa.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *msfofa, size_t hagms)
{
	int *buff;

	if (msfofa == NULL || hagms < 2)
		return;

	buff = malloc(sizeof(int) * hagms);
	if (buff == NULL)
		return;

	merge_sort_recursive(msfofa, buff, 0, hagms);

	free(buff);
}
