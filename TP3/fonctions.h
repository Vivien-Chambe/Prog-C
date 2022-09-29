#ifdef BOSS_RUSH //Si on est en mod boss on désactive l'autopilot et la vitesse mise par l'utilsateur
#undef AUTOPILOT
#undef HERTZ_RATE
#undef DEBUG
#endif

#ifndef SKIN
#define SKIN "T"  // Perso Character
#endif

#ifndef BORDER
#define BORDER "*"   // Border Character
#endif

#ifndef CANYON_SIZE
#define CANYON_SIZE 20 // Border Character
#endif

#ifndef HZ_RATE
#define HZ_RATE 50 // Border Character
#endif

// Crée un couloir droit pour le début de partie
void init_level();

// Mets à jour la position du perso en fonction de l'entrée de l'utilisateur
void update_perso_position();

// Mode démo permettant un défilement continue sans erreur
void autopilot();

// Affiche la position du personnage en fonction de sa position relative
void show_perso(int spedd);

//Crée la nouvelle ligne du haut à partir de la précédente en allant a droite/a gauche ou tout droit
int new_line();

// Décale toutes les lignes pour créer un défilement et ajoute une nouvelle ligne grâce a new_line
void update_level();

// Print le niveau de haut en bas en parcourant le tableau level 
void show_level();

// Vérifie à chaque "frame" si le joueur est en collision avec le bord gauche|droit du canyon
int check_collision();

// Indique le score en temps réel au joueur
void print_score();

// Augmente la difficulté en réduisant la taille du canyon jusqu'à un minimum de 4, et la vitesse de défilement du canyon
int adjust_difficulty();

// Fonction qui affiche des informations nécessaires au debug (Taille du canyon,vitesse,nombre de lignes|colonnes)
void debug();