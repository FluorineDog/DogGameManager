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
	list_initialize(plist,der);
	
	for(int i =0; i<0x100; ++i){
		int *tmp =smart_malloc(sizeof(int));
		*tmp = 37*i % 0x100;
		list_push(&container,tmp);
	}
	list_sort(plist, cmper);
	for(list_node *iter = list_begin(plist);
	iter!=list_end(plist); iter = iter->m_next){
		printf("%d\t",show(iter->m_pdata));
	}
	list_clear_all(plist);
	return 0;
}
