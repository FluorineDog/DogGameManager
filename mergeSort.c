#include "mergeSort.h"
#include <stdio.h>
static cmp_t cmp;
void mergeSort(list_node *beg, list_node *end, int size, cmp_t compare){
	cmp = compare;
	mergeSortPart(beg, end, size);
}
void mergeSortPart(list_node *beg, list_node *end, int size){
	if(size <= 1)
		return; 
	list_node* mid = beg;
	for(int i = 0; i < size/2 ; ++i){
		mid = mid->m_next;
	}
	// size/2 + (size+1)/2 = size
	// store beg's prev in advance, which is unchangable, to get a new beg 
	list_node* header = beg->m_prev;			
	mergeSortPart(beg, mid, size/2);
	
	// similiarly
	list_node* pre_mid = mid->m_prev;			
	mergeSortPart(mid, end, (size+1)/2);
	
	// restore
	merge(header->m_next, pre_mid->m_next, end);
}
void merge(list_node* beg, list_node* mid, list_node* end){
	list_node *iter1 = beg;
	list_node *iter2 = mid;
	while(iter1 != iter2 && iter2 != end){
		if(cmp(iter2->m_pdata, iter1->m_pdata)){
			list_node* tmp = iter2;
			iter2 = iter2->m_next;
			list_move(tmp,iter1);
		}
		else 
			iter1 = iter1->m_next;
	}
}
