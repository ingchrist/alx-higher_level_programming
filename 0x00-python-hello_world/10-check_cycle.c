#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has
 * a cycle in it
 * @list: pointer to the list
 * Return: 0 if there is no cycle,
 * 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *wz;
	listint_t *wzq;

	wz = list;
	wzq = list;
	while (list && wz && wz->next)
	{
		list = list->next;
		wz = wz->next->next;

		if (list == wz)
		{
			list = wzq;
			wzq =  wz;
			while (1)
			{
				wz = wzq;
				while (wz->next != list && wz->next != wzq)
				{
					wz = wz->next;
				}
				if (wz->next == list)
					break;

				list = list->next;
			}
			return (1);
		}
	}

	return (0);
}
