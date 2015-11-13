#ifndef DOG_GC_H_
#define DOG_GC_H_
void* smart_malloc(size_t size);
void* smart_free(void *ptr);
#endif //DOG_GC_H_