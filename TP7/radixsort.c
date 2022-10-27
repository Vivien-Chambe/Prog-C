#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h> // pour les tests
#include <sys/time.h>


// Radix sort

// Le but : Trier par base des entiers de 32 bits en utilisant un tri par dénombrement

// Tri par dénombrement 

// On suppose que les entiers sont codés sur 32 bits    

//denomsort : tri par dénombrement d'un tableau d'entiers de 32 bits

void denomsort(size_t Tlen, uint32_t T[Tlen], int k){
    int i,j;
    int *C;
    C = malloc(sizeof(*C) * (k+1));
    for (i = 0; i<=k; i++){
        C[i] = 0;
    }
    for (j = 0; j<Tlen; j++){
        C[T[j]] = C[T[j]] + 1;
    }
    for (i = 1; i<=k; i++){
        C[i] = C[i] + C[i-1];
    }
    for (j = Tlen-1; j>=0; j--){
        T[C[T[j]]-1] = T[j];
        C[T[j]] = C[T[j]] - 1;
    }
    free(C);
}

uint32_t radix_sortu(uint32_t *T, uint32_t n) {

}

