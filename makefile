all : fonctions.o processeur.o main.o
	gcc main.o fonctions.o processeur.o -o emui-mips 

fontions.o : fonctions.c
	gcc -c fonctions.c -Wall -ansi -pedantic -o fonctions.o

processeur.o : processeur.c
	gcc -c processeur.c -Wall -ansi -pedantic -o processeur.o

main.o : main.c
	gcc -c main.c -Wall -ansi -pedantic -o main.o
