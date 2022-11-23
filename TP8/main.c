#include <stdint.h>
#include <stdlib.h>
#include <math.h>


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
    struct bf *bloom = malloc(sizeof(struct bf)+ sizeof(uint32_t)*nb_elem_bits);

    uint32_t k = log(2) * (m/n);

    bloom->k = k;
    bloom->key = key;
    bloom->m = m;

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
    uint64_t h = elem.dat;
    for(int i = 0; i<s->k;i++){
        h = hash_tp8l3mi(s->key,sizeof(h),h);
    }
    //on veut mettre le h-ieme bit à 1
    // On calcule ou mettre le h-ieme bit
    int index = ((h/64)-1=0)?(h/64)-1,;
    int ind_bit = 

}