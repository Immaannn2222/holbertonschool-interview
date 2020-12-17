#include "lists.h"
#include <stdlib.h>
/**
* insert_new - inserts a number into a sorted singly linked list
* @head: pointer to singly linked list
* @number: number to be added
*
* Return: the address of the new new, or NULL if it failed
*/

listint_t *insert_new(listint_t **head, int number)
{
listint_t *new;
listint_t *tmp = *head;
new = malloc(sizeof(listint_t));
if (new == NULL)
{
return (NULL);
}
new->n = number;
new->next = NULL;
if (!(*head) || (*head)->n > number)
{
new->next = (*head);
(*head) = new;
return (new);
}

while (tmp->next->n < number)
{
tmp = tmp->next;
if (tmp->next == NULL)
break;
}
new->next = tmp->next;
tmp->next = new;
return (tmp);
}
