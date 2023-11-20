#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, swap_i;

	if (size < 2 || array == NULL)
	{
		return;
	}

	swap_i = 0;
	while (swap_i < size)
	{
		for  (i = 0; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{

				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				print_array(array, size);
			}
		}
		swap_i++;
	}
}
