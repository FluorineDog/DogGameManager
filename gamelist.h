#ifndef DOG_GAMELIST_H_
#define DOG_GAMELIST_H_
#include "commmon.h"
typedef struct gamelist_item_ gamelist_item;
const int max_achievement_size = 0x100;
struct gamelist_item_{
	struct{
		char name[0x20];
		int  num;
	}achievements[max_achievement_size];
	int achievement_size;
	int time2playInSeconds;
};

#endif //DOG_GAMELIST_H