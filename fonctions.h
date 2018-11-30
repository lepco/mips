#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recupCode(char * fichierLecture,char *ligne,long *cur);

int lecture(char fichierLecture[100], char *robert[]);

int findIndic(char *robert[],char *tab[]);

int separation(char * ligne, char *robert[], char fichierEcriture[100]);

int ecritureBinaire(int tab[], int indic);

void ecritureFichier(char fichierEcriture[],int instBin);
