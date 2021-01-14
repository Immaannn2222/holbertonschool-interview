#include "sandpiles.h"

/**
*verify - verify
*@sandpiles: grid to check
*Return: 0 or 1
*/

int verify(int sandpiles[3][3])
{
int i, j;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (sandpiles[i][j] > 3)
return (0);
}
}
return (1);
}


/**
*print_grid1 - print the grid
*@sandpiles: the grid to print
*
*Return: void
*/
void print_grid1(int sandpiles[3][3])
{
int i, j;
printf("=\n");
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
printf("%d", sandpiles[i][j]);
if (j < 2)
printf(" ");
}
printf("\n");
}
}

/**
* stablise - stabilize the sum
*
*@sandpiles: grid1
*@tmp: grid2
*
*Return:void
*/
void stablise(int sandpiles[3][3], int tmp[3][3])
{
int i, j;
for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
tmp[i][j] = sandpiles[i][j];
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (tmp[i][j] >= 4)
{
sandpiles[i][j] = sandpiles[i][j] - 4;
if (i >= 1)
sandpiles[i - 1][j] += 1;
if (i <= 1)
sandpiles[i + 1][j] += 1;
if (j >= 1)
sandpiles[i][j - 1] += 1;
if (j <= 1)
sandpiles[i][j + 1] += 1;
}
}
}
}


/**
*_sum - sum of two sandpiles
*
*@grid1: the grid1
*@grid2: the grid2
*
*Return: void
*/
void _sum(int grid1[3][3], int grid2[3][3])
{
int tmp[3][3];
int i, j;
for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
grid1[i][j] += grid2[i][j];
{
print_grid1(grid1);
stablise(grid1, tmp);
}
}
