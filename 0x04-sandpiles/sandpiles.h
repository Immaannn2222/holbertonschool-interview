#ifndef sand_pile
#define sand_pile
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int check_grid(int sandpiles[3][3]);
void prin_t(int sandpiles[3][3]);
void stable(int sandpiles[3][3], int tmp[3][3]);
#endif
