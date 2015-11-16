#include "companylist.h"
#include "gc.h"
#include "string.h"
static list companylist;
// no comments, since all info is implicited in the variable names.
void companylist_init(){
	list_init(&companylist, smart_free);
	companylist_add_new_company("No Company", "games that \
	add from the allGameList will go there");
	gamelist_init_all();
	// to deal with direct insertion into allGameList
	gamelist_init_no_company(companylist_get_gamelist(companylist_begin()));
}
iter_t companylist_add_new_company(char* name, char* description){
	companylist_item *pitem = smart_malloc(sizeof(companylist_item));
	strcpy(name, pitem->m_name);
	strcpy(description, pitem->m_description);
	list_init(&pitem->m_gamelist, do_nothing);
	return list_push(&companylist, pitem);
}
iter_t companylist_begin(){
	return list_begin(&companylist);
}
iter_t companylist_end(){
	return list_end(&companylist);
}
list* companylist_get_gamelist(iter_t company_iter){
	return &((companylist_item*)company_iter->m_pdata)->m_gamelist;
}
char* companylist_get_name(iter_t company_iter){
	return ((companylist_item*)company_iter->m_pdata)->m_description;
}
char* companylist_get_description(iter_t company_iter){
	return ((companylist_item*)company_iter->m_pdata)->m_name;
}
iter_t companylist_find(char* name){
	iter_t iter = companylist_begin();
	for(;iter != companylist_end();iter = iter->m_next){
		if(!strcmp(name, companylist_get_name(iter))){
			break;
		}
	}
	return iter;
} 
bool cmpr_name(void* a, void *b){
	// void* equals to companylist_item* 
	return strcmp(((companylist_item*)a)->m_name,
	((companylist_item*)b)->m_name )<0;
}
void companylist_sort_by_name(){
	list_sort(&companylist,cmpr_name);
}