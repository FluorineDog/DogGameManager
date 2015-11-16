#ifndef DOG_MERGESORT_H_
#define DOG_MERGESORT_H_
#include "list.h"
#include "common.h"
//Result: for any a,b in list, a is followed by b: cmp(b,a) == false 
void mergeSort(iter_t beg, iter_t end, int size, cmp_t compare);
void mergeSortPart(iter_t beg, iter_t end, int size);
void merge(iter_t beg, iter_t mid, iter_t end);
#endif //DOG_MERGESORT_H_
