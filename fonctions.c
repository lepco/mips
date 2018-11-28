#include "fonctions.h"

void lecture(fichierLecture);

void separation(char inst[]);

int ecritureBinaire(int un, int deux, int trois, int indic){
	int instBin;
	switch(indic){

		case 0 : /*ADD*/
			instBin = instBin | 32; /* 0000 0000 0000 0000 0000 0000 0010 0000 */
			instBin = instBin | un<<11;
			instBin = instBin | trois<<16;
			instBin = instBin | deux<<21;
			break;

		case 1 : /*ADDI*/
			instBin = instBin | trois;
			instBin = instBin | un<<16;
			instBin = instBin | deux<<21;
			instBin = instBin | 8<<26;
			break;

		case 2 : /*AND*/
			instBin = instBin | 36;
			instBin = instBin | un<<11;
			instBin = instBin | trois<<16;
			instBin = instBin | deux<<21;
			break;

		case 3 : /*BNE*/
			instBin = instBin | trois;
			instBin = instBin | deux<<16;
			instBin = instBin | un<<21;
			instBin = instBin | 5<<26;
			break;

		case 4: /*ROTR*/
			instBin = instBin | 2;
			instBin = instBin | trois<<6;
			instBin = instBin | un<<11;
			instBin = instBin | deux+32<<16;
			break;

		case 5: /*NOP*/
			break;

/*
case 6:
	instBin = instBin | trois;
	instBin = instBin | deux<<16;
	instBin = instBin | un<<21;
	instBin = instBin | 5<<26;
	break;

case 7:
	instBin = instBin | trois;
	instBin = instBin | deux<<16;
	instBin = instBin | un<<21;
	instBin = instBin | 5<<26;
	break;

case 8:
	instBin = instBin | trois;
	instBin = instBin | deux<<16;
	instBin = instBin | un<<21;
	instBin = instBin | 5<<26;
	break;

case 9:
	instBin = instBin | trois;
	instBin = instBin | deux<<16;
	instBin = instBin | un<<21;
	instBin = instBin | 5<<26;
	break;

case 10:
	instBin = instBin | trois;
	instBin = instBin | deux<<16;
	instBin = instBin | un<<21;
	instBin = instBin | 5<<26;
	break;

	*/


		default :
			printf("Erreur");
			break;
	}

	return(instBin);
}

void ecritureFichier(fichierEcriture, instBin);
