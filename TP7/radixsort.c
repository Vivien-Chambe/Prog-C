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

void denomsort(size_t Tlen, uint32_t T[Tlen], int k){
    // cherche le plus grand élément de T
    uint32_t max = 0;
    for (int i = 0; i<Tlen; i++){
        if (T[i]>max){max = T[i];}
    }
    // on crée un tableau de taille max+1
    uint32_t *T2;
    T2 = malloc(sizeof(*T2) * (max+1));
    // on initialise le tableau à 0
    for (int i = 0; i<(max+1); i++){
        T2[i] = 0;
    }
    // on compte le nombre d'occurences de chaque élément de T
    for (int i = 0; i<Tlen; i++){
        T2[T[i]] = T2[T[i]] + 1;
    }
    // on remplit T avec les éléments de T2
    int j = 0;
    for (int i = 0; i<(max+1); i++){
        while (T2[i]>0){
            T[j] = i;
            j = j + 1;
            T2[i] = T2[i] - 1;
        }
    }
    free(T2);

}

// radixsort : tri par base d'un tableau d'entiers de 32 bits

void radixsort(size_t Tlen, uint32_t T[Tlen]){
    // on trie par dénombrement les éléments de T en fonction de leur poids faible
    denomsort(Tlen,T,0);
    // on trie par dénombrement les éléments de T en fonction de leur poids fort
    denomsort(Tlen,T,16);
}

// Test


