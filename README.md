# DogGameManager
**A worst manager for so-called Steam games. **
void gamelist_init_no_company(list *gamelist);    
void gamelist_add_game(list* plist, char* name, int time_played);    
iter_t gamelist_find_game(list* plist, char *name);    
void gamelist_erase_game(iter_t pwhere);    

char* gamelist_get_name(iter_t pwhere);  
int gamelist_get_ptr(iter_t pwhere);    


void gamelist_sort(list* plist, gamelist_cmp_t cmp);    
bool cmp_name(gamelist_item *a, gamelist_item*b);  
bool cmp_achievement_size(gamelist_item *a, gamelist_item *b);
bool cmp_time_played(gamelist_item *a, gamelist_item *b);
