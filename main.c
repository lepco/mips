/*-------------------------------------------------------------------------------------------------
// Appel des librairies
//-------------------------------------------------------------------------------------------------*/
#include "fonctions.h"
#include "processeur.h"

/*-------------------------------------------------------------------------------------------------
// Appel des fonctions
//-------------------------------------------------------------------------------------------------
*/
int main(int argc, char const *argv[]){

		printf("\n%s\n","			***************************" );
		printf("%s\n",	"			****  Traducteur MIPS  ****" );
		printf("%s\n",	"			****                   ****" );
		printf("%s\n",	"			****     Jean DINET    ****" );
		printf("%s\n",	"			****         &         ****" );
		printf("%s\n",	"			**** Corentin LEPRINCE ****" );
		printf("%s\n\n","			***************************" );


	/*-------------------------------------------------------------------------------------------------
	// Declaration des variables
	//-------------------------------------------------------------------------------------------------*/

	char *robert[15] = {"ADD", "ADDI", "AND", "BNE", "ROTR", "NOP"};/*Instuction assembleur(ADD, NOP, BGTZ,...)*/
	long cur=0;
	char ligne[50]="";
	int registre[34] = {0};
	char wait;
	long cursorTab[30] = {0};

	/*Test si on lance le programme en lecture de fichier ou pas*/
	/*Premier cas : instructions rentrés à la main*/
	if (argv[1] == NULL) {
		int keepGoing = 0;
		printf("Lancement en mode manuel\n");
		do {
			int valeur[4]={0};
			char operande[5]="";
			int i=0; /*Le i ici est inutile, il sert juste à pouvoir executer la fonction "execution"*/

			/*Demande d'une nouvelle instruction*/
			printf("Entrez l'instruction (sans espaces): ");
			scanf("%s", ligne);

			/*Traitement de l'instruction*/
			separation(ligne, operande, valeur);
			if (ligne[0] != NULL){
				ecritureFichier(argv[2], ecritureBinaire(valeur, findIndic(robert, operande)));
				execution(valeur, findIndic(robert, operande),  registre, &cur, i, cursorTab);
				affichage(ligne, registre);
			}

			/*Demande de sortie*/
			printf("\nVoulez-vous continuer (1 : oui, 0 : non) ? ");
			scanf("%d", &keepGoing);

		} while(keepGoing == 1);

	}
	/*Deuxième cas : lecture d'un fichier*/
	else{
		printf("Lancement en mode lecture de fichier\n");
		int i=1;
		while(recupCode(argv[1], ligne, &cur) != -1){

			int valeur[4]={0};
			char operande[5]="";

			cursorTab[i] = cur;
			separation(ligne, operande, valeur);


			if (ligne[0] != NULL){
				ecritureFichier(argv[2], ecritureBinaire(valeur, findIndic(robert, operande)));
			}
			i++;
		}

		cur=0;
		i=1;
		while(recupCode(argv[1], ligne, &cur) != -1){

			int valeur[4]={0};
			char operande[5]="";

			separation(ligne, operande, valeur);

			if (ligne[0] != NULL){
				execution(valeur, findIndic(robert, operande),  registre, &cur, &i, cursorTab);
				affichage(ligne, registre);
				scanf("%c", &wait);
			}
			i++;
		}
	}
	printf("****** Sortie de l'émulateur ******\n");
	return(0);
}
