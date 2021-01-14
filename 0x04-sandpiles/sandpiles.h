#ifndef sand_pile
#define sand_pile
#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void stablise(int sandpiles[3][3], int tmp[3][3]);
void print_grid1(int sandpiles[3][3]);
int verify(int sandpiles[3][3]);

#endif
