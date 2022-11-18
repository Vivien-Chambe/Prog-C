#include <stdint.h>
#include <stdlib.h>
#include <string.h>
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

void test_v1(size_t Tlen, uint32_t T[Tlen]){
    struct timeval start; // temps de début
    struct timeval end; // temps de fin
    T = malloc(sizeof(*T) * Tlen); 
    color_vert(1);  
    printf("\nTest pour Tlen = %lu millions :",Tlen/1000000);    
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

}

void test_qsortu(){ //Test sur des tableaux de taille de 1 000 000 à 100 000 0000
    size_t Tlen; // taille du tableau
    uint32_t *T = NULL; // tableau
    
    test_v1(Tlen = 1000000,T);
    test_v1(Tlen = 5000000,T);
    test_v1(Tlen = 10000000,T);
    test_v1(Tlen = 50000000,T);
    test_v1(Tlen = 100000000,T);
    free (T); // libération de la mémoire
}


//Q3) On peut prévoir que si le tableau est trié dans l'ordre décroissant on sera en pire cas et donc les temps seront grandement augmentés

//1)
//Permets de voir que plus la taille du tableau est grande plus l'ecart entre le 
//temps de tri pour un tab random et un tab trie décroissant est grand
void test_qsortu_decroissant(){
    size_t Tlen;
    uint32_t *T;
    struct timeval start;
    struct timeval end;
    for(int i = 2; i <= 10; i++){

        Tlen = i*10;
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

//2)Qsort avec un pivot aléatoire

int partitionqsortu_aleatoire(size_t Tlen , uint32_t T[Tlen], int d, int f){
    
    uint32_t ind = rand()%(f-d+1)+d;
    uint32_t x = T[ind];

    T[ind] = T[f];
    T[f] = x;
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

void quicksortoxu_aleatoire(size_t Tlen,uint32_t T[Tlen],int d,int f){
    if (d<f){
        //for (int i=0 ; i<(int)Tlen ; i++ ){printf("%d ",T[i]);}printf("\n"); // affiche le tableau
        int x = partitionqsortu_aleatoire(Tlen,T,d,f);
        quicksortoxu_aleatoire(Tlen,T,d,x-1);
        quicksortoxu_aleatoire(Tlen,T,x+1,f);
    }

}

void qsortu_aleatoire(size_t Tlen, uint32_t T[Tlen]){
    int d,f;
    d = 0;
    f = Tlen-1;
    if (d<f){
        quicksortoxu_aleatoire(Tlen,T,d,f);
    }
}

void test_qsortu_aleatoire(){
    size_t Tlen; // taille du tableau
    uint32_t *T; // tableau
    struct timeval start; // temps de début
    struct timeval end; // temps de fin
    for (int i = 5;i<9; i++){ 
        Tlen = i*100000;
        T = malloc(sizeof(*T) * Tlen); 
        color_vert(1);  
        printf("\nTest pour Tlen = %zu :",Tlen);    
        color_reset(); 

        for (int i=0 ; i<(int)Tlen ; i++ ){ // remplissage du tableau
            T[i]= rand()%Tlen +1;
        }

        gettimeofday(&start,NULL); // début du chronomètre

        qsortu_aleatoire(Tlen,T); // tri du tableau

        gettimeofday(&end,NULL); // fin du chronomètre

        printf("\nTemps écoulé: %f s",time_diff(&start,&end)); // affichage du temps écoulé
        if (sorted(Tlen ,T)){color_vert(1);printf("\nTrié \n");color_reset();} // teste la fonction qui verifie le tri
        else {color_rouge(1);printf("\n Non trié\n\n");color_reset();} 
        
        free (T); // libération de la mémoire
    }
}


//3)

// Compare le temps de tri d'un tableau random,
// d'un tableau decroissant avec pivot à la fin
// et d'un tableau décroissant avec pivot aléatoire
void test_qsortu_aleatoire_decroissant(){
    size_t Tlen;
    uint32_t *T;
    struct timeval start;
    struct timeval end;
    for(int i = 2; i <= 10; i++){

        Tlen = i*10;
        T = malloc(sizeof(*T) * Tlen);

        color_vert(1);
        printf("\n\nTri d'un tableau de taille %zu",Tlen);
        color_reset();
        
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
        for (int i=0 ; i<(int)Tlen ; i++ ){
            T[Tlen - i - 1]= i;
        }
        gettimeofday(&start,NULL);
        qsortu_aleatoire(Tlen,T);
        gettimeofday(&end,NULL);
        printf("\n  Temps écoulé: %f s",time_diff(&start,&end));

    free(T);
    printf("\n");
    
    }
}


//Q4) Qsortg

//1)

int cmpint(const void* i1,const void* i2)
{
    uint32_t *a = (uint32_t*)i1;
    uint32_t *b = (uint32_t*)i2;
    if ((*a) > (*b))
        return 1;
    else if ((*a) < (*b))
        return -1;
    else
        return 0;
}

int partitionqsortg(void* T, size_t Tlen ,size_t size, int (*comp)(const void *, const void *) , int d, int f){
    int ind = rand()%(f-d+1)+d;
    int n = f;

    void* x = malloc(size);
    memcpy(x,T+(ind*size),size);

    void* tmp = malloc(size);
    memcpy(tmp,T + ind*size,size);
    memcpy(T + ind*size,T+n*size,size);
    memcpy(T+n*size,tmp,size);

    for (int i = f-1 ; i>=d ; i--){
        if (comp(T+(i*size),x)>0){
            memcpy(T+(n*size),T+(i*size),size);
            memcpy(T+(i*size),T+((n-1)*size),size);
            n = n-1 ;
        }
    }
    memcpy(T+(n*size),x,size);
    free(x);
    return n;
}

void qsortg(void* t, size_t Tlen, size_t size, int (*comp)(const void *, const void *),int d,int f){
    if (d<f){
        int x = partitionqsortg(t,Tlen,size,comp,d,f);
        qsortg(t,Tlen,size,comp,d,x-1);
        qsortg(t,Tlen,size,comp,x+1,f);
    }
}


void test_qsortg(){ //Test sur des tableaux de taille de 1 000 000 à 100 000 0000
    size_t Tlen; // taille du tableau
    uint32_t *T; // tableau
    struct timeval start; // temps de début
    struct timeval end; // temps de fin
    for (int i = 5;i<9; i++){ 
        Tlen = i*1000; 
        T = malloc(sizeof(*T) * Tlen); 
        color_vert(1);
        printf("\nTest pour Tlen = %zu :",Tlen);    
        color_reset(); 
        
        for (int i=0 ; i<(int)Tlen ; i++ ){ // remplissage du tableau
            T[i]= rand()%Tlen +1;
        }

        //for (int i=0 ; i<(int)Tlen ; i++ ){printf("%d ",T[i]);}printf("\n"); // affiche le tableau
        
        gettimeofday(&start,NULL); // début du chronomètre

        qsortg(T,Tlen,sizeof(int),cmpint,0,Tlen-1); // tri du tableau
        

        gettimeofday(&end,NULL); // fin du chronomètre

        printf("\nTemps écoulé: %f s",time_diff(&start,&end)); // affichage du temps écoulé
        if (sorted(Tlen ,T)){color_vert(1);printf("\nTrié \n");color_reset();} // teste la fonction qui verifie le tri
        else {color_rouge(1);printf("\n Non trié\n");color_reset();}

        //for (int i=0 ; i<(int)Tlen ; i++ ){printf("%d ",T[i]);}printf("\n"); // affiche le tableau trié 

        free (T); // libération de la mémoire
    }

}

void test_compare_qsorts(){
    size_t Tlen; // taille du tableau
    uint32_t *T; // tableau
    struct timeval start; // temps de début
    struct timeval end; // temps de fin
    for (int i = 5;i<10; i++){ 
        Tlen = i*100000; 
        T = malloc(sizeof(*T) * Tlen); 
        
        color_vert(1);
        printf("\nTest pour Tlen = %zu :",Tlen);    
        color_reset(); 
        
        for (int i=0 ; i<(int)Tlen ; i++ ){ // remplissage du tableau
            T[i]= rand()%Tlen +1;
        }

        gettimeofday(&start,NULL); // début du chronomètre

        qsortg(T,Tlen,sizeof(int),cmpint,0,Tlen-1); // tri du tableau
        
        gettimeofday(&end,NULL); // fin du chronomètre

        printf("\n  Temps écoulé avec qsortg: %f s",time_diff(&start,&end)); // affichage du temps écoulé

        for (int i=0 ; i<(int)Tlen ; i++ ){ // remplissage du tableau
            T[i]= rand()%Tlen +1;
        }

        gettimeofday(&start,NULL);
        qsortu_aleatoire(Tlen,T);
        gettimeofday(&end,NULL);
        printf("\n  Temps écoulé avec qsortu: %f s",time_diff(&start,&end));

        for (int i=0 ; i<(int)Tlen ; i++ ){ // remplissage du tableau
            T[i]= rand()%Tlen +1;
        }
        gettimeofday(&start,NULL);
        qsort(T,Tlen,sizeof(int),cmpint);
        gettimeofday(&end,NULL);
        printf("\n  Temps écoulé avec qsort : %f s",time_diff(&start,&end));

        
    }
printf("\n");
free (T); // libération de la mémoire
}