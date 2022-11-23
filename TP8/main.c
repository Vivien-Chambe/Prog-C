#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


uint64_t hash_tp8l3mi(uint32_t k, size_t buflen, uint8_t buf[buflen])
{
uint64_t acc = 0;
for (size_t i = 0; i < buflen; i++)
{
acc ^= buf[i];
acc += (acc << 28) ^ (acc << 34);
acc *= (k | 1);
}
return acc;
}




struct bf
{
uint32_t key; // main hf key
size_t m; // bitsize
uint32_t k; // #hf
uint64_t bits[]; // “s”
};


struct bd
{
size_t sz;
void *dat;
};



struct bf *create_bf(uint32_t key, size_t m, uint64_t n){
    uint64_t nb_elem_bits = ((m/64)+1);
    struct bf *bloom = malloc(sizeof(struct bf)+ sizeof(uint64_t)*nb_elem_bits);

    uint32_t k = log(2) * (m/n);

    bloom->k = k;
    bloom->key = key;
    bloom->m = m;

    printf("k = %u, key = %u, m = %zu",k,key,m);

    for(int i = 0; i<nb_elem_bits;i++){
        bloom->bits[i] = 0;
    }

    return bloom;
}

void delete_bf(struct bf *BF){
    free(BF);
}

void insert(struct bf *s, struct bd elem){
    //on hash k fois elem dans h
    uint8_t *h = elem.dat;
    int index;
    
    for(int i = 0; i < s->&k ;i++){
        //printf(" %u ",s->k);
        uint32_t key = ((s->key) + i)% (uint32_t)(pow(2,32)-1);
        uint32_t emp = hash_tp8l3mi(key,elem.sz,h);
        emp = emp%64;
        //printf("emp : %u \n",emp);
        //on veut mettre le h-ieme bit à 1
        // On calcule ou mettre le h-ieme bit
        index = (((emp/64)-1)<=0) ? (emp/64): (emp/64)-1  ; // pour savoir dans quel element de bit on doit chercher
        s->bits[index] |= (uint64_t)(pow(2,emp%64)-1);
    }

    printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHH");
    


}

bool prbly_in_set(struct bf *s, struct bd elem){
    //on hash k fois elem dans h
    uint8_t *h = elem.dat;
    int index;
    for(int i = 0; i<s->k;i++){
        uint32_t key = ((s->key) + i)% (uint32_t)(pow(2,32)-1);
        uint64_t emp = hash_tp8l3mi(key,elem.sz,h);
        emp = emp%64;
        //on verifie le hieme bit
        index = ((emp/64-1)<=0)? (emp/64)-1 :(emp/64); 
        if(s->bits[index] & (uint64_t)(pow(2,emp%64)-1)){return false;} 
    }
    return true;
    
}

bool test_insert(size_t m, uint64_t n){
    uint32_t key = rand()%(uint32_t)(pow(2,32)-1);
    struct bf *bloom = create_bf(key,m,n);
    printf("\nJE VEUX K : %u \n",bloom->k);
    struct bd elem;
    elem.sz = 64;
    for(int i = 0; i<n;i++){
        elem.dat = &i;
        //insert(bloom,elem);
        printf("bits ");
        for(int j=0;j<((m/64)+1);j++){printf(" %lu",bloom->bits[j]);}
        printf("\n");
        if(!prbly_in_set(bloom,elem)){printf("Element non trouvé\n");return false;}
        
    }
    delete_bf(bloom);
    return true;
    
}

int main(){
    test_insert(128,64);

    return 0;

}