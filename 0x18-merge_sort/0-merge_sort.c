#include "sort.h"


/**
 * merge - merges two subarrays
 * @array: the array to be sorted
 * @arr: a pointer tothe temporary array
 * @s: the starting index
 * @m: the middle index
 * @e: the finishing index
 */
void merge(int *array, int *arr, int s, int m, int e)
{
int i = s, j = m, k = s;

printf("Merging...\n");
printf("[left]: ");
print_array((const int *)&arr[s], m - s);
printf("[right]: ");
print_array((const int *)&arr[m], e - m + 1);
while (i < m && j <= e)
{
if (arr[i] < arr[j])
{
array[k] = arr[i];
i++;
k++;
}
else
{
array[k] = arr[j];
j++;
k++;
}
}
while (i < m)
{
array[k] = arr[i];
i++;
k++;
}
while (j <= e)
{
array[k] = arr[j];
j++;
k++;
}
printf("[Done]: ");
for (i = s; i <= e; i++)
arr[i] = array[i];
print_array((const int *)&array[s], e - s + 1);
}

/**
 * split - splits into subarrays(2nd step)
 * @array: main array
 * @arr: pointer to a copy of the array
 * @s: index of s element
 * @end: index of end element
 */
void split(int *array, int *arr, int s, int end)
{
int size, mid;

size = end - s + 1;
if (size < 2)
return;
mid = (size / 2) + s;
split(array, arr, s, mid - 1);
split(array, arr, mid, end);
merge(array, arr, s, mid, end);
}

/**
* merge_sort - sorts an array of integers in ascsizeing order
* @array: pointer to the array to be sorted
* @size: the size of the array
*
*Return: void
*/

void merge_sort(int *array, size_t size)
{
int i;
int *arr;
if (!array)
return;
arr = malloc(sizeof(int) * size);
if (!arr)
return;
for (i = 0; i < (int)size; i++)
arr[i] = array[i];
split(array, arr, 0, (int)(size - 1));
free(arr);
}

