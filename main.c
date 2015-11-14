#include <stdio.h>
#include "common.h"
#include "list.h"
#include "gc.h"
int show(void *p){
	return *(int*)p;
}
bool cmper(void *a, void *b){
	printf("%d***%d\n",show(a),show(b));
	return show(a)<show(b);
}
void der(void *p){
	smart_free(p);
}
int main()
{
	
	printf("\nhello, woxzzrld!\n");
	list container;
	list *plist = &container;
	list_initialize(&container,der);
	//printf("\nhe1533521llo, woxzzrld!\n");
	
	for(int i =0; i<0x100; ++i){
		int *tmp =smart_malloc(sizeof(int));
		*tmp = 37*i % 0x100;
		list_push(&container,tmp);
	}
	//printf("\nhe1533521llo, woxzzrld!\n");
	list_sort(&container, cmper);
	//list_move(list_begin(plist),list_end(plist));
	for(list_node *iter = list_begin(plist);
	iter!=list_end(plist); iter = iter->m_next){
		printf("%d\t",show(iter->m_pdata));
	}
	printf("\nhello, world!\n");
	return 0;
}
