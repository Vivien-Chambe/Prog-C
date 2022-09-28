#include <ncurses.h>
#include <stdlib.h>
#include "fonctions.h"


int perso_x = 0;
int level[255];
int canyon_size = CANYON_SIZE; // On place CANYON_SIZE dans une variable car on va la faire décroitre
int score = 1;
int speed_modifier = 0; 


// Cette fonction assure un couloir droit pour débuter la partie
void init_level(){
    for(int i = 0; i<LINES;i++){
        level[i] = (COLS/2)-(canyon_size/2);
    }
} 

int new_line(){
    int coord_gauche;
    int num = rand() % 3 + 1; 
    if(num == 1){coord_gauche = level[0] - 1;}
    else if(num == 2){coord_gauche = level[0];}
    else{coord_gauche = level[0]+1;}
    if(coord_gauche < 0){coord_gauche++;}
    else if(coord_gauche + canyon_size +1 >= COLS){coord_gauche--;}
    return coord_gauche;
}


void update_level(){
    score++;
    for(int i = LINES ; i>0;i--){
        level[i] = level[i-1];
    }
    level[0] = new_line();
}

void show_level(){
    for(int i = 0;i < LINES; i++){
            #ifdef __RAINBOW
            int random = rand()%7+1;
            attron(COLOR_PAIR(random));
            #endif
            mvprintw(i,level[i],BORDER);
            mvprintw(i,level[i] + canyon_size +1,BORDER); // Le +1 sert à ne pas compter la derniere case du canyon comme un mur mais avoir réellement canyon_size espaces.
            #ifdef __RAINBOW
            attroff(COLOR_PAIR(random));
            #endif
    }
}

int check_collision(){
    int relative_pos = COLS/2+perso_x;
    if(relative_pos == level[LINES-5] || relative_pos == (level[LINES-5]+canyon_size)){
        
        return COLS/2+perso_x;
    }
    else{return 0;}
}

void update_perso_position(int c){
    switch (c)
    {
    case KEY_LEFT:
        perso_x --;
        break;
    case KEY_RIGHT:
        perso_x ++;
        break;
    
    default:
        break;
    }
}

// Jusqu'à canyon_size = 3 l'autopilot fonctionne
void autopilot(){
    int relative_pos = COLS/2+perso_x;
    if(relative_pos - level[LINES-6] <= canyon_size/2){
        perso_x++;
    }
    else{perso_x--;}
}


void show_perso(int spedd){
    attron(COLOR_PAIR(spedd%7+1));
    int relative_pos = COLS/2+perso_x;// Si perso_x est à 0 alors avec cette formule ça le place au centre donc peu importe la taille de la fenetre c'est au milieu.
    mvprintw(LINES-5,relative_pos,SKIN);
    attroff(COLOR_PAIR(spedd%7+1));
}

void print_score(){
    mvprintw(0,0,"Score  : %d",score);
}

int adjust_difficulty(){
    if(score%500 == 0 && canyon_size>4){
        canyon_size--;
    }
    if(score%200 == 0 && speed_modifier < 10){
        speed_modifier++;
    }
    return speed_modifier;
}

void debug(){
    mvprintw(1,0,"Canyon size : %d",canyon_size);
    mvprintw(2,0,"Spedd Modifier : %d",speed_modifier);
    mvprintw(3,0,"LINES : %d COLS: %d",LINES,COLS);
    mvprintw(4,0,"GaucheC : %d DroiteC: %d",level[0],level[0]+canyon_size+1);

}

