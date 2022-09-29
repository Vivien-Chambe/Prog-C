#include <ncurses.h> //contient les fonctions basiques de jeu que l'on utilise
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h> // utile pour l'initialisation de la seed

#include "fonctions.h"
#include "ascii_art.h"



int main(){
    srand(time(NULL)); //Nous initiallisons la seed avec time car il n'est pas necessaire dans notre jeu d'avoir un meilleur prng 
    //(nous souhaitons juste que le joueur n'ait pas l'impression d'avoir les meme seed en boucles)
    initscr(); //Initialise la fenetre de "travail"
    keypad(stdscr, true); //Autorise les entrées utilisateurs
    noecho(); //Désactive l'affichage des entrées utilisateur
    cbreak(); //Désactive le bloquage de la prise en compte des entrees utilisateurs
    color_creation(); //met en route l'utilisation des couleurs
    start_screen(); // affiche le menu d'acceuil
    curs_set(0); //Désactive l'affichage du curseur
    timeout(0);  // N'attends pas un getch() pour avancer
    
    int play = 1; // variables pour l'etat de la partie
    int c;  // variable pour recuperer les entrees utilisateurs pendant le jeu 
    int speed_modifier = adjust_difficulty(); // l'indice de vittesse
    //Initialisation
    show_perso(speed_modifier); // affiche le cycliste a sa position initiale
    init_level(); // affiche les premiers murs du canyon (ligne droite) en fonction de la taille du canyon
    //
    
    //Boucle du jeu
    while (play == 1){
        c =  getch();
        if(c == 'q'){play = 0;break;} //on verifie si le joueur souhaite quitter le jeu et si oui on quiite

        // Update le jeu (Coordonnées)
        #ifdef AUTOPILOT 
        autopilot(); //mise en route de l'autopilot qui calcule la position suivante du cycliste
        #else    
        else{update_perso_position(c);} //sinon met a jour les coordonnees du cycliste en fonction des entrees du joueur
        #endif
        update_level(); //calcule et met a jour le tableau contenant le canyon
        speed_modifier = adjust_difficulty(); //met a jour l'indice de vittesse
        erase(); //efface la fenetre
        //

        //Affichage 
        print_score();//affiche le score actuel du joueur
        show_perso(speed_modifier); //affiche la nouvelle position du joueur 
        show_level(); //affiche le nouveau canyon

        #ifdef DEBUG
        debug(); //affiche les informations de debug
        #endif

        //Fin de jeu
        if(check_collision()!=0){
            timeout(-1);
            play = 0;
            mvprintw(LINES-5,check_collision(),"x"); //affiche la fin du jeu
            mvprintw(LINES/2,COLS/2,"YOU DEAD!!!!!!"); //affiche la fin du jeu
            refresh(); 
            sleep(3);
            break;
        }
        //
        refresh(); // Print changes on screen
        usleep(HZ_RATE*1000 - speed_modifier*3000);
        //
    }
    getch();
    endwin();

    return 0;

}