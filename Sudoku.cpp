#include "Sudoku.h"

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
	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle) {
		for (uiBoucle2 = 0; uiBoucle2 < uiSDKTaille; ++uiBoucle2) {
			ppuiSDKGrille[uiBoucle][uiBoucle2] = SDKUnSudoku.ppuiSDKGrille[uiBoucle][uiBoucle2];
			ppuiSDKGrilleBase[uiBoucle][uiBoucle2] = ppuiSDKGrille[uiBoucle][uiBoucle2];
		}
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
	for (uiBoucle = 0; uiBoucle < uiSDKTaille; ++uiBoucle) {
		for (uiBoucle2 = 0; uiBoucle2 < uiSDKTaille; ++uiBoucle2) {
			ppuiSDKGrille[uiBoucle][uiBoucle2] = uiUneGrille[uiBoucle][uiBoucle2];
			ppuiSDKGrilleBase[uiBoucle][uiBoucle2] = uiUneGrille[uiBoucle][uiBoucle2];
		}
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

}

bool CSudoku::SDKVerifierLigne(unsigned int uiNo, unsigned int uiNoLigne) {

}

bool CSudoku::SDKVerifierColonne(unsigned int uiNo, unsigned int uiNoColonne) {

}

unsigned int CSudoku::SDKRecupererZone(unsigned int uiLigne, unsigned int uiColonne) {

}

bool CSudoku::SDKVerifierZone(unsigned int uiNo, unsigned int uiNoZone) {

}

void CSudoku::SDKInsererNo(unsigned int uiNo, unsigned int uiLigne, unsigned int uiColonne) {

}

void CSudoku::SDKSupprimerNo(unsigned int uiNo, unsigned int uiLigne, unsigned int uiColonne) {

}

void CSudoku::SDKAfficherGrille() {

}
