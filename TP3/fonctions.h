#ifndef SKIN
#define SKIN "T"  // Perso Character
#endif

#ifndef BORDER
#define BORDER "*"   // Border Character
#endif

#ifndef CANYON_SIZE
#define CANYON_SIZE 20   // Border Character
#endif

void init_level();
void show_perso();
void update_perso_position();
int new_line();
void update_level();
int check_collision();
void show_level();