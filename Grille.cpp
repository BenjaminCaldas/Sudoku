/**
* \file Grille.cpp
* \author Benjamin Caldas
* \brief Le fichier source de la classe CGrille.
*/
#include "Grille.h"

CGrille::CGrille(void) {
	uiGRITaille = 0;
	ppuiGRIGrille = NULL;
}

CGrille::CGrille(CGrille & GRIUnSudoku) {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	uiGRITaille = GRIUnSudoku.uiGRITaille;
	ppuiGRIGrille = new unsigned int * [uiGRITaille];
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle) {
		ppuiGRIGrille[uiBoucle] = new unsigned int [uiGRITaille];
	}
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2) {
			ppuiGRIGrille[uiBoucle][uiBoucle2] = GRIUnSudoku.GRILireValeur(uiBoucle, uiBoucle2);
		}
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2)
			if ((ppuiGRIGrille[uiBoucle][uiBoucle2] > 9) || (ppuiGRIGrille[uiBoucle][uiBoucle2] < 1)) {
				ppuiGRIGrille[uiBoucle][uiBoucle2] = 0;
			}
}

CGrille::CGrille(unsigned int ** ppuiUneGrille, unsigned int uiUneTaille) {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	uiGRITaille = uiUneTaille;
	ppuiGRIGrille = new unsigned int * [uiGRITaille];
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle) {
		ppuiGRIGrille[uiBoucle] = new unsigned int [uiGRITaille];
	}
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2) {
			ppuiGRIGrille[uiBoucle][uiBoucle2] = ppuiUneGrille[uiBoucle][uiBoucle2];
		}
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2)
			if ((ppuiGRIGrille[uiBoucle][uiBoucle2] > 9) || (ppuiGRIGrille[uiBoucle][uiBoucle2] < 1)) {
				ppuiGRIGrille[uiBoucle][uiBoucle2] = 0;
			}
}

CGrille::~CGrille(void) {
	if (ppuiGRIGrille != NULL) {
		unsigned int uiBoucle;

		for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
			delete [] ppuiGRIGrille[uiBoucle];
		delete [] ppuiGRIGrille;
	}
}

unsigned int CGrille::GRILireTaille() {
	return uiGRITaille;
}

unsigned int CGrille::GRILireValeur(unsigned int uiLigne, unsigned int uiColonne) {
	if ((uiLigne < 0 || uiLigne >= uiGRITaille) || (uiColonne < 0 || uiColonne >= uiGRITaille)) {
		// Lever exception (index incorrect)
		throw CExcept(EXC_IDX_ERR);
	}
	return ppuiGRIGrille[uiLigne][uiColonne];
}

void CGrille::GRIModifierValeur(unsigned int uiLigne, unsigned int uiColonne, unsigned int uiValeur) {
	if ((uiLigne < 0 || uiLigne >= uiGRITaille) || (uiColonne < 0 || uiColonne >= uiGRITaille)) {
		// Lever exception (index incorrect)
		throw CExcept(EXC_IDX_ERR);
	}
	if (uiValeur < 0 || uiValeur > uiGRITaille) {
		// Lever exception (Valeur incorrecte)
		throw CExcept(EXC_VAL_INC);
	}
	ppuiGRIGrille[uiLigne][uiColonne] = uiValeur;
}

unsigned int CGrille::GRIRecupererZone(unsigned int uiLigne, unsigned int uiColonne) {
	if ((uiLigne < 0 || uiLigne >= uiGRITaille) || (uiColonne < 0 || uiColonne >= uiGRITaille)) {
		// Lever exception (index incorrect)
		throw CExcept(EXC_IDX_ERR);
	}
	if (uiLigne < 3) {
		if (uiColonne < 3)
			return 1;
		else {
			if (uiColonne < 6)
				return 2;
			else
				return 3;
		}
	}
	else {
		if (uiLigne < 6) {
			if (uiColonne < 3)
				return 4;
			else {
				if (uiColonne < 6)
					return 5;
				else
					return 6;
			}
		}
		else {
			if (uiColonne < 3)
				return 7;
			else {
				if (uiColonne < 6)
					return 8;
				else
					return 9;
			}
		}
	}
}

void CGrille::GRIAfficherGrille() {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	cout << endl;
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle) {
		if (uiBoucle == 3 || uiBoucle == 6)
			cout << "----------------------------" << endl;
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2) {
			cout << ppuiGRIGrille[uiBoucle][uiBoucle2];
			if (uiBoucle2 != uiGRITaille - 1)
				cout << " ";
			if (uiBoucle2 == 2 || uiBoucle2 == 5)
				cout << "|";
			if (uiBoucle2 != uiGRITaille - 1)
				cout << " ";
		}
		if (uiBoucle != uiGRITaille - 1)
			cout << endl;
	}
	cout << endl;
}
