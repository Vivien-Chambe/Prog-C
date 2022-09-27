#include <ncurses.h>
#include <stdlib.h>
#include "fonctions.h"

int perso_x = 0;
int level[255];



void init_level(){
    for(int i = 0; i<LINES;i++){
        level[i] = (COLS/2)-(CANYON_SIZE/2);
    }
} 

int new_line(){
    int coord_gauche;
    int num = rand() % 3 + 1; //Je sais faut pas utiliser rand mais c'etait pour faire des tests
    if(num == 1){coord_gauche = level[0] - 1;}
    else if(num == 2){coord_gauche = level[0];}
    else{coord_gauche = level[0]+1;}
    return coord_gauche;
}


void update_level(){
    for(int i = LINES ; i>0;i--){
        level[i] = level[i-1];
    }
    level[0] = new_line();
}

void show_level(){
    for(int i = 0;i < LINES; i++){
        mvprintw(i,level[i],BORDER);
        mvprintw(i,level[i]+CANYON_SIZE,BORDER);
    }
}

int check_collision(){
    int relative_pos = COLS/2+perso_x;
    if(relative_pos == level[LINES-5] || relative_pos == (level[LINES-5]+CANYON_SIZE)){
        
        return 1;
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

void show_perso(){
    int relative_pos = COLS/2+perso_x;// Si perso_x est à 0 alors avec cette formule ça le place au centre donc peu importe la taille de la fenetre c'est au milieu.
    mvprintw(LINES-5,relative_pos,SKIN);
}


