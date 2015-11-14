#ifndef DOG_GAMELIST_H_
#define DOG_GAMELIST_H_
#include "commmon.h"
typedef struct gamelist_item_ gamelist_item;
const int max_achievement_size = 0x100;
struct gamelist_item_{
	int m_name;
	struct{
		char name[0x20];
		int  num;
	}m_achievements[max_achievement_size];
	int m_achievement_size;
	int m_time_played;
};
list* gamelist_get_all();
void gamelist_add_game()
#endif //DOG_GAMELIST_H