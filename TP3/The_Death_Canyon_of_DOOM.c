#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "fonctions.h"
#include "ascii_art.h"



int main(){
    srand(time(NULL));
    initscr(); //Initialise la fenetre de "travail"
    keypad(stdscr, true); //Autorise les entrées utilisateurs
    noecho(); //Désactive l'affichage des entrées utilisateur
    cbreak(); //
    color_creation(); //
    start_screen();
    curs_set(0); //Désactive l'affichage du curseur
    timeout(0);  // N'attends pas un getch() pour avancer
    
    int play = 1;
    int c;
    int speed_modifier = adjust_difficulty();
    show_perso(speed_modifier);
    init_level();
    
    while (play == 1){
        c =  getch();
        if(c == 'q'){play = 0;break;}

        // Update le jeu (Coordonnées)
        #ifdef AUTOPILOT
        autopilot();
        #else    
        else{update_perso_position(c);}
        #endif
        update_level();
        speed_modifier = adjust_difficulty();
        erase();
        //

        //Affichage 
        print_score();
        show_perso(speed_modifier);
        show_level();

        #ifdef DEBUG
        debug();
        #endif
        
        if(check_collision()!=0){
            timeout(-1);
            play = 0;
            mvprintw(LINES-5,check_collision(),"x");
            mvprintw(LINES/2,COLS/2,"YOU DEAD!!!!!!");
            refresh(); 
            sleep(3);
            break;
        }
        refresh(); // Print changes on screen
        usleep(HZ_RATE*1000 - speed_modifier*3000);
    }
    getch();
    endwin();

    return 0;

}