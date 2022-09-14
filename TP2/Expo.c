#include <stdio.h>
#include <stdint.h>
#include <assert.h>

//question n°1

// 1. la taille du produit peut creer un overflow car on a 64 bits et donc avec seulement 536870909
// on risque de dépasser la taille disponible ce qui n'arrive pas avec l'addition car on resterait dans des valeurs
// inferieures à 2^^64

//2.inferieur a la racine de  2^^ le nombre de bit que l'on utilise



uint64_t add293(uint64_t a,uint64_t b){
    return ((a+b) % 536870909);
}

uint64_t mul293(uint64_t a, uint64_t b)
{
return ((a * b) % 536870909);
}



uint64_t add109(uint64_t a,uint64_t b){
    return ((a+b) % 1099511627689);
}

uint64_t mul109(uint64_t a, uint64_t b)
{
return ((a * b) % 1099511627689);
}


// In: 0 <= a < 536870909
// In: 0 <= n < 2**64
// Out: 0 <= x < 536870909 t.q. x ~ a^n [536870909]
uint64_t slow_exp(uint64_t a, uint64_t n)
{
    int exp = 1;
    if (n == 0)
    {
        return exp;
    }
    else{
        
        for(int i = 0; i<n ; i++)
        {
            exp = mul293(exp , a); 
        }
    }
    return (exp);
}

uint64_t slow_exp_nomod(uint64_t a, uint64_t n)
{
    int exp = 1;
    if (n == 0){return exp;}
    else{
        for(int i = 0; i<n ; i++) { exp = exp * a;  }
        }
    return (exp);
}

void testslowexp(int n)
{
    //assert(slow_exp(2022,36) == 233688688);
    //assert(slow_exp(2022,37)== 72127216);
    //assert(slow_exp(200022,36)== 504243905);
    //assert(slow_exp(200022,37)== 84175716);
    //assert(slow_exp(2022,1e9)== 274298323);
    
    for(int i = 1; i<n;i++){
    printf("10^%d :%lu \n",i, (slow_exp(2022,slow_exp_nomod(10,i))));
}
}

//Question n°3 :

// In: 0 <= a < 536870909
// In: 0 <= n < 2**64
// Out: 0 <= x < 536870909 t.q. x ~ a^n [536870909]
uint64_t fast_exp_rec(uint64_t a, uint64_t n)
{
    uint64_t r=1;
    
    if (n==0){ return r;}
    r = (fast_exp_rec(a,n/2));
    if (n % 2 == 0){ return mul293(r,r); }
    else {return mul293(mul293(r,r),a);}
    
    
}

void testrecexp(int n)
{
    assert(fast_exp_rec(2022,36) == 233688688);
    assert(fast_exp_rec(2022,37)== 72127216);
    assert(fast_exp_rec(200022,36)== 504243905);
    assert(fast_exp_rec(200022,37)== 84175716);
    assert(fast_exp_rec(2022,1e9)== 274298323);
    
    for(int i = 1; i<n;i++){
    printf("10^%d :%lu \n",i, (fast_exp_rec(2022,fast_exp_rec(10,i))));
    }
}

//temps d'exeion grandement ameliore passant a seulement 0,015s pour n = 10
//le cout est maintenant

int main()
{

    //printf("add293 :%lu \n",add293(456789,5432109));
    //printf("mul293 :%lu \n",mul293(456789,5432109));
    //printf("add109 :%lu \n",add109(456789,5432109));
    //printf("mul109 :%lu \n",mul109(456789,5432109));

    //testslowexp(10);    
    //le cout de la fonction est exponentiel si on affiche les resultats pour 4 test nous avons 0,013sec 
    // et pour 9 nous avons 15 sec
    printf("%d ^ %f = %lu \n",2022,1e19,fast_exp_rec(2022,1e9));
    testrecexp(10);
    return 0;
}
