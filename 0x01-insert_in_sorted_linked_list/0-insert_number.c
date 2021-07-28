#include "lists.h"
#include <stdlib.h>
/**
  * @head: head of sorted singly linked list
  * @number: the number to insert into list
  * Return: @new_node or null
  */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *node_ptr_1 = *head;
    listint_t *node_ptr_2 = (*head)->next;
    listint_t *new_node;
    
    if (!head || !number)
        return (NULL);
    new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return (NULL);
    else
        new_node->n = number;
    if (node_ptr_1->n > number)
    {
        new_node->next = node_ptr_1;
        return (new_node);
    }
    while (node_ptr_2)
    {
        if (node_ptr_1->n < number && node_ptr_2->n > number)
        {
            node_ptr_1->next = new_node;
            new_node->next = node_ptr_2;
            return (new_node);
        }
        else
        {
            node_ptr_1 = node_ptr_1->next;
            node_ptr_2 = node_ptr_2->next;
        }
    }
    node_ptr_1->next = new_node;
    new_node->next = NULL;
    return (new_node);
}
