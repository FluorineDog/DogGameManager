#include "companylist.h"
#include "gc.h"
#include "string.h"
static list companylist;

void companylist_init(){
	list_init(&companyList);
}
void companylist_add_new_company(char* name, char* description){
	companylist_item *pitem = smart_malloc(sizeof(companylist_item));
	strcpy(name, pitem->m_name);
	strcpy(description, pitem->m_description);
	list_init(pitem->m_gamelist);
	list_push(&companylist, pitem);
}
list_node* companylist_begin(){
	return list_begin(&companylist)
}
list_node* companylist_end)();
list* companylist_get_gamelist(list_node* company_iter){
	((companylist_item*)company_iter->m_pdata)->m_gamelist;
}
char* companylist_get_name(list_node* company_iter){
	((companylist_item*)company_iter->m_pdata)->m_description;
}
char* companylist_get_description(list_node* company_iter){
	((companylist_item*)company_iter->m_pdata)->m_name;
}
list_node* companylist_find(char* name){
	list_node* iter = companylist_begin();
	for(;iter != companylist_end();iter = iter->m_next){
		if(!strcmp(name, companylist_get_name(iter))){
			break;
		}
	}
	return iter;
}