ifdef test_qsortu
QSORTU = -DQSORTU
endif

ifdef test_decroissant
DECROISSANT = -DDECROISSANT
endif

ifdef test_qsort_uniforme
QSORT_UNIFORME = -DQSORT_UNIFORME
endif



CFLAGS = $(QSORTU) $(DECROISSANT) $(QSORT_UNIFORME)
CC = clang -g -lm  -Wall
EXECUTABLES = main

all : $(EXECUTABLES)


###############################################################################
# 			Regles de compilation
###############################################################################

%.o : %.c
		$(CC) -c $<

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

test_qsort_uniforme :
	make run test_qsort_uniforme=1