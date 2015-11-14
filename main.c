#include <stdio.h>
#include "common.h"
#include "list.h"
#include "gc.h"
int show(void *p){
	return *(int*)p;
}
bool cmper(void *a, void *b){
	return show(a)<show(b);
}
void der(void *p){
	smart_free(p);
}
int main()
{
	list container;
	list *plist = &container;
	list_initialize(&container,der);
	for(int i =0; i<0x100; ++i){
		int *tmp =smart_malloc(sizeof(int));
		*tmp = 31*i % 0x100;
		list_push(&container,tmp);
	}
	list_sort(&container, cmper);
	for(list_node *iter = list_begin(plist)->m_next;
	iter!=list_end(plist); iter = list_begin(plist)->m_next){
		printf("\t%d",show(iter->m_pdata));
	}
	printf("\nhello, world!\n");
	return 0;
}
