#include <iostream>
#include <stdlib.h>

#include "Sudoku.h"

using namespace std;

CSudoku::CSudoku(void) {
	uiSDKTaille = 0;
	ppuiSDKGrille = NULL;
	ppuiSDKGrilleBase = NULL;
}

CSudoku::CSudoku(CSudoku & SDKUnSudoku) {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	uiSDKTaille = SDKUnSudoku.uiSDKTaille;
	ppuiSDKGrille = new unsigned int * [uiSDKTaille];
	ppuiSDKGrilleBase = new unsigned int * [uiSDKTaille];
	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle) {
		ppuiSDKGrille[uiBoucle] = new unsigned int [uiSDKTaille];
		ppuiSDKGrilleBase[uiBoucle] = new unsigned int [uiSDKTaille];
	}
	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiSDKTaille; ++uiBoucle2) {
			ppuiSDKGrille[uiBoucle][uiBoucle2] = SDKUnSudoku.ppuiSDKGrille[uiBoucle][uiBoucle2];
			ppuiSDKGrilleBase[uiBoucle][uiBoucle2] = ppuiSDKGrille[uiBoucle][uiBoucle2];
		}
	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiSDKTaille; ++uiBoucle2)
			if ((ppuiSDKGrille[uiBoucle][uiBoucle2] > 9) || (ppuiSDKGrille[uiBoucle][uiBoucle2] < 1)) {
				ppuiSDKGrille[uiBoucle][uiBoucle2] = 0;
				ppuiSDKGrilleBase[uiBoucle][uiBoucle2] = 0;
			}
}

CSudoku::CSudoku(unsigned int ** uiUneGrille, unsigned int uiUneTaille) {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	uiSDKTaille = uiUneTaille;
	ppuiSDKGrille = new unsigned int * [uiSDKTaille];
	ppuiSDKGrilleBase = new unsigned int * [uiSDKTaille];
	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle) {
		ppuiSDKGrille[uiBoucle] = new unsigned int [uiSDKTaille];
		ppuiSDKGrilleBase[uiBoucle] = new unsigned int [uiSDKTaille];
	}
	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiSDKTaille; ++uiBoucle2) {
			ppuiSDKGrille[uiBoucle][uiBoucle2] = uiUneGrille[uiBoucle][uiBoucle2];
			ppuiSDKGrilleBase[uiBoucle][uiBoucle2] = ppuiSDKGrille[uiBoucle][uiBoucle2];
		}
	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiSDKTaille; ++uiBoucle2)
			if ((ppuiSDKGrille[uiBoucle][uiBoucle2] > 9) || (ppuiSDKGrille[uiBoucle][uiBoucle2] < 1)) {
				ppuiSDKGrille[uiBoucle][uiBoucle2] = 0;
				ppuiSDKGrilleBase[uiBoucle][uiBoucle2] = 0;
			}
}

CSudoku::~CSudoku(void) {
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle) {
		delete [] ppuiSDKGrille[uiBoucle];
		delete [] ppuiSDKGrilleBase[uiBoucle];
	}
	delete [] ppuiSDKGrille;
	delete [] ppuiSDKGrilleBase;
}

void CSudoku::SDKReinitialiserGrille() {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 <uiSDKTaille; ++uiBoucle2)
			ppuiSDKGrille[uiBoucle][uiBoucle2] = ppuiSDKGrilleBase[uiBoucle][uiBoucle2];
}

bool CSudoku::SDKVerifierLigne(unsigned int uiNo, unsigned int uiNoLigne) {
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle)
		if (ppuiSDKGrille[uiNoLigne][uiBoucle] == uiNo)
			return false;

	return true;
}

bool CSudoku::SDKVerifierColonne(unsigned int uiNo, unsigned int uiNoColonne) {
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle)
		if (ppuiSDKGrille[uiBoucle][uiNoColonne] == uiNo)
			return false;

	return true;
}

unsigned int CSudoku::SDKRecupererZone(unsigned int uiLigne, unsigned int uiColonne) {
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

bool CSudoku::SDKVerifierZone(unsigned int uiNo, unsigned int uiNoZone) {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	switch (uiNoZone) {
		case 1 :
			for (uiBoucle = 0; uiBoucle < 3; ++uiBoucle)
				for (uiBoucle2 = 0; uiBoucle2 < 3; ++uiBoucle2)
					if (ppuiSDKGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 2 :
			for (uiBoucle = 3; uiBoucle < 6; ++uiBoucle)
				for (uiBoucle2 = 0; uiBoucle2 < 3; ++uiBoucle2)
					if (ppuiSDKGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 3 :
			for (uiBoucle = 6; uiBoucle < 9; ++uiBoucle)
				for (uiBoucle2 = 0; uiBoucle2 < 3; ++uiBoucle2)
					if (ppuiSDKGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 4 :
			for (uiBoucle = 0; uiBoucle < 3; ++uiBoucle)
				for (uiBoucle2 = 3; uiBoucle2 < 6; ++uiBoucle2)
					if (ppuiSDKGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 5 :
			for (uiBoucle = 3; uiBoucle < 6; ++uiBoucle)
				for (uiBoucle2 = 3; uiBoucle2 < 6; ++uiBoucle2)
					if (ppuiSDKGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 6 :
			for (uiBoucle = 6; uiBoucle < 9; ++uiBoucle)
				for (uiBoucle2 = 3; uiBoucle2 < 6; ++uiBoucle2)
					if (ppuiSDKGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 7 :
			for (uiBoucle = 0; uiBoucle < 3; ++uiBoucle)
				for (uiBoucle2 = 6; uiBoucle2 < 9; ++uiBoucle2)
					if (ppuiSDKGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 8 :
			for (uiBoucle = 3; uiBoucle < 6; ++uiBoucle)
				for (uiBoucle2 = 6; uiBoucle2 < 9; ++uiBoucle2)
					if (ppuiSDKGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
		case 9 :
			for (uiBoucle = 6; uiBoucle < 9; ++uiBoucle)
				for (uiBoucle2 = 6; uiBoucle2 < 9; ++uiBoucle2)
					if (ppuiSDKGrille[uiBoucle][uiBoucle2] == uiNo)
						return false;
			break;
	}
	return true;
}

void CSudoku::SDKInsererNo(unsigned int uiNo, unsigned int uiLigne, unsigned int uiColonne) {
	ppuiSDKGrille[uiLigne][uiColonne] = uiNo;
}

void CSudoku::SDKSupprimerNo(unsigned int uiLigne, unsigned int uiColonne) {
	ppuiSDKGrille[uiLigne][uiColonne] = 0;
}

void CSudoku::SDKAfficherGrille() {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle) {
		for (uiBoucle2 = 0; uiBoucle2 < uiSDKTaille; ++uiBoucle2) {
			cout << ppuiSDKGrille[uiBoucle][uiBoucle2];
			if (uiBoucle2 != uiSDKTaille - 1)
				cout << " | ";
		}
		cout << endl;
		if (uiBoucle != uiSDKTaille - 1)
			cout << endl;
	}
}
