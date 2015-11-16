#include <stdlib.h>
#include "gc.h"
// static struct {
// 	int size;
// 	int capacity;
// 	void *data;
// }memory;

// no time to invent a better wheel.
void* smart_malloc(size_t size){
	return malloc(size);
}
void smart_free(void *ptr){
	free(ptr);
}

void do_nothing(void* ptr){}