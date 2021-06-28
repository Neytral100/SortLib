#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void heap_sort(int *array, int size)
{
	int i;
	for (i = size / 2 - 1; i >= 0; i--) {
		heapyfy (array, i, size);
	}
	for (i = size - 1; i > 0; i--) {
		int tmp = array[i];
		array [i] = array [0];
		array [0] = tmp;
		heapyfy (array, 0, i - 1);
	}
}

void heapyfy (int *array, int i, int size)
{
	int li = i * 2 + 1;
	int ri = i * 2 + 2;
	int maxi = i;

	if (li <= size) {
		if (ri <= size) {
			if (array[ri] > array [maxi]) {
				maxi = ri;
			}
		}
		if (array[li] > array[maxi]) {
			maxi = li;
		}
		if (maxi != i) {
			int tmp = array[i];
			array[i] = array[maxi];
			array[maxi] = tmp;
			heapyfy (array, maxi, size);
		}
	}
}