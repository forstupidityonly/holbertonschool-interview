#include "lists.h"
/**
  *  find_listint_loop - floyds algorithm
  *  @head: the head of the list
  *  Return: NUll or beginning of loop
  */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *raceCar = head;
	listint_t *paceCar = head;

	if (!head || !head->next)
		return (NULL);
	while (raceCar->next->next && paceCar->next)
	{
		raceCar = raceCar->next->next;
		paceCar = paceCar->next;
		if (raceCar == paceCar)
		{
			paceCar = head;
			while (paceCar != raceCar)
			{
				paceCar = paceCar->next;
				raceCar = raceCar->next;
			}
			return (paceCar);
		}
	}
	return (NULL);
}
