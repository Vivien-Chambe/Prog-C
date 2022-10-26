ifdef tests
TESTS = -DTESTS=$(tests)
endif

CFLAGS = $(TESTS)
CC = clang -g -Wall
EXECUTABLES = sortings

all : $(EXECUTABLES)

###############################################################################
# 			Regles de compilation
###############################################################################

fonctions.o: fonctions.c fonctions.h
	$(CC) -c $<

###############################################################################
# edition de lien des modules separes 
# pour la creation des programmes executables 
###############################################################################

sortings : fonctions.o
		$(CC) $(CFLAGS) -o $@  $^ 

###############################################################################
# nettoyage : suppression des fichiers .o et des executables
###############################################################################

clean :
	rm -rf $(EXECUTABLES) *.o

###############################################################################
# Lancement : Lancement de l'executable
###############################################################################


run : clean all 
	./sortings
