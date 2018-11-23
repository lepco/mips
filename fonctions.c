#include "fonctions.h"

void lecture(fichierLecture);

void separation(instruction);

int ecritureBinaire(int rd, int rt, int rs, int instBin){
	int i = 0;
	switch(i){
		
		case 0 : 
			instBin = instBin | 32; /* 0000 0000 0000 0000 0000 0000 0010 0000 */
			instBin = instBin | rd<<11;
			instBin = instBin | rt<<16;
			instBin = instBin | rs<<21;
			break;
		default :
			printf("Erreur");
			break;
	}
	
	printf("%d\n", instBin);
	
	return(0);
}

void ecritureFichier(fichierEcriture, instBin);