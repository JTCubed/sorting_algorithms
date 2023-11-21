#include "sort.h"

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t lowest;
	int tmp2;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		lowest = i;
		for (j = i + 1; j < size; j++)
		{

			if (array[j] < array[lowest])
			{
				lowest = j;
			}
		}
		if (lowest != i)
		{
			tmp2 = array[i];
			array[i] = array[lowest];
			array[lowest] = tmp2;
			print_array(array, size);
		}
	}

}
