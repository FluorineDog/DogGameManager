#include "gamelist.h"
static list allGameList;
static list
static gamelist_cmp_t cmpr_core;
void gamelist_init_all(){
	//Called by company_init_all
	list_init(&allGameList);
}

list* gamelist_get_all(){
	return &allGameList;
}
void gamelist_init_all(){
	list_init(allGameList);
}

void gamelist_add_game(list* plist, char* name, int time_played);
void gamelist_find_game(list* plist, char *name);

//sorting section
void gamelist_sort(list* plist, gamelist_cmp_t cmp){
	init_cmp_wrapper(cmp);
	list_sort(plist, cmp_wrapper);
}
//cmp core function
bool cmp_name(gamelist_item *a, gamelist_item*b){
	return strcmp(a->m_name, b->m_name);
}
bool cmp_achievement_size(gamelist_item *a, gamelist_item *b){
	return a->m_achievement_size  > b->m_achievement_size;
}
bool cmp_time_played(gamelist_item *a, gamelist_item *b){
	return a->m_time_played  > b->m_time_played;
}


//Attention! Need initialization each time. 
void init_cmp_wrapper(gamelist_cmp_t cmp){
	cmpr_core = cmp;
}
bool cmp_wrapper(void *a, void *b){
	return cmpr_core((gamelist_item*)a, (gamelist_item*)b);
}