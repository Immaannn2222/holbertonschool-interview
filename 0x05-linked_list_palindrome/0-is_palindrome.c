#include "lists.h"


/**
 * pali_ndrome - functio to compare two elements in a list(reversely)
 * @begin: double pointer starting from the head of the list
 * @end: double pointer to end node
 *
 * Return: true if identical else false
 */

bool pali_ndrome(listint_t **begin, listint_t *end)
{
bool check, twin;
if (!end)
return (1);
check = pali_ndrome(begin, end->next);
if (!check)
return (0);
twin = (end->n == (*begin)->n);
*begin = (*begin)->next;
return (twin);
}


/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head node
 *
 * Return: 1 if palindrome else 0
 */

int is_palindrome(listint_t **head)
{
if (!(*head) || !head)
return (1);
if (pali_ndrome(&(*head), *head))
return (1);
else
return (0);
}
