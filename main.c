/*-------------------------------------------------------------------------------------------------
// Appel des librairies
//-------------------------------------------------------------------------------------------------*/
#include "fonctions.h"

#include <stdio.h>
#include <stdlib.h>


/*-------------------------------------------------------------------------------------------------
// Declaration des variables
//-------------------------------------------------------------------------------------------------*/

int un;
int deux;
int trois;

char inst[100]; /*Contient l'instruction assembleur brute*/
char fichierLecture[100]; /*nom du fichier qui contient les instructions assembleur*/
char fichierEcriture[100]; /*nom du fichier o� on �crit les instructions en binaire*/
char *robert[] = {"ADD", "ADDI", "AND", "BNE", "ROTR", "NOP"};
int indic; /*indice dans le tableau robert correspondant à la commande EX:Commande=AND==>Indic=2*/
/*int instBin; /* 00000000000000*/



/*-------------------------------------------------------------------------------------------------
// Appel des fonctions
//-------------------------------------------------------------------------------------------------

//inst[] = lecture(fichierLecture);

//separation(inst);*/
int main(){
	printf("%x\n",ecritureBinaire(un, deux, trois, indic));
	int instBin = ecritureBinaire(un, deux, trois, indic);
	return(0);
}
