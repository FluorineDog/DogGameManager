#include "gamelist.h"
static list allGameList;
void gamelist_init_all(){
	//Called by company_init_all
	list_init(&allGameList);
}

