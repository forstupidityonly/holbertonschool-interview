#include "search_algos.h"
/**
  * print_now - helper
  * @array: the array
  * @left: left integer
  * @right: right integer
  * Return: void
  */
void print_now(int *array, unsigned long int left, unsigned long int right)
{
	printf("Searching in array: ");
	for (; left <= right; left++)
	{
		if (left == right)
			printf("%d\n", array[left]);
		else
			printf("%d, ", array[left]);
	}
}
/**
  * binary_search - recursive
  * @a: array
  * @t: target
  * @l: left
  * @r: right
  * Return: int
  */
int binary_search(int *a, int t, int l, int r)
{
	int tmp;

	if (l == r)
	{
		if (a[l] != t)
		{
			print_now(a, l, r);
			return (-1);
		}
		return (l);
	}
	print_now(a, l, r);
	tmp = (l + r) / 2;
	if (a[tmp] < t)
		l = tmp + 1;
	else
		r = tmp;
	return (binary_search(a, t, l, r));
}
/**
  * advanced_binary - adv
  * @array: array
  * @size: size
  * @value: target
  * Return: idx of target or -1 or 0
  */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || !size)
		return (-1);
	return (binary_search(array, value, 0, size - 1));
}
