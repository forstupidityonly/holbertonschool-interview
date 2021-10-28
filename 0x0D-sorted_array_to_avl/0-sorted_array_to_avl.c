#include "binary_trees.h"
/**
  *
  */
avl_t *newNode(avl_t *parent, size_t i)
{
    avl_t *theNode;

    theNode = malloc(sizeof(avl_t));
    if (!theNode)
        return (NULL);

    theNode->n = i;
    theNode->right = NULL;
    theNode->left = NULL;
    theNode->parent = parent;

    return (theNode);
}

avl_t *createTree(int *array, size_t start, size_t end, avl_t *parent)
{
    size_t mid;
    avl_t *tree;


    if (start > end)
        return (NULL);
    mid = (start + end) / 2;
    tree = newNode(parent, array[mid]);
    if (!tree)
        return (NULL);
    if (start != mid)
        tree->left = createTree(array, start, mid - 1, tree);
    if (end != mid)
        tree->right = createTree(array, mid + 1, end, tree);
    return (tree);
}

avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *tree;

    if(!array)
        return (NULL);
    return (tree = createTree(array, 0, size - 1, NULL));
}
