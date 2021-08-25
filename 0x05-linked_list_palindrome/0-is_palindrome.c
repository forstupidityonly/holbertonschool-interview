#include "lists.h"
/**
  * is_palindrome - checks if a singly linked list is a palindrome.
  * @head: ptr to the head
  * Return: 0 or 1 for yes or no
  */
int is_palindrome(listint_t **head)
{
    int length = get_list_length(head);
    int i = 0;
    int bow;
    int stern;

    if (!head)
        return (1);
    while (i < (length/2))
    {
        bow = GetNth(head, i);
        stern = GetNth(head, (length - i - 1));
        if (bow != stern)
            return (0);
        i++;
    }
    return (1);
}


int get_list_length(listint_t **head)
{
    listint_t *current = *head;
    int count = 0;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return (count);
}


int GetNth(listint_t **head, int index)
{
    listint_t *current = *head;
    int count = 0;

    while (current != NULL)
    {
        if (count == index)
            return (current->n);
        count++;
        current = current->next;
    }
    /* if we get to this line, the caller was asking for a non-existent
    element so we assert fail */
    assert(0);
}
