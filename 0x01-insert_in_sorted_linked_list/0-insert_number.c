#include "lists.h"
#include <stdlib.h>

/**
 * insert_new - inserts a number into a sorted singly linked list
 * @head: pointer to the head of the list
 * @number: data to be entered
 *
 * Return: address
 */

listint_t *insert_node(listint_t **head, int number)
{
listint_t *tmp = *head, *new;
new  = malloc(sizeof(listint_t));
if (new  == NULL)
return (NULL);
new->n = number;
new->next = NULL;
if (!(*head) || (*head)->n > number)
{
new->next = *head;
*head = new;
return (new);
}
while (tmp->next->n < number)
{
tmp = tmp->next;
if (tmp->next == NULL)
return (NULL);
}

new->next = tmp->next;
tmp->next = new;
return (new);
}
