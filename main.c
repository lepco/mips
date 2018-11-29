/*-------------------------------------------------------------------------------------------------
// Appel des librairies
//-------------------------------------------------------------------------------------------------*/
#include "fonctions.h"

#include <stdio.h>
#include <stdlib.h>


/*-------------------------------------------------------------------------------------------------
// Declaration des variables
//-------------------------------------------------------------------------------------------------*/


char fichierLecture[100]="aLire.txt"; /*nom du fichier qui contient les instructions assembleur*/
char fichierEcriture[100]; /*nom du fichier o� on �crit les instructions en binaire*/
char *robert[15] = {"ADD", "ADDI", "AND", "BNE", "ROTR", "NOP"};;/*Instuction assembleur(ADD, NOP, BGTZ,...)*/
long cur=0;
char ligne[20] ="";

/*-------------------------------------------------------------------------------------------------
// Appel des fonctions
//-------------------------------------------------------------------------------------------------
*/
int main(){
	while(recupCode(fichierLecture, ligne, &cur) != -1){
		printf("%d\n",separation(ligne, robert));
	}
	return(0);
}
