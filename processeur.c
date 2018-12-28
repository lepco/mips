#include "processeur.h"

void execution(int valeur[], int indic, int *registre, long *cur, int *i, long cursorTab[]){

	switch(indic){

		case 0 :  /*ADD*/
			/* rd = rt + rs*/
			registre[valeur[0]] = registre[valeur[1]] + registre[valeur[2]];
			registre[32]++;
			break;

		case 1 : /*ADDI*/
			/*rt = rs + immediate*/
			registre[valeur[0]] = registre[valeur[1]] + valeur[2];
			registre[32]++;
			break;

		case 2 : /*ADDI*/
			/*rd = rs AND rt*/
			registre[valeur[0]] = registre[valeur[1]] & valeur[2];
			registre[32]++;
			break;

		case 3 : /* BNE */
			/*if rs != rt ==> goto offset*/
			if (registre[valeur[0]] != registre[valeur[1]]){
				*cur = cursorTab[(*i+valeur[2])-1];
				*i = (*i+valeur[2]-1);
			}
			break;

		case 4 : /*ROTR*/
			/*rd = rt >> sa*/
			registre[valeur[0]] = registre[valeur[1]] >> valeur[2];
			registre[32]++;
			break;

		case 5: /*NOP*/
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
