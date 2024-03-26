#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
	lireChaine("AUTEUR :", (ptrL->auteur ), K_MaxAut);
	lireChaine("CODE :", (ptrL->code ), K_MaxCode);
	lireChaine("EDITEUR :", (ptrL->editeur ), K_MaxEdit);
	printf("ANNEE : ");
	scanf("%d",&ptrL->annee);
	getchar();
	strcpy(ptrL->emprunteur.nomemprunteur,"");

}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf("\n");
afficherChaine("CODE :", (ptrL->code));
printf("\n");
afficherChaine("EDITEUR :", (ptrL->editeur));
printf("\n");
printf("ANNEE : %d",ptrL->annee);
printf("\n");
afficherChaine("EMPRUNTEUR :", (ptrL->emprunteur.nomemprunteur ));
printf("\n");
printf("<----------------------------------->");
printf("\n");
}

