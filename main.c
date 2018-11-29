/*-------------------------------------------------------------------------------------------------
// Appel des librairies
//-------------------------------------------------------------------------------------------------*/
#include "fonctions.h"

#include <stdio.h>
#include <stdlib.h>


/*-------------------------------------------------------------------------------------------------
// Declaration des variables
//-------------------------------------------------------------------------------------------------*/

int rd =11;
int rs = 10;
int rt = 11;
int im = 0;
int of = 0;


char fichierLecture[100]="aLire.txt"; /*nom du fichier qui contient les instructions assembleur*/
char fichierEcriture[100]; /*nom du fichier o� on �crit les instructions en binaire*/
char *robert[15] = {"ADD", "ADDI", "AND", "BNE", "ROTR", "NOP"};;/*Instuction assembleur(ADD, NOP, BGTZ,...)*/
int instBin; /* 00000000000000*/
long cur=0;
char ligne[20] ="";



/*robert[] = {"ADD"};*/
instBin = 0;

/*-------------------------------------------------------------------------------------------------
// Appel des fonctions
//-------------------------------------------------------------------------------------------------

//inst[] = lecture(fichierLecture);

//separation(inst);*/
int main(){
/*ecritureBinaire(rd, rt, rs, instBin);
	lecture("aLire.txt");*/
	while(recupCode(fichierLecture, ligne, &cur) != -1){
		printf("%d\n",separation(ligne, robert));
	}
	return(0);
}
