#include "sort.h"
/**
  * swap - swap items
  * @i: item 1
  * @j: item 2
  * Return: None
  */
void swap(int *i, int *j)
{
	int tmp = *j;
	*j = *i;
	*i = tmp;
}
/**
  * heapify - build heap from array
  * @array: the array
  * @i: heap size
  * @j: root idx
  * @size: items in array
  * Return: None
  */
void heapify(int *array, int j, int i, size_t size)
{
	int maximum = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;

	if (left < j && array[left] > array[maximum])
		maximum = left;
	if (right < j && array[right] > array[maximum])
		maximum = right;
	if (maximum != i)
	{
		swap(&array[i], &array[maximum]);
		print_array(array, size);
		heapify(array, j, maximum, size);
	}
}
/**
  * heap_sort - sort srray with sift-down heap sort
  * @array: the array
  * @size: size of array
  * Return: None
  */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}
