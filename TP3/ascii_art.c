#include <ncurses.h>
#include "fonctions.h"

void color_creation(){
    // Spec : initialise l'utilisation de couleurs
    // E,S : none , none

    start_color(); 
    use_default_colors();
    init_pair(1,COLOR_WHITE,-1); //definit les differentes couleurs utilisabes (-1 rend le backgroung transparent)
    init_pair(2,COLOR_YELLOW,-1);
    init_pair(3,COLOR_GREEN,-1);
    init_pair(4,COLOR_CYAN,-1);
    init_pair(5,COLOR_BLUE,-1);
    init_pair(6,COLOR_MAGENTA,-1);
    init_pair(7,COLOR_RED,-1);
}


void start_screen(){
    // Spec : initialise l'ecran de depart du jeu
    // E,S : none , none

    WINDOW * startScreen = newwin(LINES, COLS, 0, 0); //initialise une fenetre pour le menu
    box(startScreen,0,0); 
    wrefresh(startScreen);

    //wattron est la fonction qui sert à changer la couleur dans une fenetre (similaire à attron)

    //Affichage du titre du jeu
    wattron(startScreen, COLOR_PAIR(7));
    mvwprintw(startScreen,10,(COLS/2 - COLS/3),"###   # #   ###       ##    ###    #    ###   # #        ##    #    ###   # #    #    ###");
    mvwprintw(startScreen,11,(COLS/2 - COLS/3)," #    # #   #         # #   #     # #    #    # #       #     # #   # #   # #   # #   # #");
    mvwprintw(startScreen,12,(COLS/2 - COLS/3)," #    ###   ##        # #   ##    ###    #    ###       #     ###   # #    #    # #   # #");
    mvwprintw(startScreen,13,(COLS/2 - COLS/3)," #    # #   #         # #   #     # #    #    # #       #     # #   # #    #    # #   # #");
    mvwprintw(startScreen,14,(COLS/2 - COLS/3)," #    # #   ###       ##    ###   # #    #    # #        ##   # #   # #    #     #    # #");

    mvwprintw(startScreen,18,(COLS/2 - COLS/6)," #    ###  ");
    mvwprintw(startScreen,19,(COLS/2 - COLS/6),"# #   #    ");
    mvwprintw(startScreen,20,(COLS/2 - COLS/6),"# #   ##   ");
    mvwprintw(startScreen,21,(COLS/2 - COLS/6),"# #   #    ");
    mvwprintw(startScreen,22,(COLS/2 - COLS/6)," #    #    ");
    
    mvwprintw(startScreen,25,(COLS/2 - COLS/6 + COLS/40),"##     #     #    #   #");
    mvwprintw(startScreen,26,(COLS/2 - COLS/6 + COLS/40),"# #   # #   # #   ## ##");
    mvwprintw(startScreen,27,(COLS/2 - COLS/6 + COLS/40),"# #   # #   # #   # # #");
    mvwprintw(startScreen,28,(COLS/2 - COLS/6 + COLS/40),"# #   # #   # #   #   #");
    mvwprintw(startScreen,29,(COLS/2 - COLS/6 + COLS/40),"##     #     #    #   #");
    wattroff(startScreen, COLOR_PAIR(7));

    //Cactus
    wattron(startScreen, COLOR_PAIR(3));
    mvwprintw(startScreen,18,(COLS/2 - COLS/20),"   # #   ");
    mvwprintw(startScreen,19,(COLS/2 - COLS/20)," # ###   ");
    mvwprintw(startScreen,20,(COLS/2 - COLS/20)," ###     ");
    mvwprintw(startScreen,21,(COLS/2 - COLS/20),"   #     ");
    mvwprintw(startScreen,22,(COLS/2 - COLS/20),"   #     ");

    mvwprintw(startScreen,25,(COLS/2 - COLS/4),"   # # ");
    mvwprintw(startScreen,26,(COLS/2 - COLS/4)," # ### ");
    mvwprintw(startScreen,27,(COLS/2 - COLS/4)," ###   ");
    mvwprintw(startScreen,28,(COLS/2 - COLS/4),"   #   ");
    mvwprintw(startScreen,29,(COLS/2 - COLS/4),"   #   ");
    wattroff(startScreen, COLOR_PAIR(3));

    //Pablo
    wattron(startScreen, COLOR_PAIR(2));
    mvwprintw(startScreen,10, (COLS/2 + COLS/19) ,"             / '-'  /");
    mvwprintw(startScreen,11, (COLS/2 + COLS/19),"            ;       ;");
    mvwprintw(startScreen,12, (COLS/2 + COLS/19),"         /'-|       |-' |");
    mvwprintw(startScreen,13, (COLS/2 + COLS/19),"        |   |_______K   |");
    mvwprintw(startScreen,14, (COLS/2 + COLS/19),"        |   '-------'   /");
    mvwprintw(startScreen,15, (COLS/2 + COLS/19),"         '.___.....___.'");
    wattroff(startScreen, COLOR_PAIR(2));
    wattron(startScreen, COLOR_PAIR(3));
    mvwprintw(startScreen,16, (COLS/2 + COLS/19),"             | ;  : ;|");
    mvwprintw(startScreen,17, (COLS/2 + COLS/19),"            _|;__;__.|_");
    wattroff(startScreen, COLOR_PAIR(3));
    wattron(startScreen, COLOR_PAIR(1));
    mvwprintw(startScreen,18, (COLS/2 + COLS/10),"|     Y     |");
    mvwprintw(startScreen,19, (COLS/2 + COLS/10),"|___.'^'.___|");
    wattroff(startScreen, COLOR_PAIR(1));
    wattron(startScreen, COLOR_PAIR(3));
    mvwprintw(startScreen,20, (COLS/2 + COLS/19),"             |_  ;  _|      .--.");
    mvwprintw(startScreen,21, (COLS/2 + COLS/19)," .--.        {^^^^^^^}     /;   |");
    mvwprintw(startScreen,22, (COLS/2 + COLS/19),"/   ;|       {       }    | ;   |");
    mvwprintw(startScreen,23, (COLS/2 + COLS/19),"|  ; |       {       }    |     |");
    mvwprintw(startScreen,24, (COLS/2 + COLS/19),"|;   |       ;-.__.'|    |:  ; |");
    mvwprintw(startScreen,25, (COLS/2 + COLS/19),"| ;  |      |;  ;   |_____/ ;  |");
    mvwprintw(startScreen,26, (COLS/2 + COLS/19),"|   '.'-----'      ' -_   .'   /");
    mvwprintw(startScreen,27, (COLS/2 + COLS/19),"|  '.   - _  ' ;  ;  _  -    .'");
    mvwprintw(startScreen,28, (COLS/2 + COLS/19)," '.   -     - ;  ;   .------`");
    mvwprintw(startScreen,29, (COLS/2 + COLS/19),"   `--------.      ; |");
    mvwprintw(startScreen,30, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,31, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,32, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,33, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,34, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,35, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,36, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,37, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,38, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,39, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,40, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,41, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,42, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,43, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,44, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,45, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,46, (COLS/2 + COLS/19),"            |;  ,    |");
    mvwprintw(startScreen,47, (COLS/2 + COLS/19),"            |;  ,    |");
    wattroff(startScreen, COLOR_PAIR(3)); 

    mvwprintw(startScreen,40, 70,"Press any key to continue"); 
    wgetch(startScreen);//attend un input de l'utilisateur pour fermer le menu
    endwin();

}

void death_message(int score){
    // Spec : initialise l'ecran de mort / fin du jeu
    // E,S : none , none


    mvprintw(LINES-5,check_collision(),"x"); //place le symbole de mort

    //message de mort
    mvprintw((LINES/2),(COLS/2)-10,  "         ## #           ");
    mvprintw((LINES/2)+1,(COLS/2)-10,"         ####         ");
    mvprintw((LINES/2)+2,(COLS/2)-10,"_________##_________ ");
    mvprintw((LINES/2)+3,(COLS/2)-10,"|                    |");
    mvprintw((LINES/2)+4,(COLS/2)-10,"|    YOU DIE !!!!!!  |");
    mvprintw((LINES/2)+5,(COLS/2)-10,"|                    |");
    mvprintw((LINES/2)+6,(COLS/2)-10,"|      Score:%d     |",score);
    mvprintw((LINES/2)+7,(COLS/2)-10,"|____________________|");
}