#include <stdio.h>
#include <stdlib.h>

int recupCode(char * fichierLecture,char *ligne,long *cur);

int lecture(char fichierLecture[100], char *robert[]);

int findIndic(char *robert[],char *operande);

void separation(char * ligne, char *operande, int *valeur);

int ecritureBinaire(int tab[], int indic);

void ecritureFichier(char fichierEcriture[],int instBin);
