#include <math.h>
#include <stdio.h>
//clang -lm hach_fonc.c 
#include <stdint.h>





// In: 0 <= a,b < 8589934583
// Out: 0 <= x < 8589934583 t.q. x ~ a * b [8589934583]
uint64_t mul339(uint64_t a, uint64_t b)
{
    uint64_t power17 = 131072;
    uint64_t power33 = 8589934592;
    //r=17
    uint64_t a1,a0,b1,b0;
    a1 = a/(power17);
    b1 = b/(power17);
    a0 = a%(power17);
    b0 = b%(power17);

    uint64_t res = a1*b1*18 + a1*b0*power17 + a0*b1*power17 + a0*b0;
    printf("res etape 1: %lu \n",res);
    printf("inférieur à 2_54: %d \n",res<pow(2,54));


    //div euclidienne par 2^33
    uint64_t res1,res0;
    res1 = res/power33;
    res0 = res%power33;
    res = (res1*9 + res0);
    printf("res etape 2: %lu \n",res);
    printf("inférieur à 2 × (233 − 9) − 1: %d \n",res<2*(power33-9)-1);

    //reduction a l'intervalle voulu
    if (res<(power33-9)){return res ;}

    else{return (res-(power33-9));}


}


uint64_t hash339(uint64_t k, size_t buflen, uint8_t buf[buflen]){
    
}



int main(){
    uint64_t res = mul339 ( 32768,32768);
    printf ("res : %lu \n", res);
    return 1;}