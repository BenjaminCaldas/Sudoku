/**
* \file Solveur.cpp
* \author Benjamin Caldas
* \brief Le fichier source de la classe CSolveur.
*/
#include "Solveur.h"

CSolveur::CSolveur(void) {
	pGRIGrille = NULL;
	luiSLVTempsResolution = luiSLVNbNumerosTestes = 0;
}

CSolveur::CSolveur(CSolveur & SLVSolveur) {
	pGRIGrille = SLVSolveur.pGRIGrille;
	luiSLVTempsResolution = SLVSolveur.luiSLVTempsResolution;
	luiSLVNbNumerosTestes = SLVSolveur.luiSLVNbNumerosTestes;
}

CSolveur::CSolveur(CGrille * GRIUneGrille) {
	pGRIGrille = GRIUneGrille;
	luiSLVTempsResolution = luiSLVNbNumerosTestes = 0;
}

bool CSolveur::SLVEstValide(unsigned int uiPosition) {
	unsigned int uiTailleGrille = pGRIGrille->GRILireTaille();

	if (uiPosition < 0 || uiPosition > uiTailleGrille * uiTailleGrille) {
		// Lever une exception (position hors grille)
		throw CExcept(EXC_IDX_ERR);
	}

	// Si l'on se trouve sur la derniere case, la resolution est terminee
	if (uiPosition == uiTailleGrille * uiTailleGrille)
		return true;

	// On prend une ligne et une colonne
	unsigned int uiLigne = uiPosition / 9;
	unsigned int uiColonne = uiPosition % 9;

	// Si une valeur est deja presente, on passe a la case suivante
	if (pGRIGrille->GRILireValeur(uiLigne, uiColonne) != 0)
		return SLVEstValide(uiPosition + 1);

	unsigned int uiNumero;
	CControleurGrille CGRControleur(pGRIGrille);
	// On teste les valeurs de 1 à 9 sur la case[uiLigne][uiColonne]
	// Jusqu'a trouver la bonne valeur
	for (uiNumero = 1; uiNumero <= uiTailleGrille; ++uiNumero) {
		if (CGRControleur.CGRVerifierLigne(uiNumero, uiLigne) && CGRControleur.CGRVerifierColonne(uiNumero, uiColonne) && CGRControleur.CGRVerifierZone(uiNumero, pGRIGrille->GRIRecupererZone(uiLigne, uiColonne))) {
			// Si toute les regles du Sudoku sont verifiees, on modifie la valeur
			pGRIGrille->GRIModifierValeur(uiLigne, uiColonne, uiNumero);
			++luiSLVNbNumerosTestes;
			pGRIGrille->GRIAfficherGrille();
			// Recursivite afin de couvrir toute la grille
			if (SLVEstValide(uiPosition + 1))
				return true;
		}
	}
	// Si la valeur ne convient pas, on remet la case a 0
	pGRIGrille->GRIModifierValeur(uiLigne, uiColonne, 0);
	++luiSLVNbNumerosTestes;
	// Et on retourne faux
	return false;
}

void CSolveur::SLVResoudre(void) {
	// Timer avant resolution
	time_t tDebut;
	// Timer apres resolution
	time_t tFin;
	// Timer de reference
	struct tm tmReference = {0};
	long unsigned int luiDebut;
	long unsigned int luiFin;

	tmReference.tm_hour = 0;   tmReference.tm_min = 0; tmReference.tm_sec = 0;
	tmReference.tm_year = 100; tmReference.tm_mon = 0; tmReference.tm_mday = 1;
	// Difference entre le timer de reference et celui d'avant resolution
	time(&tDebut);
	luiDebut = difftime(tDebut ,mktime(&tmReference));

	SLVEstValide(0);
	// Difference entre le timer de reference et celui d'apres resolution
	time(&tFin);
	luiFin = difftime(tFin ,mktime(&tmReference));
	// Difference entre la fin et le debut de resolution
	luiSLVTempsResolution = luiFin - luiDebut;
}

void CSolveur::SLVAfficherStatistiques(void) {
	cout << endl << "La grille de Sudoku a ete resolue en " << luiSLVTempsResolution << " secondes." << endl;
	cout << luiSLVNbNumerosTestes << " numeros ont ete testes." << endl;
}