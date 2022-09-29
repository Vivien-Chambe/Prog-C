###############################################################################
# Makefile pour la compilation des programmes 
###############################################################################

#### variables ####

ifdef d
DEBUG = -DDEBUG
endif
ifdef r
RAINBOW = -DRAINBOW
endif
ifdef ap
AP = -DAUTOPILOT
endif
ifdef cn
CANYON_SIZE = -DCANYON_SIZE=$(cn)
endif
ifdef hz
HZ_RATE = -DHZ_RATE=$(hz)
endif

CFLAGS = $(DEBUG) ${RAINBOW} ${AP} $(CANYON_SIZE) $(HZ_RATE)
CC = clang -g -Wall -lncurses

EXECUTABLES = The_Death_Canyon_of_DOOM

all : $(EXECUTABLES)


###############################################################################
# 			Regles de compilation
###############################################################################

%.o : %.C
		$(CC) $(CFLAGS) -c $<

The_Death_Canyon_of_DOOM.o :  The_Death_Canyon_of_DOOM.c fonctions.h ascii_art.h
fonctions.o : fonctions.c fonctions.h 
ascii_art.o : ascii_art.c ascii_art.h 
###############################################################################
# edition de lien des modules separes 
# pour la creation des programmes executables 
###############################################################################

The_Death_Canyon_of_DOOM : The_Death_Canyon_of_DOOM.o fonctions.o ascii_art.o
		$(CC)  $(CFLAGS) $^ -o $@ 

###############################################################################
# nettoyage : suppression des fichiers .o et des executables
###############################################################################

clean :
	rm -rf $(EXECUTABLES) *.o

###############################################################################
# Lancement : Lancement de l'executable
###############################################################################


run : clean all 
	./The_Death_Canyon_of_DOOM


