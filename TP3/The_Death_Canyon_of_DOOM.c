#include "fonctions.h"
#include <ncurses.h>

int main(void) {

    initscr();
    keypad(stdscr,TRUE);

    int ch; 
    int play = 1;
    int perso_x = (COLS/2);
    int perso_y = LINES-1;
    mvprintw(perso_x, perso_y,"^");
    while (play){
        ch = getch();
        
        switch(ch){
            case KEY_LEFT:
                mvprintw(perso_y, perso_x," ");
                perso_x = perso_x-1;
                mvprintw(perso_y, perso_x,"^");
            case KEY_RIGHT:
                mvprintw(perso_y, perso_x," ");
                perso_x = perso_x+1;
                mvprintw(perso_y, perso_x,"^");
            case KEY_DOWN:
                endwin();
            

        }
        refresh();

    }
    return 0;
}