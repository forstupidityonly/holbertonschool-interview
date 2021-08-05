#include "binary_trees.h"
#include <stdlib.h>
/**
  * binary_tree_node - creates a binary tree node
  * @parent: ptr to the parent node of the node to create
  * @value: value to put in the new node
  * Return: ptr to new node or NULL
  */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = NULL;

    new_node = calloc(1, sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);
    new_node->parent = parent;
    new_node->n = value;
    return (new_node);
}
