void heap_sort(void * array, size_t number, size_t size, int ( * comparator ) ( const void *, const void * ));
void heapyfy (void *array, int i, size_t number, size_t size, int ( * comparator ) ( const void *, const void * ));
void swap (void * val1, void * val2, size_t size);