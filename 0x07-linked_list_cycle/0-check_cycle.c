#include "lists.h"
/**
  * check_cycle - find loops
  * @list: head
  * Return: 0 1
  * if hi laps lag then there must be a loop if there is not hi will finish
  * the race
  */
int check_cycle(listint_t *list)
{
	listint_t *lag, *hi_fps;

	lag = list;
	hi_fps = list;
	while (lag && hi_fps && hi_fps->next)
	{
		hi_fps = hi_fps->next->next;
		lag = lag->next;
		if (lag == hi_fps)
			return(1);
	}
	return(0);
}
