#include "menger.h"
#include <stdio.h>
#include <stdlib.h>
#include<math.h>


/**
* menger - represents factral menger sponges
* @level: the level
*
* Return: void
**/

void menger(int level)
{
int i, j, size, x;
size = pow(3, level);

for (i = 0; i < size; i++)
{
for (j = 0; j < size; j++)
{
for (x = size / 3; x; x /= 3)
if ((i % (x * 3)) / x == 1 && (j % (x * 3)) / x == 1)
break;
printf(x ? " " : "#");
}
printf("\n");
}
}
