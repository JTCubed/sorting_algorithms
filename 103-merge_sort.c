#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays of array.
 * @array: The array to be sorted.
 * @temp: A temporary array to store the merged result.
 * @start: The starting index of the first subarray.
 * @mid: The ending index of the first subarray and the starting index of the
 * second subarray.
 * @end: The ending index of the second subarray.
 */
void merge(int *array, int *temp, size_t start, size_t mid, size_t end)
{

	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);

	printf("[right]: ");
	print_array(array + mid, end - mid);

	i = start;
	j = mid;
	k = 0;

	while (i < mid && j < end)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];

	while (j < end)
		temp[k++] = array[j++];

	for (i = 0, k = start; k < end; i++, k++)
		array[k] = temp[i];

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_sort_recursive - Recursive function to apply merge sort.
 * @array: The array to be sorted.
 * @temp: A temporary array to store the merged result.
 * @start: The starting index of the subarray.
 * @end: The ending index of the subarray.
 */
void merge_sort_recursive(int *array, int *temp, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = (start + end) / 2;
		merge_sort_recursive(array, temp, start, mid);
		merge_sort_recursive(array, temp, mid, end);
		merge(array, temp, start, mid, end);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge
 * sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}
