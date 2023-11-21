#include "sort.h"
/**
 * quicksort_recursive - recuresive application after partition
 * @array: array to be sorted
 * @size: size of the array
 * @lo: start of the array
 * @hi: end of the array
 */
void quicksort_recursive(int *array, int lo, int hi, size_t size)
{
	int p;
	if (lo < hi)
	{
		p = partition_(array, lo, hi, size);
		quicksort_recursive(array, lo, p - 1, size);
		quicksort_recursive(array, p + 1, hi, size);

	}

}

/**
 * quick_sort - a call to quicksort_recursive
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);

}

/**
 * partition_ - recuresive application after partition
 * @array: array to be sorted
 * @size: size of the array
 * @lo: start of the array
 * @hi: end of the array
 * Return: pivot index
 */

int partition_(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];

	int i, tmp;
	int cur = lo - 1;

	for (i = lo; i < hi; i++)
	{
		if (array[i] <= pivot)
		{
			cur++;
			tmp = array[i];
			array[i] = array[cur];
			array[cur] = tmp;
		}
	}
	tmp = array[cur + 1];
	array[cur + 1] = array[hi];
	array[hi] = tmp;
	print_array(array, size);
	return (cur + 1);
}
