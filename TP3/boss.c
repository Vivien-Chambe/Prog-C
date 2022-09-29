#include <ncurses.h>

#include "boss.h"
#include "fonctions.h"

void boss_screen(){
    // Spec : initialise la bordure separant Pablo du canyon
    // E,S : none , none
    int nouvelle_bordure = COLS-50;
    for(int i = 0; i<=LINES;i++){
        mvprintw(i,nouvelle_bordure,"|");
    }
}

void color_burnt_pablo(){
    // Spec : change les couleurs pour faire Pablo brule 
    // E,S : none , none

    start_color();
    use_default_colors();
    init_pair(1,COLOR_MAGENTA,-1);
    init_pair(2,COLOR_RED,-1);
    init_pair(3,COLOR_YELLOW,-1);
    init_pair(4,COLOR_CYAN,-1);
    init_pair(5,COLOR_BLUE,-1);
    init_pair(6,COLOR_WHITE,-1);
    init_pair(7,COLOR_GREEN,-1);
}

void print_Pablo(){
    // Spec : affiche Pablo dans sa zone
    // E,S : none , none

    mvprintw(4, 165,"PABLO");
    //Big Cactus
    attron(COLOR_PAIR(2));
    mvprintw(6, 150,"             / '-'  /");
    mvprintw(7, 150,"            ;       ;");
    mvprintw(8, 150,"         /'-|       |-' |");
    mvprintw(9, 150,"        |   |_______P   |");
    mvprintw(10, 150,"        |   '-------'   /");
    mvprintw(11, 150,"         '.___.....___.'");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(3));
    mvprintw(12, 150,"             | ;  : ;|");
    mvprintw(13, 150,"            _|;__;__.|_");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(1));
    mvprintw(14, 150,"           |     Y     |");
    mvprintw(15, 150,"           |___.'^'.___|");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(3));
    mvprintw(16, 150,"             |_  ;  _|      .--.");
    mvprintw(17, 150," .--.        {^^^^^^^}     /;   |");
    mvprintw(18, 150,"/   ;|       {       }    | ;   |");
    mvprintw(19, 150,"|  ; |       {       }    |     |");
    mvprintw(20, 150,"|;   |       ;-.__.'|    |:  ; |");
    mvprintw(21, 150,"| ;  |      |;  ;   |_____/ ;  |");
    mvprintw(22, 150,"|   '.'-----'      ' -_   .'   /");
    mvprintw(23, 150,"|  '.   - _  ' ;  ;  _  -    .'");
    mvprintw(24, 150," '.   -     - ;  ;   .------`");
    mvprintw(25, 150,"   `--------.      ; |");
    mvprintw(26, 150,"            |;  ,    |");
    mvprintw(27, 150,"            |;  ,    |");
    attroff(COLOR_PAIR(3));
}

void print_pablo_health(int pablo_health){
    // Spec : affiche la vie actuelle de Pablo
    // E : int pablo_health
    // S : none
    mvprintw(30,162,"[");
    mvprintw(30,162+10,"]");
    attron(COLOR_PAIR(7));
    for(int i = 1;i<pablo_health;i++){
        mvprintw(30,162+i,"#");
    }
    attroff(COLOR_PAIR(7));
}
int events(int score,int pablo_health,int canyon_size){
    if(pablo_health>0){
        if(score==680){return 2;}
        else if(score==780){return 2;}
        else if(score==1170){return 2;}
        else if(score==1700){return 4;}
        else{return 0;}
    }
    else{return 0;}

}




