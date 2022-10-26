#include <sys/time.h>
#include <stdint.h>
#include <stdio.h>

float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}


// Ces fonctions permettent de changer la couleur du texte dans le terminal
// (pour les tests)
// Je les aies récupérées du projet de MAP401

void color_noir (int bold) {
    printf("\033[%d;30m", !!bold);
}

void color_rouge (int bold) {
    printf("\033[%d;31m", !!bold);
}

void color_vert (int bold) {
    printf("\033[%d;32m", !!bold);
}

void color_jaune (int bold) {
    printf("\033[%d;33m", !!bold);
}

void color_bleu (int bold) {
    printf("\033[%d;34m", !!bold);
}

void color_violet (int bold) {
    printf("\033[%d;35m", !!bold);
}

void color_cyan (int bold) {
    printf("\033[%d;36m", !!bold);
}

void color_blanc (int bold) {
    printf("\033[%d;37m", !!bold);
}

void color_reset () {
    printf("\033[0m");
}