#ifndef DOG_COMPANYLIST_H_
#define DOG_COMPANYLIST_H_
#include "list.h"
#include "gc.h"
#include "gamelist.h"
typedef struct companylist_item_ companylist_item;
struct companylist_item_{
	list m_gamelist;
	char m_description[0x400];
	char m_name[MAXSIZE_NAME];
};

void companylist_init(void);
list_node* companylist_add_new_company(char* name, char* description);
void companylist_sort_by_name();
//void companylist_sort_by_volumn(); 
//3 liter blood to death

list_node* companylist_find(char* name);
list* companylist_get_gamelist(list_node* company_iter);
char* companylist_get_name(list_node* company_iter);
char* companylist_get_description(list_node* company_iter);
list_node* companylist_begin();
list_node* companylist_end();
#endif //DOG_COMPANYLIST_H_