void print_pablo_dialogue(int score){
    if(score>=100 && score <= 150){mvprintw(33,155,"Hola amigo¡");}
    else if (score>=150 && score <= 200){mvprintw(33,155,"Bienvenue dans mon canyon");}
    else if (score>=200 && score <= 250){mvprintw(33,155,"Je suis Pablo");}
        
    else if (score>=300 && score <= 350){mvprintw(33,155,"On dirait que tu t'es perdu");}
    else if (score>=350 && score <= 400){mvprintw(33,155,"   Comment es tu arrivé là?     ");}
    else if (score>=400 && score <= 450){mvprintw(33,150,"Tu ferais mieux de faire demi tour    ");}
    
    else if (score>=600 && score <= 650){mvprintw(33,155,"Tu oses défier mon autorité?");}
    
    else if (score>=680 && score <= 720){attron(COLOR_PAIR(2)); mvprintw(14,150,"*PAN*"); attroff(COLOR_PAIR(2));}//-2 hp  joueur qui tire une balle se situe sur pablo 
    
    else if (score>=700 && score <= 750){mvprintw(33,155,"AAARGH!");} 
    else if (score>=750 && score <= 780){mvprintw(33,155,"Comment oses tu?");}
    else if (score>=780 && score <= 820){mvprintw(33,155,"*Boit un shot de tequila*");} // -2 hp
    else if (score>=820 && score <= 860){mvprintw(33,155,"AAAH C'EST PIRE");}

    else if (score>=870 && score <= 920){mvprintw(33,155,"Tu vas le regretter");}
    else if (score>=920 && score <= 960){mvprintw(33,155,"Le canyon m'obéit");}
    else if (score>=960 && score <= 1010){mvprintw(33,155,"Tout va s'ebouler ahahaha");}
    else if (score>=1010 && score <= 1060){mvprintw(33,155,"*Retrecit le canyon*");}

    else if (score>=1170 && score <= 1220){mvprintw(33,155,"AH j'ai pris un caillou\n  sur la tête");} //-2  hp
    else if (score>=1220 && score <= 1290){mvprintw(33,155,"C'est pas moi l'intrus c'est lui !!");}
    else if (score>=1340 && score <= 1400){mvprintw(33,155,"Ce n'est pas grave je t'aurais quand meme");}
    
    else if (score>=1400 && score <= 1450){mvprintw(LINES/2,(COLS-50)/2,"*Le ciel s'assombrit*");}
    else if (score>=1500 && score <= 1550){mvprintw(33,155,"Tu crois que j'ai peur de la météo?");}
    else if (score>=1550 && score <= 1600){mvprintw(33,155,"Au contraire");}
    else if (score>=1700 && score <= 1730){mvprintw(LINES/2,(COLS-50)/2,"*La foudre frappe Pablo*");} //-4 hp
    else if (score>=1730 && score <= 1800){color_burnt_pablo(); mvprintw(33,155,"*AAAAAAH*");}
    else if (score>=1800 && score <= 1850){mvprintw(33,155,"Bien joué mais...");}
    else if (score>=1850 && score <= 1950){mvprintw(33,155,"I'LL BE BACK");}
    else if (score>=1950 && score <= 2000){mvprintw(33,155,"*Le corps de Pablo s'arrete de bouger*");}
    else if (score>=2000 && score <= 2050){mvprintw(33,155,"Ses graines ont disparu il a du fuir...");}
    else if (score>=2050 && score <= 10000){
        autopilot();
        win_Pablo_message();
        mvprintw((LINES/2) + 9,(COLS-46)/2,"Press q to quit");
        }

    
    else if (score>=10000 && score <= 10050){mvprintw(33,155,"Que fais tu encore dans ce canyon?");}
    else if (score>=10050 && score <= 10300){mvprintw(33,155,"Il n'y a plus rien a voir ici ");}
}



void win_Pablo_message(){
    // Spec : affiche l'ecran de fin du jeu
    // E,S : none , none
    
    mvprintw((LINES/2),((COLS-49)/2),  "         ## #           ");
    mvprintw((LINES/2)+1,((COLS-49)/2),"         ####         ");
    mvprintw((LINES/2)+2,((COLS-49)/2),"_________##_________ ");
    mvprintw((LINES/2)+3,((COLS-49)/2),"|                    |");
    mvprintw((LINES/2)+4,((COLS-49)/2),"|    YOU WIN!        |");
    mvprintw((LINES/2)+5,((COLS-49)/2),"|                    |");
    mvprintw((LINES/2)+6,((COLS-49)/2),"| You defeated Pablo |");
    mvprintw((LINES/2)+7,((COLS-49)/2 + 3),"|____________________|");
}