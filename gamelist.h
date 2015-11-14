#ifndef DOG_GAMELIST_H_
#define DOG_GAMELIST_H_
#include "commmon.h"
typedef struct gamelist_item_ gamelist_item;

struct gamelist_item_{
	char m_name[MAXSIZE_NAME];
	struct{
		char name[MAXSIZE_NAME];
		int  num;
	}m_achievement[max_achievement_size];
	int m_achievement_size;
	int m_time_played;
};
list* gamelist_get_all();
void gamelist_init_all();
void gamelist_add_game(list* plist, char* name, int time_played);
void gamelist_find_game(list* plist, char *name);

#endif //DOG_GAMELIST_H
