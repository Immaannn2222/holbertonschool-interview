#ifndef RADIX_H
#define RADIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int find_max(int *arr, size_t n);
void counting_sort(int *array, size_t size, int placment);

#endif
