#include <stdio.h>
#include "common.h"
#include "list.h"
#include "gc.h"
#include "gamelist.h"
#include "companylist.h"
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
	list_init(plist,der);
	
	for(int i =0; i<10000000; ++i){
		int *tmp =smart_malloc(sizeof(int));
		*tmp = rand()*65536+rand();
		list_push(&container,tmp);
	}
	printf("begins\n");
	list_sort(plist, cmper);
	printf("ends\n");
	int i=(unsigned int)-1 /2;
	list_clear_all(plist);
	return 0;
}
