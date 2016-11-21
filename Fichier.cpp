#include "Fichier.h"

CFichier::CFichier() {
	pcFICChemin = NULL;
}

CFichier::CFichier(CFichier & FICUnFichier) {
	if(fFICFichier.is_open()) {
		pcFICChemin = new char[strlen(FICUnFichier.pcFICChemin)+1];
		strcpy(pcFICChemin, FICUnFichier.pcFICChemin);
	}
	else {
		pcFICChemin = NULL;
		// Lever une exception (Erreur lors de la lecture du fichier)
		//throw CExcept(ERR_FIC);
	}
}

CFichier::CFichier(char * pcChemin) {
	if(fFICFichier.is_open()) {
		pcFICChemin = new char[strlen(pcChemin)+1];
		strcpy(pcFICChemin, pcChemin);
	}
	else {
		pcFICChemin = NULL;
		// Lever une exception (Erreur lors de la lecture du fichier)
		//throw CExcept(ERR_FIC);
	}
}

CFichier::~CFichier() {
	if(fFICFichier.is_open())
		fFICFichier.close();
	delete[] pcFICChemin;
}

char * CFichier::FICLireChemin() {
	return pcFICChemin;
}

void CFichier::FICModifierChemin(char * pcChemin) {
	unsigned int uiBoucle;
	strcpy(pcFICChemin, pcChemin);
}

unsigned int ** CFichier::FICLiregrille() {

}
