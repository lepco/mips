#include <stdio.h>
#include <stdlib.h>

int recupCode(const char * fichierLecture,char *ligne,long *cur);

int findIndic(char *robert[],char *operande);

void separation(char * ligne, char *operande, int *valeur);

int ecritureBinaire(int valeur[], int indic);

void registerReplacement(char *ligne, char *dicoRegistre);

void ecritureFichier(char fichierEcriture[],int instBin);
