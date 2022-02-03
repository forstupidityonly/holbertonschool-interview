#include "binary_trees.h"
/**
	* heap_extract - extract the root node
	* @root: double ptr to root node
	* Return: val stored in the root node
	*/
int heap_extract(heap_t **root)
{
	if (!root || !*root)
		return (0);
	return ((*root)->n);
}
