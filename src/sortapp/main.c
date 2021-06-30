#include <stdio.h>
#include <libsort/heap.h>
#include <libsort/insertion.h>
#include <stdlib.h>

int main()
{
	int size = 5;
	int *array = malloc (sizeof(int) * size);

	array [0] = 1;
	array [1] = 7;
	array [2] = 4;
	array [3] = 6;
	array [4] = 0;

	//heap_sort (array, size);

	insertion_sort (array, size);

	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}