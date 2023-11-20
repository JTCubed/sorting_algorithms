#include "sort.h"
/**
 * insertion_sort_list - sorts doubly linked list using the
 * insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *tmp, *tmp2;

	if (list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;
	while (cur != NULL)
	{
		if (cur->prev != NULL)
		{
			if (cur->n < cur->prev->n)
			{
				tmp = cur;
				while (tmp->prev != NULL && tmp->n < tmp->prev->n)
				{
					tmp2 = tmp->prev;
					tmp->prev = tmp2->prev;
					tmp2->next = tmp->next;
					if (tmp->next != NULL)
						tmp->next->prev = tmp2;

					tmp2->prev = tmp;
					tmp->next = tmp2;
					if (tmp->prev != NULL)
						tmp->prev->next = tmp;
					else
						*list = tmp;

					print_list(*list);
				}
			}
		}
		cur = cur->next;
	}
}
