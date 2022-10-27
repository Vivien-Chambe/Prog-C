#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h> // pour les tests
#include <sys/time.h>

#include "help.h"

//Q1)

int sorted(size_t Tlen, const uint32_t T[Tlen]){
    for (int i = 0; i<(Tlen-1);i++){
        if (T[i]>T[i+1]){return 0;}
        }
    return 1;
}

   

//Q2)
int partitionqsort(size_t Tlen , uint32_t T[Tlen], int d, int f){
    uint32_t x = T[f];
    int n = f;
    for (int i = f-1 ; i>=d ; i--){
        if (T[i]>x){
            T[n] = T[i];
            T[i] = T[n-1];
            n = n-1 ;
        }
    }
    T[n] = x;
    return n;
}
void quicksortox(size_t Tlen,uint32_t T[Tlen],int d,int f){
    if (d<f){
        int x = partitionqsort(Tlen,T,d,f);
        quicksortox(Tlen,T,d,x-1);
        quicksortox(Tlen,T,x+1,f);
    }

}
void qsortu(size_t Tlen, uint32_t T[Tlen]){
    int d,f;
    d = 0;
    f = Tlen-1;
    if (d<f){
        quicksortox(Tlen,T,d,f);
    }
}

void test_qsortu(){ //Test sur des tableaux de taille de 1 000 000 à 100 000 0000
    size_t Tlen; // taille du tableau
    uint32_t *T; // tableau
    struct timeval start; // temps de début
    struct timeval end; // temps de fin
    for (int i = 5;i<9; i++){ 
        Tlen = pow(10,i); 
        T = malloc(sizeof(*T) * Tlen); 
        color_vert(1);  
        printf("\nTest pour Tlen = %zu :",Tlen);    
        color_reset(); 

        for (int i=0 ; i<(int)Tlen ; i++ ){ // remplissage du tableau
            T[i]= rand()%Tlen +1;
        }
        gettimeofday(&start,NULL); // début du chronomètre

        qsortu(Tlen,T); // tri du tableau

        gettimeofday(&end,NULL); // fin du chronomètre

        printf("\nTemps écoulé: %f s",time_diff(&start,&end)); // affichage du temps écoulé
        if (sorted(Tlen ,T)){color_vert(1);printf("\nTrié \n");color_reset();} // teste la fonction qui verifie le tri
        else {color_rouge(1);printf("\n Non trié\n\n");color_reset();} 
        free (T); // libération de la mémoire
    }

}

//couleur terminal?

//Q3) On peut prévoir que si le tableau est trié dans l'ordre décroissant on sera en pire cas et donc les temps seront grandement augmentés

//1)
//Permets de voir que plus la taille du tableau est grande plus l'ecart entre le 
//temps de tri pour un tab random et un tab trie décroissant est grand
// On teste sur des tableaux de taille 2000 à 10 000 car en dessous il est plus compliqué de voir de réelles différences
void test_qsortu_decroissant(){
    size_t Tlen;
    uint32_t *T;
    struct timeval start;
    struct timeval end;
    for(int i = 2; i <= 10; i++){

        Tlen = i*1000;
        T = malloc(sizeof(*T) * Tlen);

        color_vert(1);
        printf("\n\nTri d'un tableau de taille %zu",Tlen);
        color_reset();
        printf("\nTableau aléatoire:");
        //Tableau random
        for (int i=0 ; i<(int)Tlen ; i++ ){
            T[i]= rand()%Tlen +1;
        }
        gettimeofday(&start,NULL);
        qsortu(Tlen,T);
        gettimeofday(&end,NULL);
        printf("\n  Temps écoulé: %f s",time_diff(&start,&end));
        
        printf("\nTableau décroissant:");
        //Tableau décroissant
        for (int i=0 ; i<(int)Tlen ; i++ ){
            T[Tlen - i - 1]= i;
        }

        gettimeofday(&start,NULL);
        qsortu(Tlen,T);
        gettimeofday(&end,NULL);
        printf("\n  Temps écoulé: %f s",time_diff(&start,&end));

        free(T);
    printf("\n");
    
    }
}

//2)

int partitionqsort_uniforme(size_t Tlen , uint32_t T[Tlen], int d, int f){
    uint32_t x = rand()%(f-d+1)+d;
    int n = f;
    for (int i = f-1 ; i>=d ; i--){
        if (T[i]>x){
            T[n] = T[i];
            T[i] = T[n-1];
            n = n-1 ;
        }
    }
    T[n] = x;
    return n;
}

void quicksortox_uniforme(size_t Tlen,uint32_t T[Tlen],int d,int f){
    if (d<f){
        int x = partitionqsort_uniforme(Tlen,T,d,f);
        quicksortox_uniforme(Tlen,T,d,x-1);
        quicksortox_uniforme(Tlen,T,x+1,f);
    }

}

void qsortu_uniforme(size_t Tlen, uint32_t T[Tlen]){
    int d,f;
    d = 0;
    f = Tlen-1;
    if (d<f){
        quicksortox_uniforme(Tlen,T,d,f);
    }
}


//3)

// Compare le temps de tri d'un tableau random,
// d'un tableau decroissant avec pivot à la fin
// et d'un tableau décroissant avec pivot aléatoire
void test_qsortu_uniforme_decroissant(){
    size_t Tlen;
    uint32_t *T;
    struct timeval start;
    struct timeval end;
    for(int i = 2; i <= 10; i++){

        Tlen = i*1000;
        T = malloc(sizeof(*T) * Tlen);

        color_vert(1);
        printf("\n\nTri d'un tableau de taille %zu",Tlen);
        color_reset();
        printf("\nTableau aléatoire:");
        //Tableau random
        for (int i=0 ; i<(int)Tlen ; i++ ){
            T[i]= rand()%Tlen +1;
        }
        gettimeofday(&start,NULL);
        qsortu_uniforme(Tlen,T);
        gettimeofday(&end,NULL);
        printf("\n  Temps écoulé: %f s",time_diff(&start,&end));
        
        printf("\nTableau décroissant avec pivot à la fin:");
        //Tableau décroissant
        for (int i=0 ; i<(int)Tlen ; i++ ){
            T[Tlen - i - 1]= i;
        }

        gettimeofday(&start,NULL);
        qsortu(Tlen,T);
        gettimeofday(&end,NULL);
        printf("\n  Temps écoulé: %f s",time_diff(&start,&end));

        printf("\nTableau décroissant avec pivot aléatoire:");
        //Tableau décroissant
        for (int i=0 ; i<(int)Tlen ; i++ ){
            T[Tlen - i - 1]= i;
        }

        gettimeofday(&start,NULL);
        qsortu_uniforme(Tlen,T);
        gettimeofday(&end,NULL);
        printf("\n  Temps écoulé: %f s",time_diff(&start,&end));

        free(T);
    printf("\n");
    
    }
}


//Q4)

//1)

