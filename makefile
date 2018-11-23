all : fonctions.o main.o
	gcc main.o fonctions.o -o main 
	
fontions.o : fonctions.c
	gcc -c fonctions.c -Wall -ansi -pedantic -o fonctions.o
	
main.o : main.c
	gcc -c main.c -Wall -ansi -pedantic -o main.o