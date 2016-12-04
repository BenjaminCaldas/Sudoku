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
	ppuiGRIGrilleBase = new unsigned int * [uiGRITaille];
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle) {
		ppuiGRIGrille[uiBoucle] = new unsigned int [uiGRITaille];
		ppuiGRIGrilleBase[uiBoucle] = new unsigned int [uiGRITaille];
	}
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2) {
			ppuiGRIGrille[uiBoucle][uiBoucle2] = GRIUnSudoku.ppuiGRIGrille[uiBoucle][uiBoucle2];
			ppuiGRIGrilleBase[uiBoucle][uiBoucle2] = ppuiGRIGrille[uiBoucle][uiBoucle2];
		}
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2)
			if ((ppuiGRIGrille[uiBoucle][uiBoucle2] > 9) || (ppuiGRIGrille[uiBoucle][uiBoucle2] < 1)) {
				ppuiGRIGrille[uiBoucle][uiBoucle2] = 0;
				ppuiGRIGrilleBase[uiBoucle][uiBoucle2] = 0;
			}
}

CGrille::CGrille(unsigned int ** uiUneGrille, unsigned int uiUneTaille) {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	uiGRITaille = uiUneTaille;
	ppuiGRIGrille = new unsigned int * [uiGRITaille];
	ppuiGRIGrilleBase = new unsigned int * [uiGRITaille];
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle) {
		ppuiGRIGrille[uiBoucle] = new unsigned int [uiGRITaille];
		ppuiGRIGrilleBase[uiBoucle] = new unsigned int [uiGRITaille];
	}
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2) {
			ppuiGRIGrille[uiBoucle][uiBoucle2] = uiUneGrille[uiBoucle][uiBoucle2];
			ppuiGRIGrilleBase[uiBoucle][uiBoucle2] = ppuiGRIGrille[uiBoucle][uiBoucle2];
		}
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2)
			if ((ppuiGRIGrille[uiBoucle][uiBoucle2] > 9) || (ppuiGRIGrille[uiBoucle][uiBoucle2] < 1)) {
				ppuiGRIGrille[uiBoucle][uiBoucle2] = 0;
				ppuiGRIGrilleBase[uiBoucle][uiBoucle2] = 0;
			}
}

CGrille::~CGrille(void) {
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle) {
		delete [] ppuiGRIGrille[uiBoucle];
		
	}
	delete [] ppuiGRIGrille;
	
}

void CGrille::GRIReinitialiserGrille() {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 <uiGRITaille; ++uiBoucle2)
			ppuiGRIGrille[uiBoucle][uiBoucle2] = ppuiGRIGrilleBase[uiBoucle][uiBoucle2];
}

bool CGrille::GRIVerifierLigne(unsigned int uiNo, unsigned int uiNoLigne) {
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		if (ppuiGRIGrille[uiNoLigne][uiBoucle] == uiNo)
			return false;

	return true;
}

bool CGrille::GRIVerifierColonne(unsigned int uiNo, unsigned int uiNoColonne) {
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		if (ppuiGRIGrille[uiBoucle][uiNoColonne] == uiNo)
			return false;

	return true;
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

bool CGrille::GRIVerifierZone(unsigned int uiNo, unsigned int uiNoZone) {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	switch (uiNoZone) {
		case 1 :
			for (uiBoucle = 0; uiBoucle < 3; ++uiBoucle)
				for (uiBoucle2 = 0; uiBoucle2 < 3; ++uiBoucle2)
					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 2 :
			for (uiBoucle = 3; uiBoucle < 6; ++uiBoucle)
				for (uiBoucle2 = 0; uiBoucle2 < 3; ++uiBoucle2)
					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 3 :
			for (uiBoucle = 6; uiBoucle < 9; ++uiBoucle)
				for (uiBoucle2 = 0; uiBoucle2 < 3; ++uiBoucle2)
					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 4 :
			for (uiBoucle = 0; uiBoucle < 3; ++uiBoucle)
				for (uiBoucle2 = 3; uiBoucle2 < 6; ++uiBoucle2)
					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 5 :
			for (uiBoucle = 3; uiBoucle < 6; ++uiBoucle)
				for (uiBoucle2 = 3; uiBoucle2 < 6; ++uiBoucle2)
					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 6 :
			for (uiBoucle = 6; uiBoucle < 9; ++uiBoucle)
				for (uiBoucle2 = 3; uiBoucle2 < 6; ++uiBoucle2)
					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 7 :
			for (uiBoucle = 0; uiBoucle < 3; ++uiBoucle)
				for (uiBoucle2 = 6; uiBoucle2 < 9; ++uiBoucle2)
					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 8 :
			for (uiBoucle = 3; uiBoucle < 6; ++uiBoucle)
				for (uiBoucle2 = 6; uiBoucle2 < 9; ++uiBoucle2)
					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 9 :
			for (uiBoucle = 6; uiBoucle < 9; ++uiBoucle)
				for (uiBoucle2 = 6; uiBoucle2 < 9; ++uiBoucle2)
					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
	}
	return true;
}

void CGrille::GRIInsererNo(unsigned int uiNo, unsigned int uiLigne, unsigned int uiColonne) {
	ppuiGRIGrille[uiLigne][uiColonne] = uiNo;
}

void CGrille::GRISupprimerNo(unsigned int uiNo, unsigned int uiLigne, unsigned int uiColonne) {
	ppuiGRIGrille[uiLigne][uiColonne] = 0;
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
