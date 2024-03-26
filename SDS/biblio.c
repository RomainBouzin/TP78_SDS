#include "biblio.h"
#include <time.h>


void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB){
	if (ptrB->nbLivres<CAPACITE_BIBLIO){
		saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
		ptrB->nbLivres++;
		return 1;
	}
	return 0;
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB){
	int i;
	if(ptrB->nbLivres==0){
		return 0;
	}
	else{
		for(i=0;i<ptrB->nbLivres;i++){
			afficherLivre( &(ptrB->etagere[i])  );
		}
		printf("Il y a %d livres dans la bibliothèque.", ptrB->nbLivres);
		return 1;
	}
}

int rechercherlivre(const T_Bibliotheque *ptrB){
	int i;
	int compt = 0;
	T_Titre titre;
	lireChaine("Titre = ",titre, K_MaxTit);
	if(ptrB->nbLivres==0){
		return 1;
	}
	else {	
		for(i=0;i<ptrB->nbLivres;i++){
			if(strcmp(ptrB->etagere[i].titre, titre) == 0){
				afficherLivre(&(ptrB->etagere[i]));
				printf("la position est %d \n", i+1);
				compt = 1;
			}
		}
	}
	if (compt == 1){
		return 0;
	}
	else {
		return 1;
	}
}

int rechercherauteur(const T_Bibliotheque *ptrB){
	int i;
	int compt = 0;
	T_Aut auteur;
	lireChaine("Auteur = ",auteur, K_MaxAut);
	if(ptrB->nbLivres==0){
		return 1;
	}
	else {	
		for(i=0;i<ptrB->nbLivres;i++){
			if(strcmp(ptrB->etagere[i].auteur, auteur) == 0){
				afficherLivre(&(ptrB->etagere[i]));
				printf("la position est %d \n", i+1);
				compt = 1;
			}
		}
	}
	if (compt == 1){
		return 0;
	}
	else {
		return 1;
	}
}

int supprimer(T_Bibliotheque *ptrB){
	int i;
	T_Aut auteur;
	T_Titre titre;
	T_livre aux;
	lireChaine("Auteur = ",auteur, K_MaxAut);
	lireChaine("Titre =", titre, K_MaxTit);
	if(ptrB->nbLivres==0){
		return 0;
	}
	else {	
		for(i=0;i<ptrB->nbLivres;i++){
			if(strcmp(ptrB->etagere[i].auteur, auteur) == 0 && strcmp(ptrB->etagere[i].titre, titre) == 0){
				afficherLivre(&(ptrB->etagere[i]));
				aux = ptrB->etagere[i];
				ptrB->etagere[i] = ptrB->etagere[ptrB->nbLivres-1];
				ptrB->etagere[ptrB->nbLivres-1] = aux;
				ptrB->nbLivres --;
				return 1;
			}
		}
	}
	return 1;
}

int emprunterLivres(T_Bibliotheque *ptrB, char *code, char *emp){
	int i;
	time_t secondes;
	if (ptrB -> nbLivres > 0){
		for (i=0; i < ptrB -> nbLivres; i++){
			if (strcmp(ptrB -> etagere[i].code, code) == 0){
				if (strcmp(ptrB->etagere[i].emprunteur.nomemprunteur, "") == 0){
					strcpy(ptrB->etagere[i].emprunteur.nomemprunteur, emp);
					ptrB->etagere[i].emprunteur.quand=(double)time(&secondes);
					return 1;
				}
				else
					return 0;
			}		
		}	
	}
	return 0;
}

int rendre(T_Bibliotheque *ptrB, char *code){
    int i;
    if(ptrB->nbLivres>0){
        for(i=0;i<ptrB->nbLivres;i++){
            if(strcmp(ptrB->etagere[i].code,code)==0){
                if(strcmp(ptrB->etagere[i].emprunteur.nomemprunteur,"")!=0){
                    strcpy(ptrB->etagere[i].emprunteur.nomemprunteur,"");
					ptrB->etagere[i].emprunteur.quand=0;
                    return 1;
				}
            }
        }
    }
    return 0;
}
    
int trierTitre(T_Bibliotheque *ptrB){
    int i,j;
    T_livre aux;

	for(j=1;j<=(ptrB->nbLivres);j++){
	    for(i=0;i<(ptrB->nbLivres)-1;i++){
	        if (strcmp(ptrB->etagere[i].titre,ptrB->etagere[i+1].titre)>0 ){
	                aux=ptrB->etagere[i];
	                ptrB->etagere[i]=ptrB->etagere[i+1];
	                ptrB->etagere[i+1]=aux;
	        }
	    }
	} 
   	return 1;
}

int trierAuteur(T_Bibliotheque *ptrB){
    int i,j;
    T_livre aux;
	for(j=1;j<=(ptrB->nbLivres);j++){
     	for(i=0;i<(ptrB->nbLivres)-1;i++){
        	if (strcmp(ptrB->etagere[i].auteur,ptrB->etagere[i+1].auteur)>0 ){
                aux=ptrB->etagere[i];
                ptrB->etagere[i]=ptrB->etagere[i+1];
                ptrB->etagere[i+1]=aux;
            }
     	} 
	} 
   	return 1;
}

int trierDate(T_Bibliotheque *ptrB){
    int i,j;
    T_livre aux;
    for(j=1;j<=(ptrB->nbLivres);j++){
        for(i=0;i<(ptrB->nbLivres)-1;i++){
            if (ptrB->etagere[i].annee>ptrB->etagere[i+1].annee){
                aux=ptrB->etagere[i];
                ptrB->etagere[i]=ptrB->etagere[i+1];
                ptrB->etagere[i+1]=aux;
            }
                
        }
    }
    return 1;
}

int dispo(T_Bibliotheque *ptrB, char *code){
	int i;
	if (ptrB -> nbLivres > 0){
		for (i=0; i < ptrB -> nbLivres; i++){
			if (strcmp(ptrB -> etagere[i].code, code) == 0){
				if (strcmp(ptrB->etagere[i].emprunteur.nomemprunteur, "") == 0)
					return 1;
				else
					return 0;
			}		
		}	
	}
	return 1;
}

int dispolivres(T_Bibliotheque *ptrB){
	int compteur =0;
	if(ptrB->nbLivres==0)
		return 0;
	printf("Les livres disponibles sont :\n");
	printf("<----------------------------------->\n");
	for(int i=0; i<ptrB -> nbLivres; i++){
		if (strcmp(ptrB->etagere[i].emprunteur.nomemprunteur, "") == 0){
			compteur++;
			afficherLivre(&(ptrB->etagere[i]));
		}
	}
	printf("\n Il y a %d livres disponibles", compteur);
	return 1;
}

int listerRetard(T_Bibliotheque *ptrB){
    time_t secondes;
    int i;
    time_t quand2=(double)time(&secondes);
    for(i=0;i<(ptrB->nbLivres);i++){
        if(quand2 - ptrB->etagere[i].emprunteur.quand >= (24*3600))
            afficherLivre(&(ptrB->etagere[i]));
    }
    return 1;
}