#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*
	array - указатель на массив
	number - кол-во элементов в массиве
	size - размер элемента
	comparator - указатель на функцию сравнения
*/

void insertion_sort(void * array, size_t number, size_t size, int ( * comparator ) ( const void *, const void * ))
{
	void * key = malloc (size);
	int j;
	for (int i = 1; i < (int)number; i++){
		memcpy(key, (array + i * size), size);
		j = i-1;
		while ((j >= 0) && ((comparator ((array + j * size), key)) > 0)) {
			memcpy((array + (j + 1) * size), (array + j * size), size);
			j--;
		}
		memcpy((array + (j + 1) * size), key, size);
	}
}