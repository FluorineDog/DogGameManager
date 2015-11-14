#include "list.h"
struct list_node{
	list_node *m_prev, *m_next;	
	void *m_pdata;	//Block of data for universial usage
}; 

struct list{
	int m_size;
	list_node m_head, m_tail;
	
};

void list_initialize(list *plist){
	plist->size = 0;
	plist->m_head.m_next = &plist->m_tail;
	plist->m_tail.m_prev = &plist->m_head;
}
void list_insert(list *plist, void* pdata){
	//always insert to the head of list
	smart_malloc(sizeof())
}
void list_delete(list *plist, list_node* pwhere){
	pwhere->m_prev->m_next = pwhere->m_next;
	pwhere->m_next->m_prev = pwhere->m_prev;
		
}

typedef bool (*cmp_t)(void *pdata1, void *pdata2);
//to sort in the standard of cmp
void list_sort(list *plist, cmp_t cmp);
list_node* list_begin(list *plist){return plist->m_head.m_next;}
list_node* list_end(list *plist){return &plist->m_tail;}
typedef bool (*check_t)(void )
