#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "fonctions.h"



int main(){
    initscr();
    keypad(stdscr, true); //Autorise les entrées utilisateurs
    noecho();
    cbreak();
    curs_set(0);
    timeout(0);

    int play = 1;
    int c;
    show_perso();
    init_level();
    while (play == 1){
        c =  getch();
        if(c == 'q'){play = 0;break;}
        else{update_perso_position(c);}

        update_level();
        erase();
        mvprintw(0,0,"LINES:%d COLS:%d",LINES,COLS);
        //Check collision
        if(check_collision()){
            timeout(-1);
            play = 0;
            erase();
            mvprintw(LINES/2,COLS/2,"YOU DEAD!!!!!!");
            refresh(); 
            break;
        }

        show_perso();
        show_level();
        refresh(); // Print changes on screen
        usleep(30000);

        
    }
    getch();
    getch();
    endwin();

    return 0;

}