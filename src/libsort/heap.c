#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include <string.h>

void heap_sort(void * array, size_t number, size_t size, int ( * comparator ) ( const void *, const void * ))
{
	int i;
	for (i = number / 2 - 1; i >= 0; i--)
		heapyfy (array, i, number, size, comparator);
	for (i = number - 1; i > 0; i--) {
		swap ((array + i * size), array, size);
		heapyfy (array, 0, i - 1, size, comparator);
	}
}

void heapyfy (void *array, int i, size_t number, size_t size, int ( * comparator ) ( const void *, const void * ))
{
	int li = i * 2 + 1;
	int ri = i * 2 + 2;
	int maxi = i;

	if (li <= (int)number) {
		if (ri <= (int)number)
			if (comparator((array + ri * size), (array + maxi * size)) > 0)
				maxi = ri;
		if (comparator((array + li * size), (array + maxi * size)) > 0)
			maxi = li;
		if (maxi != i) {
			swap((array + i * size), (array + maxi * size), size);
			heapyfy (array, maxi, number, size, comparator);
		}
	}
}

void swap (void * val1, void * val2, size_t size)
{
	void * tmp = malloc (size);
	memcpy(tmp, val1, size);
	memcpy(val1, val2, size);
	memcpy(val2, tmp, size);
}