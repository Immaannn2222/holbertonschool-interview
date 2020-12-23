#include "binary_trees.h"

/**
 * binary_tree_node - adds a new node
 * @parent: parent node
 * @value: value of the new node
 *
 * Return: new node
 **/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new;
new = malloc(sizeof(binary_tree_t));
if (new == NULL)
return (NULL);
new->parent = parent;
new->left = NULL;
new->right = NULL;
new->n = value;
return (new);
}
