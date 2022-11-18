#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h> // pour les tests
#include <sys/time.h>




int main (){
    // for (int32_t i = 997; i >=0; i--){
    //     usleep(5000);
    //     printf("%d\n", i);
    // }

    // int *t = (int *)malloc(64); t[63] = 64;
    // printf("%d\n", t[63]); //ça marche

    // int t[256]; 
    // t[256] = 0 ;
    // printf("%d\n", t[256]); // On écrit en dehors du tableau
    // // ça marche mais on veut pas ça

    // int t[10][10]; 
    // t[0] = 4;
    // printf("%d\n", t[0]); //ça marche pas car t[0] est un pointeur

    // int t[10000][10000]; t[0][0] = 4;
    // printf("%d\n", t[0][0]); //ça marche pas car 10000 est trop grand stack overflow

    int *p = (int *)malloc(10000*sizeof(int));
    free(p);
    
    #define QUAT(x) ((x)*(x)*(x)*(x))

    uint64_t a,b,c;
    a = 1;
    b = 1;
    c = QUAT(a+b);
    printf("%lu\n", c);
    c= QUAT(a-b);
    printf("%lu\n", c);

}