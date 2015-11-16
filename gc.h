#ifndef DOG_GC_H_
#define DOG_GC_H_
#include "common.h"
void* smart_malloc(size_t size);
void smart_free(void *ptr);
void do_nothing(void *ptr);
#endif //DOG_GC_H_
