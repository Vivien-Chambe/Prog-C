#include <stdint.h>
#include <stdlib.h>
#ifndef TEST 
#define TEST 0
#endif 


#include "qsort.h"
#include "radixsort.h"
#include "help.h"


int main(){
    srand(time(NULL));
    
    printf("\n\n");
    #if TEST == 0
    color_rouge(1); printf("Aucun test n'est effectué, voir README.md pour plus d'informations\n");
    #elif TEST == 1
    color_bleu(1); printf("Test de qsortu\n");
    test_qsortu(); // Verifie que qsortu fonctionne correctement
    #elif TEST == 2
    color_bleu(1); printf("Test de qsortu avec des tableaux décroissants\n");
    color_bleu(1); test_qsortu_decroissant(); // Teste qsortu sur des listes décroissantes
    #elif TEST == 3
    color_bleu(1); printf("Test de qsortu avec un pivot aléatoire\n");
    test_qsortu_aleatoire(); // Verifie que qsortu avec un pivot aleatoire fonctionne correctement
    #elif TEST == 4
    color_bleu(1); printf("Comparatif de qsortu avec un pivot aléatoire et pivot à la fin sur des tableaux décroissants\n");
    test_qsortu_aleatoire_decroissant(); // Compare le temps de tri en prenant le pivot a la fin ou en aleatoire
    #elif TEST == 5
    color_bleu(1); printf("Test de qsortg\n");
    test_qsortg(); // Verifie que qsortg fonctionne correctement
    #elif TEST == 6
    color_bleu(1); printf("Comparatif de qsortu, qsortg, et qsort standard\n");
    test_compare_qsorts(); // Compare le temps de tri de qsortu, qsortg et qsort de la librairei standard
    #elif TEST == 7
    test_radixsort(); // Teste radixsort
    #endif

    return 0;
}