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
	companylist_init();
	companylist_add_new_company("EA", "a game Empire.");
	companylist_add_new_company("Disney", "most successful canton game provider");
	companylist_add_new_company("XDisney", "most successful fake canton game provider");
	companylist_sort_by_name();
	list* gamelist = companylist_get_gamelist(companylist_begin());
	gamelist_add_game(gamelist,"fishing",55);
	gamelist_add_game(gamelist,"balling",13);
	gamelist_add_game(gamelist,"zoo",31);
	gamelist_sort(gamelist,cmp_name);
	for()
	return 0;
}
