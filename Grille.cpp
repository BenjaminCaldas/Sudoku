#include <iostream>
#include <stdlib.h>

#include "Grille.h"

using namespace std;

CGrille::CGrille(void) {
	uiGRITaille = 0;
	ppuiGRIGrille = NULL;
}

CGrille::CGrille(CGrille & GRIUnSudoku) {
	unsigned int uiBoucle ,uiBoucle2;

	uiGRITaille = GRIUnSudoku.uiGRITaille;
	ppuiGRIGrille = new unsigned int * [uiGRITaille];
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle) {
		ppuiGRIGrille[uiBoucle] = new unsigned int [uiGRITaille];
	}
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2) {
			ppuiGRIGrille[uiBoucle][uiBoucle2] = GRIUnSudoku.ppuiGRIGrille[uiBoucle][uiBoucle2];
		}
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2)
			if ((ppuiGRIGrille[uiBoucle][uiBoucle2] > 9) || (ppuiGRIGrille[uiBoucle][uiBoucle2] < 1)) {
				ppuiGRIGrille[uiBoucle][uiBoucle2] = 0;
			}
}

CGrille::CGrille(unsigned int ** uiUneGrille, unsigned int uiUneTaille) {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	uiGRITaille = uiUneTaille;
	ppuiGRIGrille = new unsigned int * [uiGRITaille];
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle) {
		ppuiGRIGrille[uiBoucle] = new unsigned int [uiGRITaille];
	}
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2) {
			ppuiGRIGrille[uiBoucle][uiBoucle2] = uiUneGrille[uiBoucle][uiBoucle2];
		}
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2)
			if ((ppuiGRIGrille[uiBoucle][uiBoucle2] > 9) || (ppuiGRIGrille[uiBoucle][uiBoucle2] < 1)) {
				ppuiGRIGrille[uiBoucle][uiBoucle2] = 0;
			}
}

CGrille::~CGrille(void) {
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle) {
		delete [] ppuiGRIGrille[uiBoucle];
		
	}
	delete [] ppuiGRIGrille;
	
}

unsigned int CGrille::GRILireTaille() {
	return uiGRITaille;
}

unsigned int CGrille::GRILireValeur(unsigned int uiLigne, unsigned int uiColonne) {
	return ppuiGRIGrille[uiLigne][uiColonne];
}

void CGrille::GRIModifierValeur(unsigned int uiLigne, unsigned int uiColonne, unsigned int uiValeur) {
	ppuiGRIGrille[uiLigne][uiColonne] = uiValeur;
}

unsigned int CGrille::GRIRecupererZone(unsigned int uiLigne, unsigned int uiColonne) {
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

	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle) {
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2) {
			cout << ppuiGRIGrille[uiBoucle][uiBoucle2];
			if (uiBoucle2 != uiGRITaille - 1)
				cout << " | ";
		}
		cout << endl;
		if (uiBoucle != uiGRITaille - 1)
			cout << endl;
	}
}
