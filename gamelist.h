#ifndef DOG_GAMELIST_H_
#define DOG_GAMELIST_H_
#include "commmon.h"
#include "list.h"
#include "companylist.h"
void gamelist_init_no_company(list_node *no_company_node);
typedef struct gamelist_item_ gamelist_item;
typedef bool (*gamelist_cmp_t)(gamelist_item* ptr1, gamelist_item* ptr2);
struct gamelist_item_{
	char m_name[MAXSIZE_NAME];
	struct{
		char name[MAXSIZE_NAME];
		int  num;
	}m_achievement[max_achievement_size];
	int m_achievement_size;
	int m_time_played;
	list_node* m_company;
	list_node* position_in_allGameList;
	list_node* position_in_companylist;//for fast deletion
};
list* gamelist_get_all();
void gamelist_init_all();
void gamelist_add_game(list* plist, char* name, int time_played);
void gamelist_find_game(list* plist, char *name);
void gamelist_erase_game(list_node* pwhere);

void gamelist_sort(list* plist, gamelist_cmp_t cmp);
bool cmp_name(gamelist_item *a, gamelist_item*b);
bool cmp_achievement_size(gamelist_item *a, gamelist_item *b);
bool cmp_time_played(gamelist_item *a, gamelist_item *b);


//Attention! Need initialization each time. 
void init_cmp_wrapper(gamelist_cmp_t cmp);
bool cmp_wrapper(void *a, void *b);

#endif //DOG_GAMELIST_H
