#include <ncurses.h>
//*? taille fixe dans main 
//*! taille du canyon soit inferieure a la taille du jeux

// focntions pour l'aleatoire des nouveaux etats

void print_state(char state){ // imprime l'etat courant
    for(int i = 0; i<sizeof(state);i++){
        printf("%c",state[&i]);
    }
    printf("\n");

}

void init_game(){ // Initialise la partie et les x premieres lignes et la position du classique
    // char state[] = "                                                                                                        ";
    // for(int i = 0;i<71;i++){
    //     state[i] = ' ';
    // }
    // int droite_canyon = ((sizeof(state)-taille_c)/2)%2;
    // state[droite_canyon] = '*';
    // state[droite_canyon+taille_c];
    // for(int i = 0;i<10;i++){
    //     print_state(state);
    // }
    // state[((sizeof(state)-1)/2)+1] = 'T';
    // print_state(state);

    
    move(LINES - 1, COLS - 1);  // Déplace le curseur tout en bas à droite de l'écran
    addch('.');
    int c = getch();
    if ( KEY_LEFT == c){
        refresh();
        move(LINES - 2, COLS -2);
        getch();
    }
    
    if (getchar()== c){
        endwin;
    }

}


//*! char new_state(char state){ }

//*! void test_crash(){}
void player_movement(int key){
}

void game_over(int EXIT) {
    EXIT = true;
    endwin();
    printf("Game Over!\n");
}

void collision(){
    //doit detecter si le joueur et a la position d'un des murs
    //et soit     quitte le jeu avec un message        soit renvoie un bool avec la value collis
}