#include <ncurses.h>

void color_creation(){
    start_color();
    use_default_colors();
    init_pair(1,COLOR_WHITE,-1);
    init_pair(2,COLOR_YELLOW,-1);
    init_pair(3,COLOR_GREEN,-1);
    init_pair(4,COLOR_CYAN,-1);
    init_pair(5,COLOR_BLUE,-1);
    init_pair(6,COLOR_MAGENTA,-1);
    init_pair(7,COLOR_RED,-1);
}


void start_screen(){
    WINDOW * startScreen = newwin(LINES, COLS, 0, 0);
    box(startScreen,0,0);
    wrefresh(startScreen);

    //wattron est la fonction qui sert à changer la couleur dans une fenetre (similaire à attron)
    wattron(startScreen, COLOR_PAIR(7));
    mvwprintw(startScreen,10,40,"###   # #   ###       ##    ###    #    ###   # #        ##    #    ###   # #    #    ###");
    mvwprintw(startScreen,11,40," #    # #   #         # #   #     # #    #    # #       #     # #   # #   # #   # #   # #");
    mvwprintw(startScreen,12,40," #    ###   ##        # #   ##    ###    #    ###       #     ###   # #    #    # #   # #");
    mvwprintw(startScreen,13,40," #    # #   #         # #   #     # #    #    # #       #     # #   # #    #    # #   # #");
    mvwprintw(startScreen,14,40," #    # #   ###       ##    ###   # #    #    # #        ##   # #   # #    #     #    # #");

    mvwprintw(startScreen,18,80," #    ###  ");
    mvwprintw(startScreen,19,80,"# #   #    ");
    mvwprintw(startScreen,20,80,"# #   ##   ");
    mvwprintw(startScreen,21,80,"# #   #    ");
    mvwprintw(startScreen,22,80," #    #    ");

    mvwprintw(startScreen,25,75,"##     #     #    #   #");
    mvwprintw(startScreen,26,75,"# #   # #   # #   ## ##");
    mvwprintw(startScreen,27,75,"# #   # #   # #   # # #");
    mvwprintw(startScreen,28,75,"# #   # #   # #   #   #");
    mvwprintw(startScreen,29,75,"##     #     #    #   #");
    wattroff(startScreen, COLOR_PAIR(7));

    //Cactus
    wattron(startScreen, COLOR_PAIR(3));
    mvwprintw(startScreen,18,101,"   # #   ");
    mvwprintw(startScreen,19,101," # ###   ");
    mvwprintw(startScreen,20,101," ###     ");
    mvwprintw(startScreen,21,101,"   #     ");
    mvwprintw(startScreen,22,101,"   #     ");

    mvwprintw(startScreen,25,60,"   # # ");
    mvwprintw(startScreen,26,60," # ### ");
    mvwprintw(startScreen,27,60," ###   ");
    mvwprintw(startScreen,28,60,"   #   ");
    mvwprintw(startScreen,29,60,"   #   ");
    wattroff(startScreen, COLOR_PAIR(3));

    //Big Cactus
    wattron(startScreen, COLOR_PAIR(2));
    mvwprintw(startScreen,10, 130,"             / '-'  /");
    mvwprintw(startScreen,11, 130,"            ;       ;");
    mvwprintw(startScreen,12, 130,"         /'-|       |-' |");
    mvwprintw(startScreen,13, 130,"        |   |_______K   |");
    mvwprintw(startScreen,14, 130,"        |   '-------'   /");
    mvwprintw(startScreen,15, 130,"         '.___.....___.'");
    wattroff(startScreen, COLOR_PAIR(2));
    wattron(startScreen, COLOR_PAIR(3));
    mvwprintw(startScreen,16, 130,"             | ;  : ;|");
    mvwprintw(startScreen,17, 130,"            _|;__;__.|_");
    wattroff(startScreen, COLOR_PAIR(3));
    wattron(startScreen, COLOR_PAIR(1));
    mvwprintw(startScreen,18, 141,"|     Y     |");
    mvwprintw(startScreen,19, 141,"|___.'^'.___|");
    wattroff(startScreen, COLOR_PAIR(1));
    wattron(startScreen, COLOR_PAIR(3));
    mvwprintw(startScreen,20, 130,"             |_  ;  _|      .--.");
    mvwprintw(startScreen,21, 130," .--.        {^^^^^^^}     /;   |");
    mvwprintw(startScreen,22, 130,"/   ;|       {       }    | ;   |");
    mvwprintw(startScreen,23, 130,"|  ; |       {       }    |     |");
    mvwprintw(startScreen,24, 130,"|;   |       ;-.__.'|    |:  ; |");
    mvwprintw(startScreen,25, 130,"| ;  |      |;  ;   |_____/ ;  |");
    mvwprintw(startScreen,26, 130,"|   '.'-----'      ' -_   .'   /");
    mvwprintw(startScreen,27, 130,"|  '.   - _  ' ;  ;  _  -    .'");
    mvwprintw(startScreen,28, 130," '.   -     - ;  ;   .------`");
    mvwprintw(startScreen,29, 130,"   `--------.      ; |");
    mvwprintw(startScreen,30, 130,"            |;  ,    |");
    mvwprintw(startScreen,31, 130,"            |;  ,    |");
    mvwprintw(startScreen,32, 130,"            |;  ,    |");
    mvwprintw(startScreen,33, 130,"            |;  ,    |");
    mvwprintw(startScreen,34, 130,"            |;  ,    |");
    mvwprintw(startScreen,35, 130,"            |;  ,    |");
    mvwprintw(startScreen,36, 130,"            |;  ,    |");
    mvwprintw(startScreen,37, 130,"            |;  ,    |");
    mvwprintw(startScreen,38, 130,"            |;  ,    |");
    mvwprintw(startScreen,39, 130,"            |;  ,    |");
    mvwprintw(startScreen,40, 130,"            |;  ,    |");
    mvwprintw(startScreen,41, 130,"            |;  ,    |");
    mvwprintw(startScreen,42, 130,"            |;  ,    |");
    mvwprintw(startScreen,43, 130,"            |;  ,    |");
    mvwprintw(startScreen,44, 130,"            |;  ,    |");
    mvwprintw(startScreen,45, 130,"            |;  ,    |");
    mvwprintw(startScreen,46, 130,"            |;  ,    |");
    mvwprintw(startScreen,47, 130,"            |;  ,    |");
    wattroff(startScreen, COLOR_PAIR(3)); 

    mvwprintw(startScreen,40, 70,"Press any key to continue");
    wgetch(startScreen);
    endwin();

}

