#include "sort.h"


/**
 * find_max - finds the maximum of an integer in an array
 * @arr: the array
 * @n: its size
 *
 * Return: max
 */

int find_max(int *arr, size_t n)
{
size_t i;
int max = arr[0];

for (i = 0; i < n; i++)
{
if (arr[i] > max)
max = arr[i];
}
return (max);
}

/**
 * counting_sort - subroutine to sort digits for the radix sorting algo
 *
 * @array: an array
 * @size: its size
 * @placment: the placment of the digit in the new array
 * Return: void
 */

void counting_sort(int *array, size_t size, int placment)
{
size_t i;
int j, x, *rept, *arranged;

rept = malloc(sizeof(int) * (10));
if (!rept)
return;
for (j = 0; j < 10; j++)
rept[j] = 0;
for (i = 0; i < size; i++)
{
j = (array[i] / placment) % 10;
rept[j] += 1;
}
for (j = 0; j < 10; j++)
rept[j] += rept[j - 1];

arranged = malloc(sizeof(int) * size);
if (!arranged)
{
free(rept);
return;
}
for (i = size - 1; (int)i >= 0 ; i--)
for (j = 0; j < 10; j++)
{
if ((array[i] / placment) % 10 == j)
{
x = rept[j] - 1;
rept[j] -= 1;
arranged[x] = array[i];
}
}
for (i = 0; i < size; i++)
array[i] = arranged[i];
free(arranged);
free(rept);
}

/**
*radix_sort -  sorts an array using Radix sort algorithm
*
*@array: array of integers
*@size: size of array
*
*Return:void
*/

void radix_sort(int *array, size_t size)
{
int max;
int post;

if (!array || size < 2)
return;

max = find_max(array, size);
for (post = 1; max / post > 0; post *= 10)
{
counting_sort(array, size, post);
print_array(array, size);
}
}

