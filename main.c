/*-------------------------------------------------------------------------------------------------
// Appel des librairies
//-------------------------------------------------------------------------------------------------*/
#include "fonctions.h"

/*-------------------------------------------------------------------------------------------------
// Appel des fonctions
//-------------------------------------------------------------------------------------------------
*/
int main(int argc, char const *argv[]){

	/*-------------------------------------------------------------------------------------------------
	// Declaration des variables
	//-------------------------------------------------------------------------------------------------*/

	char *robert[15] = {"ADD", "ADDI", "AND", "BNE", "ROTR", "NOP"};/*Instuction assembleur(ADD, NOP, BGTZ,...)*/
	long cur=0;
	char ligne[15] ="";

	/*char *operande = calloc(4, sizeof(char));*/

	while(recupCode(argv[1], &ligne, &cur) != -1){
		int valeur[4]={0};
		char operande[5]="";
		separation(&ligne, &operande, &valeur);

		printf("OPERANDE: %s\n", operande);
		printf("VALEUR: %d %d %d %d\n", valeur[0], valeur[1], valeur[2], valeur[3]);

		/*
		printf("1st= %d\n", findIndic(robert, &operande));
		printf("2nd= %x\n", ecritureBinaire(&valeur, findIndic(robert, &operande)));
		*/


		ecritureFichier(argv[2], ecritureBinaire(&valeur, findIndic(robert, &operande)));

	}
	return(0);
}
