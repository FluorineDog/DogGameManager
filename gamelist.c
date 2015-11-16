#include "gamelist.h"
static list allGameList;
static list* no_company_gamelist;
static gamelist_cmp_t cmpr_core;
void gamelist_init_all(){
	//Called by company_init_all
	list_init(&allGameList, smart_free);
}

list* gamelist_get_all_list(){
	return &allGameList;
}


void gamelist_init_no_company(list *gamelist){
	no_company_gamelist = gamelist;
}
void gamelist_add_game(list* gamelist, char* name, int time_played){
	if(gamelist == &allGameList)
		gamelist = no_company_gamelist;
	gamelist_item* new_item = smart_malloc(sizeof(gamelist_item));
	strcpy(name,new_item->m_name);
	new_item->m_achievement_size = 0;
	new_item->m_time_played = time_played;
	new_item->m_company_gamelist = gamelist;
	new_item->m_position_in_allGameList = list_push(&allGameList, new_item);
	new_item->m_position_in_companylist = list_push(gamelist, new_item);
}
list_node* gamelist_find_game(list* gamelist, char *name){
	list_node* iter = list_begin(gamelist);
	for(;iter != list_end(gamelist);iter = iter->m_next){
		if(!strcmp(name, gamelist_get_name(iter))){
			break;
		}
	}
	return iter;
}
void gamelist_erase_game(list_node* pwhere){
	gamelist_item *trash = (gamelist_item*) pwhere->m_pdata;
	list_erase(trash->m_company_gamelist, trash->m_position_in_companylist);
	list_erase(&allGameList, trash->m_position_in_allGameList);
}

char* gamelist_get_name(list_node* game_iter){
	return ((gamelist_item*)game_iter->m_pdata)->m_name;
}

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


//Attention! ed initialization each time. 
void init_cmp_wrapper(gamelist_cmp_t cmp){
	cmpr_core = cmp;
}
bool cmp_wrapper(void *a, void *b){
	return cmpr_core((gamelist_item*)a, (gamelist_item*)b);
}
