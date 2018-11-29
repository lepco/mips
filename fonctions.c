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
	int instBin;
	switch(indic){

		case 0 : /*ADD*/
			instBin = instBin | 32; /* 0000 0000 0000 0000 0000 0000 0010 0000 */
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
			instBin = instBin | tab[1]+32<<16;
			break;

		case 5: /*NOP*/
			break;


		default :
			printf("Erreur");
			break;
	}

	return(instBin);
}



int separation(char * ligne, char *robert[]){
	int i=0;
	int j=0;
	int l=0;
	int k=0;
	char tab[10]="";
	char tab2[10]="";
	int tab3[10];

	while (ligne[i] != NULL){

		if ((ligne[i] >= 0x41) && (ligne[i] <= 0x5a)) {
			tab[j] = ligne[i];
			j++;
			}

		else if (ligne[i] >= 0x30 && ligne[i] <= 0x39){
			while (ligne[i] != 0x2c && ligne[i] != 0x0a){
				tab2[l] = ligne[i];
				l++;
				i++;
			}
			tab3[k] = atoi(tab2);
			strcpy(tab2, "");
			k++;
			i--;
			l=0;
		}

		i++;
	}




	int indic = findIndic(robert, tab);

	return(printf("%x\n",ecritureBinaire(tab3,indic)));

}

int findIndic(char *robert[],char *tab[]){
	int i=0;
	while ((robert[i] != NULL) && (strcmp(robert[i],tab) != 0)){
		i++;
	}
	return (i);
}
