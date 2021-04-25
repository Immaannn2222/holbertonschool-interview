#include "sort.h"

/**
*swap - swaps two elements in an arr
*@a: pointer to the first element
*@b: pointer to the second element
*
*Return: void
*/

void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
*operate_heap - finds the largest
*@arr: the arr to arrange
*@n: size of the arr
*@i: random
*@size: the size of the array
*Return: void
*/

void operate_heap(int arr[], int n, size_t size, int i)
{
int largest = i;
int lefty = 2 * i + 1;
int righty = 2 * i + 2;

if (lefty < n && arr[lefty] > arr[largest])
largest = lefty;
if (righty < n && arr[righty] > arr[largest])
largest = righty;

if (largest != i)
{
swap(&arr[i], &arr[largest]);
print_array(arr, size);
operate_heap(arr, n, size, largest);
}
}

/**
 *heap_sort - sorts an arr of integers ascendingly
 *
 *@arr: The arr to be sorted
 *@size: size of the arr
 *Return: void
 *
 */

void heap_sort(int *arr, size_t size)
{
int i;
if (!arr)
return;
for (i = size / 2 - 1; i >= 0; i--)
operate_heap(arr, size, size, i);

for (i = size - 1; i > 0; i--)
{
swap(&arr[0], &arr[i]);
print_array(arr, size);
operate_heap(arr, i, size, 0);
}
swap(&arr[0], &arr[i]);
operate_heap(arr, i, size, 0);
}
