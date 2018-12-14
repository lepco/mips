#include "fonctions.h"


int recupCode(char * fichierLecture,char *ligne,long *cur){

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


int ecritureBinaire(int tab[], int indic){
	int instBin = 0;
	switch(indic){

		case 0 : /*ADD*/
			instBin = instBin | 32;
			instBin = instBin | tab[0]<<11;
			instBin = instBin | tab[2]<<16;
			instBin = instBin | tab[1]<<21;
			break;

		case 1 : /*ADDI*/
			instBin = instBin | tab[2];
			instBin = instBin | tab[0]<<16;
			instBin = instBin | tab[1]<<21;
			instBin = instBin | 8<<26;
			break;

		case 2 : /*AND*/
			instBin = instBin | 36;
			instBin = instBin | tab[0]<<11;
			instBin = instBin | tab[2]<<16;
			instBin = instBin | tab[1]<<21;
			break;

		case 3 : /*BNE*/
			instBin = instBin | tab[2];
			instBin = instBin | tab[1]<<16;
			instBin = instBin | tab[0]<<21;
			instBin = instBin | 5<<26;
			break;

		case 4: /*ROTR*/
			instBin = instBin | 2;
			instBin = instBin | tab[2]<<6;
			instBin = instBin | tab[0]<<11;
			instBin = instBin | (tab[1])<<16;
			instBin = instBin | 1<<21;
			break;

		case 5: /*NOP*/
			break;


		default :
			printf("Erreur\n");
			break;
	}

	return(instBin);
}



void separation(char *ligne, char *operande, int *valeur){
	int i=0, j=0, k=0;

	while (ligne[i] != NULL){

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
		fprintf(fic, "%02X\n", instBin);
	}
	else{
		perror("Probleme ouverture du fichier en ecriture");
		exit(1);
	}

	fclose(fic);
}
