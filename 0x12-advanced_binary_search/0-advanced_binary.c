#include "search_algos.h"

/**
*advanced_binary - searches for a value in a sorted array of integers
*@array: pointer to the first element of the array to search in
*@size: number of elements in array
*@value: value to search for
*
*Return: index where value is located
*/

int advanced_binary(int *array, size_t size, int value)
{
if (!array)
return (-1);
int tortoise;
size_t i;
for (i = 0; i <= size; i++)
{
tortoise = array[0];
value = array[array[0]];
while (tortoise != value)
{
tortoise = array[tortoise];
value = array[array[value]];
}
value = 0;
while (tortoise != value)
{
tortoise = array[tortoise];
value = array[value];
}
}
return (value);
printf("%d", value);
}
