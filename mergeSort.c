#include "list.h"

void mergeSort(list_node *beg, list_node *end, int size){
	if(size <= 1)
		return; 
	list_node* mid = beg;
	for(int i = 0; i < size/2 ; ++i){
		mid = mid->m_next;
	}
	// size/2 + (size+1)/2 = size
	mergeSort(beg, mid, size/2);
	mergeSort(beg, mid, (size+1)/2); 
	merge(beg, mid, end);
}
void merge(list_node* beg, list_node* mid, list_node* end){
	list_node *iter1 = beg;
	list_node *iter2 = mid;
	while(iter1 != mid && iter2 != end){
		if(cmp(iter2->m_pdata, iter1->m_pdata)){
			list_node* tmp = iter2;
			iter2 = iter2->m_next;
			list_move(tmp,iter1);
		}
		else 
			iter1 = iter1->next;
	}
}