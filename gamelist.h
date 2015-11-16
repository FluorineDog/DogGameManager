#ifndef DOG_GAMELIST_H_
#define DOG_GAMELIST_H_
#include "common.h"
#include "list.h"
#include "gc.h"
#include "string.h"
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
	list* m_company_gamelist;
	list_node* m_position_in_allGameList;
	list_node* m_position_in_companylist;//for fast deletion
};
list* gamelist_get_all_list();
void gamelist_init_all();
void gamelist_init_no_company(list *gamelist);
void gamelist_add_game(list* plist, char* name, int time_played);
list_node* gamelist_find_game(list* plist, char *name);
void gamelist_erase_game(list_node* pwhere);

char* gamelist_get_name(list_node* pwhere);
int gamelist_get_ptr(list_node* pwhere);


void gamelist_sort(list* plist, gamelist_cmp_t cmp);
bool cmp_name(gamelist_item *a, gamelist_item*b);
bool cmp_achievement_size(gamelist_item *a, gamelist_item *b);
bool cmp_time_played(gamelist_item *a, gamelist_item *b);


//Attention! Need initialization each time. 
void init_cmp_wrapper(gamelist_cmp_t cmp);
bool cmp_wrapper(void *a, void *b);

#endif //DOG_GAMELIST_H
