#include <math.h>
#include <stdio.h>
//clang -lm hach_fonc.c 
#include <stdint.h>





// In: 0 <= a,b < 8589934583
// Out: 0 <= x < 8589934583 t.q. x ~ a * b [8589934583]
uint64_t mul339(uint64_t a, uint64_t b)
{
    //r=17
    uint64_t a1,a0,b1,b0;
    a1 = a/(pow(2,17));
    b1 = b/(pow(2,17));
    a0 = a%(2^17);
    b0 = b%(2^17);

    int res = a1*b1*18 + a1*b0*pow(2,17) + a0*b1*pow(2,17) + a0*b0;
   

    //div euclidienne par 2^33
    res = res/pow(2,33);
    //reduction a l'intervalle voulu
    res = (res+1)/2;
    
    return res;


}

int main(){return 1;}