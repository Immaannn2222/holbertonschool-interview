#include "binary_trees.h"

/**
 * get_size - returns the size of a heap
 * @root: the first node of the heap
 *
 * Return: heap's size
 */

int get_size(heap_t *root)
{
if (!root)
return (0);
else
return (taille_arb(root->left) + 1 + taille_arb(root->right));
}

/**
 * arr_convert - converts a heap into an array
 * @array: array
 * @root: first node of the heap
 * @x: whree to fill
 *
 * Return: void
 */
void arr_convert(heap_t **array, heap_t *root, int x)
{
array[x] = root;
if (root)
{
arr_convert(array, root->left, (x * 2) + 1);
arr_convert(array, root->right, (x * 2) + 2);
}
}

/**
 * reconstruct_heap - rebuilds a heap
 * @node: root of the heap
 *
 * Return: void
 */

void reconstruct_heap(heap_t *node)
{
int tempo;

if (!node->left)
{
return;
}
else if (!node->right || node->left->n >= node->right->n)
{
if (node->n < node->left->n)
{
tempo = node->n;
node->n = node->left->n;
node->left->n = tempo;
}
reconstruct_heap(node->left);
}
else if (node->left->n < node->right->n)
{
if (node->n < node->right->n)
{
tempo = node->n;
node->n = node->right->n;
node->right->n = tempo;
}
reconstruct_heap(node->right);
}
}

/**
* heap_extract - extracts the root node of a Max Binary Heap
* @root: double pointer to the root node of the heap
*
* Return: value stored in the root node or 0 on fail
*/

int heap_extract(heap_t **root)
{
int i, n, size;
heap_t **array;

if (!root || !*root)
return (0);
n = (*root)->n;
size = get_size(*root);
array = malloc(1024 * sizeof(heap_t *));
if (!array)
return (0);
for (i = 0; i < size; i++)
array[i] = NULL;
arr_convert(array, *root, 0);
if (array[size - 1] == (*root))
{
free(array);
free(*root);
*root = NULL;
return (n);
}
(*root)->n = array[size - 1]->n;
if (array[size - 1]->parent->left == array[size - 1])
array[size - 1]->parent->left = NULL;
else
array[size - 1]->parent->right = NULL;
free(array[size - 1]);
free(array);
reconstruct_heap(*root);
return (n);
}
