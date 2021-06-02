#include "lists.h"

/**
* find_listint_loop - finds the loop in a linked list
* @head: head of the list
*
* Return: The address of the node where the loop starts, or NULL
*/

listint_t *find_listint_loop(listint_t *head)
{
listint_t *slowy = head, *fasty = head;
if (head == NULL || head->next == NULL)
return (NULL);
while (fasty->next && fasty->next->next)
{
slowy = slowy->next;
fasty = fasty->next->next;
if (slowy == fasty)
{
slowy = head;
while (fasty != NULL)
{
if (slowy == fasty)
return (slowy);
slowy = slowy->next;
fasty = fasty->next;
}
}
}
return (NULL);
}
