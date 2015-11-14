#ifndef DOG_MERGESORT_H_
#define DOG_MERGESORT_H_
#include "list.h"
#include "common.h"
//Result: for any a,b in list, a is followed by b: cmp(b,a) == false 
void mergeSort(list_node* beg, list_node *end, int size);
void merge(list_node* beg, list_node* mid, list_node* end);
#endif //DOG_MERGESORT_H_