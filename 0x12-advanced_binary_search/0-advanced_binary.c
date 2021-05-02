#include "search_algos.h"


/**
* print_array - Prints an array of integers
*
* @array: The array to be printed
* @size: Number of elements in @array
* @i: posution of the print
*/
void print_array(int *array, size_t i, size_t size)
{
if (i > size)
return;
printf("%d", array[i]);
if (i < size)
printf(", ");
print_array(array, i + 1, size);
}


/**
* advanced_binary - searches for a value in a sorted array of integers
* @array: pointer to the first element of the array to search in
* @size: number of elements in array
* @value: the value to search for
*
* Return: return the index where value is located
*/

int advanced_binary(int *array, size_t size, int value)
{
size_t bottom = 0;
size_t highest = size - 1;
size_t m;

if (!array)
return (-1);
while (bottom <= highest)
{
printf("Searching in array: ");
print_array(array, bottom, highest);
printf("\n");

m = (bottom + highest) / 2;
if (array[m] == value && array[m - 1] != value)
return (m);
else if (array[m] < value)
bottom = m + 1;
else
highest = m;
}
return (-1);
}


