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
typedef list_node* iter_t;
struct list_node_{
	iter_t m_prev, m_next;	
	void *m_pdata;	//Block of data for universial usage
}; 
struct list_{
	int m_size;
	list_node m_head, m_tail;
	destructor_t m_destructor;//for m_pdata
};

void list_init(list *plist, destructor_t destructor);
iter_t list_insert(list *plist, iter_t pwhere, void* pdata);
void list_erase(list *plist, iter_t pwhere);
void list_move(iter_t pwhich, iter_t pwhere);
void list_clear_all(list *plist);

iter_t list_begin(list *plist);
iter_t list_end(list *plist);
iter_t list_push(list *plist, void* pdata);

//to sort in the standard of cmp with method of mergeSort
void list_sort(list *plist, cmp_t cmp);

//to find the first matched item
iter_t list_find(list *plist, check_t check);


#endif //DOG_LIST_H_
