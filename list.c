#include "list.h"
#include "mergeSort.h"
void list_initialize(list *plist, destructor_t destructor){
	plist->m_size = 0;
	plist->m_head.m_next = &plist->m_tail;
	plist->m_tail.m_prev = &plist->m_head;
	plist->m_destructor =  destructor;
}

void list_insert(list *plist, list_node* pwhere, void* pdata){
	++plist->m_size;
	list_node *new_item = smart_malloc(sizeof(list_node));
	new_item->m_pdata = pdata;
	new_item->m_next = pwhere;
	new_item->m_prev = pwhere->m_prev;
	new_item->m_next->m_prev = new_item;
	new_item->m_prev->m_next = new_item;
}

void list_erase(list *plist, list_node* pwhere){
	--plist->m_size;
	pwhere->m_prev->m_next = pwhere->m_next;
	pwhere->m_next->m_prev = pwhere->m_prev;
	plist->m_destructor(pwhere->m_pdata);
}
void list_move(list_node* pwhich, list_node* pwhere){
	pwhich->m_prev->m_next = pwhich->m_next;
	pwhich->m_next->m_prev = pwhich->m_prev;
	pwhich->m_next = pwhere;
	pwhich->m_prev = pwhere->m_prev;
	pwhich->m_next->m_prev = pwhich;
	pwhich->m_prev->m_next = pwhich;
}
void list_clear_all(list *plist){
	for(list_node *iter = list_begin(plist)->m_next;
	iter!=list_end(plist); iter = list_begin(plist)->m_next){
		list_erase(plist,iter);
	}
}
//to sort in the standard of cmp with method of mergeSort
void list_sort(list *plist, cmp_t cmp){
	mergeSort(list_begin(plist), list_end(plist), plist->m_size, cmp);
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
