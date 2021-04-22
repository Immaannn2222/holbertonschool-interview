#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void operate_heap(int arr[], int n, int i);
void swap(int *a, int *b);

#endif
