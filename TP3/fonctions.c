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

char init_game(int taille_c){ // Initialise la partie et les x premieres lignes et la position du classique
    char state[71];
    for(int i = 0;i<71;i++){
        state[i] = ' ';
    }
    int droite_canyon = ((71-taille_c)/2)%2;
    state[droite_canyon] = '*';
    state[droite_canyon+taille_c];
    for(int i = 0;i<10;i++){
        print_state(state);
    }
    state[(70/2)+1] = 'T';
    print_state(state);
    return state;

}


char new_state(char state){ 
    
}

void test_crash(){
    

}
