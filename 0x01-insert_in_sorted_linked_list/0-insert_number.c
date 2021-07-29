#include "lists.h"
#include <stdlib.h>
/**
  * @head: head of sorted singly linked list
  * @number: the number to insert into list
  * Return: @new_node or null
  */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *node_ptr = *head;
    listint_t *new_node = malloc(sizeof(listint_t));

    if (!new_node)
        return (NULL);
    new_node->n = number;
    new_node->next = NULL;
    if (!node_ptr || new_node->n < node_ptr->n)
    {
        new_node->next = node_ptr;
        *head = new_node;
        return (*head);
    }
    while (node_ptr)
    {
        if (!node_ptr->next || new_node->n < node_ptr->next->n)
        {
            new_node->next = node_ptr->next;
            node_ptr->next = new_node;
            return (node_ptr);
        }
        node_ptr = node_ptr->next;
    }
    return (NULL);
}
