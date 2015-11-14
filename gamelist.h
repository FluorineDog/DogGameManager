#ifndef DOG_GAMELIST_H_
#define DOG_GAMELIST_H_
#include "commmon.h"
typedef struct gamelist_item_ gamelist_item;
struct gamelist_item_{
	struct {
		int time2play;
	}game_data;
	list* company;
};

#endif //DOG_GAMELIST_H_
