#include <stdint.h>
#include <stdlib.h>


#include "qsort.h"


int main(){
    srand(time(NULL));
    
    #ifdef QSORTU
    test_qsortu();
    #endif
    #ifdef DECROISSANT
    test_qsortu_decroissant();
    #endif

    return 1;
}