#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 20 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);	
int rechercherlivre(const T_Bibliotheque *ptrB);
int rechercherauteur(const T_Bibliotheque *ptrB);
int supprimer(T_Bibliotheque *ptrB);
void sauvegarde(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);
int emprunterLivres(T_Bibliotheque *ptrB, char *code, char *emp);
int rendre(T_Bibliotheque *ptrB, char *code);
int trierTitre(T_Bibliotheque *ptrB);
int trierAuteur(T_Bibliotheque *ptrB);
int trierDate(T_Bibliotheque *ptrB);
int dispo(T_Bibliotheque *ptrB, char *code);
int dispolivres(T_Bibliotheque *ptrB);
int listerRetard(T_Bibliotheque *ptrB);


#endif