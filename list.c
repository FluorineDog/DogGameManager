#include "list.h"

void list_initialize(list *plist, destructor_t destructor){
	plist->size = 0;
	plist->m_head.m_next = &plist->m_tail;
	plist->m_tail.m_prev = &plist->m_head;
	m_destructor =  destructor;
}

void list_insert(list *plist, void* pdata){
	//always insert to the tail of list
	++size;
	list_node *new_item = smart_malloc(sizeof(list_node));
	new_item->m_pdata = pdata;
	new_item->m_next = list_end(plist);
	new_item->m_prev = list_end(plist)->prev;
	new_item->m_next->m_prev = new_item->m_prev;
	new_item->m_prev->m_next = new_item->m_next;
}

void list_erase(list *plist, list_node* pwhere){
	--size;
	pwhere->m_prev->m_next = pwhere->m_next;
	pwhere->m_next->m_prev = pwhere->m_prev;
	plist->m_destructor(pwhere->mdata);
}

//to sort in the standard of cmp with method of MergeSort
void list_sort(list *plist, cmp_t cmp){
	
}
list_node* list_find(list *plist, check_t check){
	for(list_node* iter = list_begin(plist);\
	iter!= list_end(plist);iter = iter-m_next){
		if(check(iter->m_pdata)){
			return iter;
		}
	}
	return iter;
}