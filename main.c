/*-------------------------------------------------------------------------------------------------
// Appel des librairies
//-------------------------------------------------------------------------------------------------*/
#include "fonctions.h"

/*-------------------------------------------------------------------------------------------------
// Appel des fonctions
//-------------------------------------------------------------------------------------------------
*/
int main(int argc, char const *argv[]){

		printf("\n%s\n","			***************************" );
		printf("%s\n",	"			****  Traducteur MIPS  ****" );
		printf("%s\n",	"			****                   ****" );
		printf("%s\n",	"			****     Jean DINET    ****" );
		printf("%s\n",	"			****         &         ****" );
		printf("%s\n",	"			**** Corentin LEPRINCE ****" );
		printf("%s\n\n","			***************************" );


	/*-------------------------------------------------------------------------------------------------
	// Declaration des variables
	//-------------------------------------------------------------------------------------------------*/

	char *robert[15] = {"ADD", "ADDI", "AND", "BNE", "ROTR", "NOP"};/*Instuction assembleur(ADD, NOP, BGTZ,...)*/
	long cur=0;
	char ligne[50]="";

	while(recupCode(argv[1], ligne, &cur) != -1){

		int valeur[4]={0};
		char operande[5]="";
		separation(ligne, operande, valeur);


		if (ligne[0] != NULL){
			ecritureFichier(argv[2], ecritureBinaire(valeur, findIndic(robert, operande)));
		}
	}
	return(0);
}
