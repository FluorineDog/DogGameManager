#ifndef DOG_LIST_H_
#define DOG_LIST_H_


struct list_node{
	list_node *m_prev, *m_next;	
	void *m_pdata;	//Block of data for universial usage
}; 

struct list{
	int m_size;
	list_node m_head, m_tail;
};

void list_initialize(list *plist);
void list_insert(list *plist, void* pdata);
void list_delete(list *plist, list_node* pwhere);

typedef bool (*cmp_t)(void *pdata1, void *pdata2);
//to sort in the standard of cmp
void list_sort(list *plist, cmp_t cmp);
list_node* list_begin(list *plist){return plist->m_head.m_next;}
list_node* list_end(list *plist){return &plist->m_tail;}
typedef bool (*check_t)(void* pdata){
	return pdata;
}

#endif //DOG_LIST_H_