#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h> // pour les tests
#include <sys/time.h>

void sorted(size_t Tlen, const uint32_t T[Tlen]);

void test_qsortu();
void test_qsortu_aleatoire();
void test_qsortu_decroissant();
void test_qsortu_aleatoire_decroissant();
void test_qsortg();
void test_compare_qsorts();
void qsortu_aleatoire(size_t Tlen, uint32_t T[Tlen]);
void qsortg(void* t, size_t Tlen, size_t size, int (*comp)(const void *, const void *),int d,int f);
int cmpint(const void* i1,const void* i2);
