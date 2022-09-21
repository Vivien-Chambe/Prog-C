###############################################################################
# Makefile pour la compilation des programmes 
###############################################################################

#### variables ####
CC = clang -g -Wall -lncurses

EXECUTABLES = The_Death_Canyon_of_DOOM

all : $(EXECUTABLES)


###############################################################################
# 			Regles de compilation
###############################################################################

%.o : %.C
		$(CC) -c $<

The_Death_Canyon_of_DOOM.o :  The_Death_Canyon_of_DOOM.c fonctions.h
fonctions.o : fonctions.c fonctions.h 

###############################################################################
# edition de lien des modules separes 
# pour la creation des programmes executables 
###############################################################################

The_Death_Canyon_of_DOOM : The_Death_Canyon_of_DOOM.o fonctions.o
		$(CC) $^ -o $@ 

###############################################################################
# nettoyage : suppression des fichiers .o et des executables
###############################################################################



clean :
	rm -rf $(EXECUTABLES) *.o


run : 
	./The_Death_Canyon_of_DOOM
