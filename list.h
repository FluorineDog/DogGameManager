//This file provides a framework of common lists
//You must specify it before any use
#ifndef DOG_LIST_H_
#define DOG_LIST_H_
#include "gc.h"
#include "common.h"

typedef struct list_node_ list_node;
typedef struct list_ list;
typedef void (*destructor_t)(void * data);
typedef bool (*cmp_t)(void *pdata1, void *pdata2);
typedef bool (*check_t)(void* pdata);

struct list_node_{
	list_node *m_prev, *m_next;	
	void *m_pdata;	//Block of data for universial usage
}; 
struct list_{
	int m_size;
	list_node m_head, m_tail;
	destructor_t m_destructor;//for m_pdata
};

void list_initialize(list *plist, destructor_t destructor);
void list_insert(list *plist, list_node* pwhere, void* pdata);
void list_erase(list *plist, list_node* pwhere);
void list_move(list_node* pwhich, list_node* pwhere);
void list_clear_all(list *plist);

inline list_node* list_begin(list *plist){return plist->m_head.m_next;}
inline list_node* list_end(list *plist){return &plist->m_tail;}
inline void list_push(list *plist, void* pdata){
	//always insert to the tail of list
	list_insert(plist, list_end(plist), pdata);
}

//to sort in the standard of cmp with method of mergeSort
void list_sort(list *plist, cmp_t cmp);

//to find the first matched item
list_node* list_find(list *plist, check_t check);


#endif //DOG_LIST_H_
