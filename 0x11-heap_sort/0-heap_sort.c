#include "sort.h"

/**
*swap - swaps two elements in an array
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
*@arr: the array to arrange
*@n: size of the array
*@i: random
*
*Return: void
*/

void operate_heap(int arr[], int n, int i)
{
int largest = i;
int lefty = 2 * i + 1;
int right = 2 * i + 2;
if (lefty < n && arr[lefty] > arr[largest])
largest = lefty;
if (right < n && arr[right] > arr[largest])
largest = right;
if (largest != i)
{
swap(&arr[i], &arr[largest]);
operate_heap(arr, n, largest);
}
}


/**
 *heap_sort - sorts an array of integers ascendingly
 *
 *@arr: The array to be sorted
 *@size: size of the array
 *Return: void
 *
 */

void heap_sort(int *arr, size_t size)
{
int i;
for (i = size / 2 - 1; i >= 0; i--)
{
operate_heap(arr, size, i);
print_array((const int *)arr, size);
}
for (i = size - 1; i >= 0; i--)
{
swap(&arr[0], &arr[i]);
print_array((const int *)arr, size);
operate_heap(arr, i, 0);
print_array((const int *)arr, size);
}
}
