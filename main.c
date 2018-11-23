/*-------------------------------------------------------------------------------------------------
// Appel des librairies
//-------------------------------------------------------------------------------------------------*/
#include "fonctions.h"

#include <stdio.h>
#include <stdlib.h>


/*-------------------------------------------------------------------------------------------------
// Declaration des variables
//-------------------------------------------------------------------------------------------------*/

int rd =11;
int rs = 10;
int rt = 11;
int im = 0;
int of = 0;

char inst[100]; /*Contient l'instruction assembleur brute*/
char fichierLecture[100]; /*nom du fichier qui contient les instructions assembleur*/
char fichierEcriture[100]; /*nom du fichier où on écrit les instructions en binaire*/
char robert[15] ;/*Instuction assembleur(ADD, NOP, BGTZ,...)*/
int instBin; /* 00000000000000*/


/*robert[] = {"ADD"};*/
instBin = 0;

/*-------------------------------------------------------------------------------------------------
// Appel des fonctions
//-------------------------------------------------------------------------------------------------

//inst[] = lecture(fichierLecture);

//separation(inst);*/
int main(){
	ecritureBinaire(rd, rt, rs, instBin);
	return(0);
}
