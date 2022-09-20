###############################################################################
# Makefile pour la compilation des programmes 
###############################################################################

#### options de compilation ####
COMPIL_OPTIONS = -g 
CFLAG =  -c

#### variables ####
CC = clang 
BIN = clang

EXECUTABLES = The_Death

all : $(EXECUTABLES)



###############################################################################
# compilation separee des packages (modules)
###############################################################################

The_Death_Canyon_of_DOOM.o :  The_Death_Canyon_of_DOOM.c fonctions.h

fonctions.o : fonctions.c fonctions.h


%.o: %.c
	$(CC) $(CFLAG) $(COMPIL_OPTIONS) $<


###############################################################################
# edition de lien des modules separes 
# pour la creation des programmes executables 
###############################################################################

The_Death : The_Death_Canyon_of_DOOM.o fonctions.o


%: %.o
	$(BIN) $(COMPIL_OPTIONS) $^ -o $@

###############################################################################
# nettoyage : suppression des fichiers .o et des executables
###############################################################################

clean :
	rm -rf *.o $(EXECUTABLES)
