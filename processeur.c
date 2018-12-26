#include "processeur.h"

void execution(int tab[], int indic, int *registre){

	switch(indic){

		case 0 :  /*ADD*/
			/* rd = rt + rs*/
			registre[tab[0]] = registre[tab[1]] + registre[tab[2]];
			registre[32]++;
			break;

		case 1 : /*ADDI*/
			/*rt = rs + immediate*/
			registre[tab[0]] = registre[tab[1]] + tab[2];
			registre[32]++;
			break;

		case 2 : /*ADDI*/
			/*rd = rs AND rt*/
			registre[tab[0]] = registre[tab[1]] & tab[2];
			registre[32]++;
			break;

		case 4 : /*ROTR*/
			/*rd = rt >> sa*/
			registre[tab[0]] = registre[tab[1]] >> tab[2];
			registre[32]++;
			break;

		default :
			printf("Erreur\n");
			break;
	}

}

void affichage(char * ligne, int *registre){
	int i;
	printf("\n");
	printf("---------------------------\n");;
	printf("	%s\n", ligne);

	for (i = 0; i < 29; i++) {
		printf(" Registre %d = %d\n", i, registre[i]);
	}

	printf(" Stack Pointer = %d\n", registre[29]);

	for (i = 30; i < 32; i++) {
		printf(" Registre %d = %d\n", i, registre[i]);
	}

	printf(" Program Counter = %d\n", registre[32]);
}
