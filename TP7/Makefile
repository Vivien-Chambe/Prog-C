ifdef test_qsortu
QSORTU = -DQSORTU
endif

ifdef test_decroissant
DECROISSANT = -DDECROISSANT
endif



CFLAGS = $(QSORTU) $(DECROISSANT)
CC = clang -g -lm  -Wall
EXECUTABLES = main

all : $(EXECUTABLES)


###############################################################################
# 			Regles de compilation
###############################################################################

%.o : %.c
		$(CC) $(CFLAGS) -c $<

main.o :  main.c qsort.h 
qsort.o : qsort.c qsort.h help.h
help.o : help.c help.h
###############################################################################
# edition de lien des modules separes 
# pour la creation des programmes executables 
###############################################################################

main : main.o qsort.o help.o
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
test_qsortu:
	test_qsortu=1 run
test_decroissant:
	test_decroissant=1 run
