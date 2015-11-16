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
iter_t companylist_add_new_company(char* name, char* description);
void companylist_sort_by_name();
//void companylist_sort_by_volumn(); 
//3 liter blood to death

iter_t companylist_find(char* name);
list* companylist_get_gamelist(iter_t company_iter);
char* companylist_get_name(iter_t company_iter);
char* companylist_get_description(iter_t company_iter);
iter_t companylist_begin();
iter_t companylist_end();
#endif //DOG_COMPANYLIST_H_