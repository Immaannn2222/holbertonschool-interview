#include "list.h"


/**
* add_node_end - adds a new node to the end of a double circular linked list
* @list: double ointer to the list
* @str: the string to copy into the new node
*
* Return: Address of the new node, or NULL on failure
*/
List *add_node_end(List **list, char *str)
{
List *new_end = NULL;
List *temp;

new_end = malloc(sizeof(List));
if (!new_end)
return (NULL);
new_end->str = strdup(str);
if (new_end->str == NULL)
return (NULL);
if (list == NULL || (*list) == NULL)
{
*list = new_end;
(*list)->next = *list;
(*list)->prev = *list;
return (new_end);
}
temp = *list;
while (temp)
{
if (temp->next == *list)
break;
temp = temp->next;
}
new_end->next = temp->next;
temp->next = new_end;
new_end->prev = temp;
new_end->next->prev = new_end;
return  (new_end);
}


/**
* add_node_begin - adds a new node to the beginning of the list
* @list: double ointer to the list
* @str: the string to copy into the new node
*
* Return: Address of the new node, or NULL on failure
*/
List *add_node_begin(List **list, char *str)
{
List *new_start = NULL;

new_start = malloc(sizeof(List));
if (!new_start)
return (NULL);
new_start->str = strdup(str);
if (new_start->str == NULL)
return (NULL);
if (list == NULL || (*list) == NULL)
{
*list = new_start;
(*list)->next = *list;
(*list)->prev = *list;
return (new_start);
}
new_start->next = *list;
new_start->prev = (*list)->prev;
(*list)->prev = new_start;
new_start->prev->next = new_start;
(*list) = new_start;
return (new_start);
}
