#include "fonctions.h"


int recupCode(const char * fichierLecture,char *ligne,long *cur){

	FILE * f = fopen(fichierLecture,"r");

	if(f != NULL){
		fseek(f,*cur, SEEK_SET);
			if(fgets(ligne, 1000,f)!=NULL){
				* cur = ftell(f);
				fclose(f);
				return 1;
			}

			else {
				fclose(f);
				return -1;
			}
	}
	fclose(f);
	return -1;
}


int ecritureBinaire(int valeur[], int indic){
	int instBin = 0;
	switch(indic){

		case 0 : /*ADD*/
			instBin = instBin | 32;
			instBin = instBin | valeur[0]<<11;
			instBin = instBin | valeur[2]<<16;
			instBin = instBin | valeur[1]<<21;
			break;

		case 1 : /*ADDI*/
			instBin = instBin | valeur[2];
			instBin = instBin | valeur[0]<<16;
			instBin = instBin | valeur[1]<<21;
			instBin = instBin | 8<<26;
			break;

		case 2 : /*AND*/
			instBin = instBin | 36;
			instBin = instBin | valeur[0]<<11;
			instBin = instBin | valeur[2]<<16;
			instBin = instBin | valeur[1]<<21;
			break;

		case 3 : /*BEQ*/
			instBin = instBin | valeur[2];		/*offset*/
			instBin = instBin & 65535;
			instBin = instBin | valeur[1]<<16;/*rt*/
			instBin = instBin | valeur[0]<<21;/*rs*/
			instBin = instBin | 4<<26;
			break;

		case 4 : /*BGTZ*/
			instBin = instBin | valeur[1];		/*offset*/
			instBin = instBin & 65535;
			instBin = instBin | valeur[0]<<21;/*rs*/
			instBin = instBin | 7<<26;
			break;

		case 5 : /*BLEZ*/
			instBin = instBin | valeur[1];		/*offset*/
			instBin = instBin & 65535;
			instBin = instBin | valeur[0]<<21;/*rs*/
			instBin = instBin | 6<<26;
			break;

		case 6 : /*BNE*/
			instBin = instBin | valeur[2];
			instBin = instBin & 65535;
			instBin = instBin | valeur[1]<<16;
			instBin = instBin | valeur[0]<<21;
			instBin = instBin | 5<<26;
			break;

		case 7 : /*DIV*/
			instBin = instBin | 26;
			instBin = instBin | valeur[1]<<16;/*rs*/
			instBin = instBin | valeur[0]<<21;/*rt*/
			break;

		case 8 : /*JUMP*/
			instBin = instBin | valeur[0]>>2;
			instBin = instBin | 2<<26;
			break;

		case 9 : /*JAL*/
			instBin = instBin | valeur[0]>>2;
			instBin = instBin | 3<<26;
			break;

		case 10 : /*JR*/
			instBin = instBin | 8;
			instBin = instBin | valeur[0]<<21;
			break;

		case 11 : /*LUI*/
			break;

		case 12 : /*LW*/
			break;

		case 13 : /*MFHI*/
			instBin = instBin | 16;
			instBin = instBin | valeur[0]<<11;
			break;

		case 14 : /*MFLO*/
			instBin = instBin | 18;
			instBin = instBin | valeur[0]<<11;
			break;

		case 15 : /*MULT*/
			break;

		case 16 : /*OR*/
			instBin = instBin | 37;
			instBin = instBin | valeur[0]<<11;
			instBin = instBin | valeur[2]<<16;
			instBin = instBin | valeur[1]<<21;
			break;

		case 17 : /*ROTR*/
			instBin = instBin | 2;
			instBin = instBin | valeur[2]<<6;
			instBin = instBin | valeur[0]<<11;
			instBin = instBin | (valeur[1])<<16;
			instBin = instBin | 1<<21;
			break;

		case 18 : /*SLL*/
			instBin = instBin | valeur[2]<<6;
			instBin = instBin | valeur[0]<<11;
			instBin = instBin | (valeur[1])<<16;
			instBin = instBin | 1<<21;
			break;

		case 19 : /*SLT*/
			break;

		case 20 : /*SRL*/
			instBin = instBin | 2;
			instBin = instBin | valeur[2]<<6;
			instBin = instBin | valeur[0]<<11;
			instBin = instBin | (valeur[1])<<16;
			instBin = instBin | 0<<21;
			break;

		case 21 : /*SUB*/
			break;

		case 22 : /*SW*/
			break;

		case 23 : /*XOR*/
			instBin = instBin | 38;
			instBin = instBin | valeur[0]<<11;
			instBin = instBin | valeur[2]<<16;
			instBin = instBin | valeur[1]<<21;
			break;


		default :
			printf("Erreur\n");
			break;
	}

	return(instBin);
}



void separation(char *ligne, char *operande, int *valeur){
	int i=0, j=0, k=0;

		while (ligne[i] != NULL && ligne[i] != 0x23 && ligne[i] != 0x0a){

			if ((ligne[i] >= 0x41) && (ligne[i] <= 0x5a)) {
				operande[j] = ligne[i];
				j++;
				}

			else if (ligne[i] >= 0x30 && ligne[i] <= 0x39 || ligne[i] == 0x2d){
				char tab[5]="";
				int l=0;
				while (ligne[i] != 0x2c && ligne[i] != 0x0a && ligne[i] != NULL){
					tab[l] = ligne[i];
					l++;
					i++;
				}
				valeur[k] = atoi(tab);
				k++;
			}
			i++;

		}
		ligne[i]=NULL;

}

int findIndic(char *robert[],char *operande){
	int i=0;
	while ((robert[i] != NULL) && (strcmp(robert[i],operande) != 0)){
		i++;
	}
	return (i);

}

void ecritureFichier(char fichierEcriture[],int instBin){
	FILE * fic;
	int k, i;

	fic = fopen(fichierEcriture, "a");/*Ouvre le fichier a la fin ou en creer un nouveau*/
	if(fic != NULL){
		for (i = 31; i>=0; i--) {
			k = instBin >> i;
			if (k & 1)
				fprintf(fic,"1");
			else
				fprintf(fic,"0");
		}

		fprintf(fic, "\n");
		fprintf(fic, "%08X\n", instBin);
	}
	else{
		perror("Probleme ouverture du fichier en ecriture");
		exit(1);
	}

	fclose(fic);
}
