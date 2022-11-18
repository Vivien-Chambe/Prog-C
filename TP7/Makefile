ifdef test
    TEST = -DTEST=$(test)
endif

CFLAGS = $(TEST)
CC = clang -g  -lm  -Wall 
EXECUTABLES = main

all : $(EXECUTABLES)


###############################################################################
# 			Regles de compilation
###############################################################################

%.o : %.c
		$(CC) $(CFLAGS) -c $<

main.o :  main.c qsort.h 
qsort.o : qsort.c qsort.h help.h
radix.o : radixsort.c radixsort.h help.h
help.o : help.c help.h
###############################################################################
# edition de lien des modules separes 
# pour la creation des programmes executables 
###############################################################################

main : main.o qsort.o radixsort.o help.o
		$(CC)  $(CFLAGS) $^ -o $@ 

###############################################################################
# nettoyage : suppression des fichiers .o et des executables
###############################################################################

clean :
	rm -rf $(EXECUTABLES) *.o

###############################################################################
# Lancement : Lancement de l'executable
###############################################################################

run :clean all
	./main

###############################################################################

