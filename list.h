//This file provide a framework of common lists
//You must specify it before any usage
#ifndef DOG_LIST_H_
#define DOG_LIST_H_
#include "gc.h"

struct list_node_{
	list_node *m_prev, *m_next;	
	void *m_pdata;	//Block of data for universial usage
}; 
typedef struct list_node_ list_node;
typedef void (*destructor_t)(void * data);
struct list_{
	int m_size;
	list_node m_head, m_tail;
	destructor_t m_destructor;//for m_pdata
};
typedef struct list_ list;

void list_initialize(list *plist, destructor_t destructor);
void list_insert(list *plist, void* pdata);
void list_erase(list *plist, list_node* pwhere);

typedef bool (*cmp_t)(void *pdata1, void *pdata2);
//to sort in the standard of cmp
void list_sort(list *plist, cmp_t cmp);

typedef bool (*check_t)(void* pdata);
//to find the first matched item
list_node* list_find(list *plist, check_t check);

list_node* list_begin(list *plist){return plist->m_head.m_next;}
list_node* list_end(list *plist){return &plist->m_tail;}


#endif //DOG_LIST_H_