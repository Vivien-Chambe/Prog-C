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
    uint32_t k = s->k;
    for(int i = 0; i < k ;i++){
        uint32_t key = ((s->key) + i)% (uint32_t)(pow(2,32)-1);
        uint32_t emp = hash_tp8l3mi(key,elem.sz,h);
        emp = emp%64;
        //on veut mettre le h-ieme bit à 1
        // On calcule ou mettre le h-ieme bit
        index = (((emp/64))<=0) ? (emp/64): (emp/64)-1  ; // pour savoir dans quel element de bit on doit chercher
        uint64_t mask = 1;
        mask = mask << (emp%64); // on veut mettre le emp-ieme bit à 1 donc on décale de emp%64
        
        s->bits[index] = s->bits[index] | mask; // on met le emp-ieme bit à 1

    }
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
        index = ((emp/64)<=0)? (emp/64)-1 :(emp/64); 
        if(!(s->bits[index] & (uint64_t)(pow(2,emp%64)))){return false;} 
    }
    return true;
    
}



bool test_insert(size_t m, uint64_t n){
    uint32_t key = rand()%(uint32_t)(pow(2,32)-1);
    struct bf *bloom = create_bf(key,m,n);
    uint64_t *elements = malloc(sizeof(uint64_t)*n);
    for(int i = 0; i<n;i++){
        uint64_t r = rand() + 1;
        elements[i] = r;
    }
    struct bd elem;
    elem.sz = 64;
    for(int i = 0; i<n;i++){
        elem.dat = &elements[i];
        insert(bloom,elem);    
    }
    for(int i = 0; i<n;i++){
        elem.dat = &elements[i];
        if(!prbly_in_set(bloom,elem)){
            return false;
        }
    }
    delete_bf(bloom);
    return true;
    
    }   

uint64_t test_fp(size_t m, uint64_t n, uint64_t nfpt){
    uint32_t key = rand()%(uint32_t)(pow(2,32)-1);
    struct bf *bloom = create_bf(key,m,n);
    uint64_t *elements = malloc(sizeof(uint64_t)*n);
    for(int i = 0; i<n;i++){
        uint64_t r = rand() + 1;
        elements[i] = r;
    }
    struct bd elem;
    elem.sz = 64;
    for(int i = 0; i<n;i++){
        elem.dat = &elements[i];
        insert(bloom,elem);    
    }
    uint64_t *fpt = malloc(sizeof(uint64_t)*nfpt);
    for(int i = 0; i<nfpt;i++){
        uint64_t r = rand() + 1;
        fpt[i] = r;
    }
    uint64_t nb_fp = 0;
    for(int i = 0; i<nfpt;i++){
        elem.dat = &fpt[i];
        if(prbly_in_set(bloom,elem)){
            nb_fp++;
        }
    }
    delete_bf(bloom);
    return nb_fp;

}

int main(){
    uint64_t nb_fp = test_fp(64,64,100000);
    printf("%lu \n",nb_fp);

    nb_fp = test_fp(1280,1280,100000);
    printf("%lu \n",nb_fp);

    nb_fp = test_fp(64,64*6,100000);
    printf("%lu \n",nb_fp);

    for (int i = 1; i<=40;i++){
        nb_fp = test_fp(64*i,64,64000);
        printf("Pour m=64*%d n=64 et nfpt = 64000 : %lu \n",i,nb_fp);
    }
    printf("\n");
    printf("\033[0;32m");
    for (int i = 1; i<=40;i++){
        nb_fp = test_fp(100*i,100,100000);
        printf("Pour m=100*%d n=100 et nfpt = 64000 : %lu \n",i,nb_fp);
    }
    printf("\033[0m");
    printf("\n");
    for (int i = 1; i<=40;i++){
        nb_fp = test_fp(256*i,256,256000);
        printf("Pour m=256*%d n=256 et nfpt = 256000 : %lu \n",i,nb_fp);
    }
    printf("\n");
    printf("\033[0;32m");
    for (int i = 1; i<=40;i++){
        nb_fp = test_fp(1024*i,1024,1024000);
        printf("Pour m=1024*%d n=1024 et nfpt = 1024000 : %lu \n",i,nb_fp);
    }
    printf("\033[0m");
    return 0;

}