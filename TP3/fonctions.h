

#ifndef SKIN
#define SKIN "T"  // Perso Character
#endif

#ifndef BORDER
#define BORDER "*"   // Border Character
#endif

#ifndef CANYON_SIZE
#define CANYON_SIZE 20 // Border Character
#endif

void init_level();

void update_perso_position();
void show_perso(int spedd);
void autopilot();

int new_line();
void update_level();
void show_level();

int check_collision();
void print_score();
int adjust_difficulty();

void debug();