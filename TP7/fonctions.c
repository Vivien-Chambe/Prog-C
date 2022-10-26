#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h> // pour les tests
#include <sys/time.h>

#include "fonctions.h"



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

float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

void test_qsortu(){ //Test sur des tableaux de taille de 1 000 000 à 100 000 0000
    size_t Tlen;
    uint32_t *T;
    struct timeval start;
    struct timeval end;
    for (int i = 5;i<9; i++){
        Tlen = pow(10,i);
        T = malloc(sizeof(*T) * Tlen);

        printf("\nTest pour Tlen = %zu :",Tlen);


        for (int i=0 ; i<(int)Tlen ; i++ ){
            T[i]= rand()%Tlen +1;
        }
        gettimeofday(&start,NULL);

        qsortu(Tlen,T);

        gettimeofday(&end,NULL);

        printf("\nTemps écoulé: %f s",time_diff(&start,&end));
        if (sorted(Tlen ,T)){printf("\nTrié \n");} // teste la fonction qui verifie le tri
        else {printf("\n Non trié\n\n");}
        free (T);
    }

}

//couleur terminal?

//Q3) On peut prévoir que si le tableau est trié dans l'ordre décroissant on sera en pire cas et donc les temps seront grandement augmentés

void test_qsortu_decroissant(){
    size_t Tlen;
    uint32_t *T;
    struct timeval start;
    struct timeval end;
    for(int i = 0; i < 1000; i++){

        Tlen = i*10;
        T = malloc(sizeof(*T) * Tlen);

        printf("\n\nTri d'un tableau de taille %zu",Tlen);
        printf("    \nTableau aléatoire:");
        //Tableau random
        for (int i=0 ; i<(int)Tlen ; i++ ){
            T[i]= rand()%Tlen +1;
        }
        gettimeofday(&start,NULL);
        qsortu(Tlen,T);
        gettimeofday(&end,NULL);
        printf("\n  Temps écoulé: %f s",time_diff(&start,&end));
        
        printf("\n   Tableau décroissant:");
        //Tableau décroissant
        for (int i=0 ; i<(int)Tlen ; i++ ){
            T[Tlen - i - 1]= i;
        }

        gettimeofday(&start,NULL);
        qsortu(Tlen,T);
        gettimeofday(&end,NULL);
        printf("\nTemps écoulé: %f s",time_diff(&start,&end));

    }
}




int main(){
    srand(time(NULL));
    
    //test_qsortu();
    test_qsortu_decroissant();

    return 1;
}