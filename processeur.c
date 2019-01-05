#include "processeur.h"

void execution(int valeur[], int indic, int *registre, long *cur, int *i, long cursorTab[]){
	int j;
	long long int resMult = 0;
	switch(indic){

		case 0 :  /*ADD*/
			/* rd = rt + rs*/
			registre[valeur[0]] = registre[valeur[1]] + registre[valeur[2]];
			registre[32] = registre[32] + 4;
			break;

		case 1 : /*ADDI*/
			/*rt = rs + immediate*/
			registre[valeur[0]] = registre[valeur[1]] + valeur[2];
			registre[32] = registre[32] + 4;
			break;

		case 2 : /*AND*/
			/*rd = rs AND rt*/
			registre[valeur[0]] = registre[valeur[1]] & valeur[2];
			registre[32] = registre[32] + 4;
			break;

		case 3 : /* BEQ */
			/*if rs == rt ==> goto offset*/
			if (registre[valeur[0]] == registre[valeur[1]]){
				*cur = cursorTab[(*i+valeur[2])-1];
				*i = (*i+valeur[2]-1);
				registre[32] = registre[32] + valeur[2]*4;
			}
			else{
				registre[32] = registre[32] + 4;
			}
			break;

		case 4 : /*BGTZ*/
			/*if rs > 0 ==> goto offset*/
			if (registre[valeur[0]] > 0){
				*cur = cursorTab[(*i+valeur[1])-1];
				*i = (*i+valeur[1]-1);
				registre[32] = registre[32] + valeur[1]*4;
			}
			else{
				registre[32] = registre[32] + 4;
			}
			break;

		case 5 : /*BLEZ*/
			/*if rs <= 0 ==> goto offset*/
			if (registre[valeur[0]] <= 0){
				*cur = cursorTab[(*i+valeur[1])-1];
				*i = (*i+valeur[1]-1);
				registre[32] = registre[32] + valeur[1]*4;
			}
			else{
				registre[32] = registre[32] + 4;
			}
			break;

		case 6 : /* BNE */
			/*if rs != rt ==> goto offset*/
			if (registre[valeur[0]] != registre[valeur[1]]){
				*cur = cursorTab[(*i+valeur[2])-1];
				*i = (*i+valeur[2]-1);
				registre[32] = registre[32] + valeur[2]*4;
			}
			else{
				registre[32] = registre[32] + 4;
			}
			break;

		case 7 : /*DIV*/
			registre[34] = registre[valeur[0]] / registre[valeur[1]]; /*LO = rs / rt*/
			registre[33] = registre[valeur[0]] % registre[valeur[1]]; /*HI = rs % rt*/
			registre[32] = registre[32] + 4;
			break;

		case 8 : /*JUMP*/
			*cur = cursorTab[(valeur[0]/4)];
			*i = valeur[0]/4;
			registre[32] = valeur[0];
			break;

		case 9 : /*JAL*/
			registre[31] = registre[32] + 4; /*On enregistre la valeur de l'adresse de retour*/
			*cur = cursorTab[(valeur[0]/4)];
			*i = valeur[0]/4;
			registre[32] = valeur[0];
			break;

		case 10 : /*JR*/
			*cur = cursorTab[(registre[valeur[0]])/4];
			*i = registre[valeur[0]/4];
			registre[32] = registre[valeur[0]];
			break;

		case 11 : /*LUI*/
			break;

		case 12 : /*LW*/
			break;

		case 13 : /*MFHI*/
			registre[valeur[0]] = registre[33];
			registre[32] = registre[32] + 4;
			break;

		case 14 : /*MFLO*/
			registre[valeur[0]] = registre[34];
			registre[32] = registre[32] + 4;
			break;

		case 15 : /*MULT*/
			resMult = registre[valeur[0]] * registre[valeur[1]];
			registre[33] = resMult >> 32; /*HI*/
			registre[34] = resMult; /*LO*/
			registre[32] = registre[32] + 4;
			break;

		case 16 : /*OR*/
			registre[valeur[0]] = registre[valeur[1]] | registre[valeur[2]];
			registre[32] = registre[32] + 4;
			break;

		case 17 : /*ROTR*/
			registre[valeur[0]] = registre[valeur[1]] >> valeur[2];
			for (j = 0; j < valeur[2]; j++) {
				/*rd = rd | (((rt >> j) & 1) << (32 - j))*/
				registre[valeur[0]] = registre[valeur[0]] | (((registre[valeur[1]] >> j) & 1) << (31 - j));
			}
			registre[32] = registre[32] + 4;
			break;

		case 18 : /*SLL*/
			registre[valeur[0]] = registre[valeur[1]] << valeur[2];
			registre[32] = registre[32] + 4;
			break;

		case 19 : /*SLT*/
			if (registre[valeur[1]] < registre[valeur[2]])
				registre[valeur[0]] = 1;
			else
				registre[valeur[0]] = 0;
			registre[32] = registre[32] + 4;
			break;

		case 20 : /*SRL*/
			registre[valeur[0]] = registre[valeur[1]] >> valeur[2];
			registre[32] = registre[32] + 4;
			break;

		case 21 : /*SUB*/
			registre[valeur[0]] = registre[valeur[1]] - registre[valeur[2]];
			registre[32] = registre[32] + 4;
			break;

		case 22 : /*SW*/
			break;

		case 23 : /*XOR*/
			registre[valeur[0]] = registre[valeur[1]] ^ registre[valeur[2]];
			registre[32] = registre[32] + 4;
			break;

		default :
			printf("Erreur processeur\n");
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
	printf(" Return Adress = %d\n", registre[31]);
	printf(" Program Counter = %d\n", registre[32]);
	printf(" HI = %d\n", registre[33]);
	printf(" LO = %d\n", registre[34]);
}
