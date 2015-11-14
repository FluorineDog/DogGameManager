#include <stdlib.h>
static struct {
	int size;
	int capacity;
	void *data;
}memory;
void* smart_malloc(size_t size){
	return malloc(size);
}