#include "mergeSort.h"
#include <stdio.h>
static cmp_t cmp;
void mergeSort(iter_t beg, iter_t end, int size, cmp_t compare){
	cmp = compare;
	mergeSortPart(beg, end, size);
}
void mergeSortPart(iter_t beg, iter_t end, int size){
	if(size <= 1)
		return; 
	iter_t mid = beg;
	for(int i = 0; i < size/2 ; ++i){
		mid = mid->m_next;
	}
	// size/2 + (size+1)/2 = size
	// store beg's prev in advance, which is unchangable, to get a new beg 
	iter_t header = beg->m_prev;			
	mergeSortPart(beg, mid, size/2);
	
	// similiarly
	iter_t pre_mid = mid->m_prev;			
	mergeSortPart(mid, end, (size+1)/2);
	
	// restore
	merge(header->m_next, pre_mid->m_next, end);
}
void merge(iter_t beg, iter_t mid, iter_t end){
	iter_t iter1 = beg;
	iter_t iter2 = mid;
	while(iter1 != iter2 && iter2 != end){
		if(cmp(iter2->m_pdata, iter1->m_pdata)){
			iter_t tmp = iter2;
			iter2 = iter2->m_next;
			list_move(tmp,iter1);
		}
		else 
			iter1 = iter1->m_next;
	}
}
