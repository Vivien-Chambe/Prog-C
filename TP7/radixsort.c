#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h> // pour les tests
#include <sys/time.h>

#include "qsort.h"

// Radix sort

// Le but : Trier par base des entiers de 32 bits en utilisant un tri par dénombrement

// Tri par dénombrement 

// On suppose que les entiers sont codés sur 32 bits    

//denomsort : tri par dénombrement d'un tableau d'entiers de 32 bits

uint32_t denomsort(uint32_t *T,uint32_t *TS, size_t b,size_t Tlen){
    uint32_t *T2 = calloc(Tlen, sizeof(uint32_t));

    for(size_t i = 0; i < Tlen; i++){
        T2[T[i]] += 1;
    }
    for(size_t i = 1; i < b; i++){
        T2[i] += T2[i-1];
    }
    for(size_t i = Tlen; i > 0; i--){
        T2[T[i]] = T2[T[i]] -1 ;
        TS[T2[T[i]]] = T[i];
    }
    free(T2);
    return TS;

}

// radixsort : tri par base d'un tableau d'entiers de 32 bits

uint32_t radixsortu(size_t nlen, uint32_t *T, size_t b){
    uint32_t *T1 = malloc(nlen * sizeof(uint32_t));
    uint32_t *T2 = malloc(nlen * sizeof(uint32_t));
    for(int i = 0; i < nlen; i++){
        denomsort(T1,T2,b,i);
        memcpy(T1,T2,nlen * sizeof(uint32_t));
    }
    
    free(T2);
    return T1;
}

// Test

void test_radixsort(){
    
    size_t Tlen; // taille du tableau
    uint32_t *T; // tableau
    
    Tlen = 100; 
    T = malloc(sizeof(*T) * Tlen); 
    color_vert(1);
    printf("\nTest pour Tlen = %zu :",Tlen);    
    color_reset(); 
        
    for (int i=0 ; i<(int)Tlen ; i++ ){ // remplissage du tableau
        T[i]= rand()%Tlen +1;
    }
    int nlen = 32 * Tlen;
    uint32_t* T_trie = radixsortu(nlen,T,32);

    free (T); // libération de la mémoire
}

