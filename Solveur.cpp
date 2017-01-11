#include "Solveur.h"

CSolveur::CSolveur() {
	pGRIGrille = NULL;
	luiSLVTempsResolution = luiSLVNbNumerosTestes = uiSLVPourcentageResolution = 0;
}

CSolveur::CSolveur(CSolveur & SLVUnSolveur) {
	luiSLVTempsResolution = SLVUnSolveur.luiSLVTempsResolution;
	luiSLVNbNumerosTestes = SLVUnSolveur.luiSLVNbNumerosTestes;
	uiSLVPourcentageResolution = SLVUnSolveur.uiSLVPourcentageResolution;
}

CSolveur::CSolveur(CGrille * GRIUneGrille) {
	pGRIGrille = GRIUneGrille;
	luiSLVTempsResolution = luiSLVNbNumerosTestes = uiSLVPourcentageResolution = 0;
}

unsigned int CSolveur::SLVRecupererTempsResolution() {
	return luiSLVTempsResolution;
}

bool CSolveur::SLVEstValide(unsigned int uiPosition) {
	CControleurGrille CGRControleur(pGRIGrille);
	unsigned int uiTailleGrille = pGRIGrille->GRILireTaille();

	if (uiPosition == uiTailleGrille * uiTailleGrille)
		return true;

	unsigned int uiLigne = uiPosition / 9;
	unsigned int uiColonne = uiPosition % 9;

	if (pGRIGrille->GRILireValeur(uiLigne, uiColonne) != 0)
		return SLVEstValide(uiPosition + 1);

	unsigned int uiNumero;

	for (uiNumero = 1; uiNumero <= uiTailleGrille; ++uiNumero) {
		if (CGRControleur.CGRVerifierLigne(uiNumero, uiLigne) && CGRControleur.CGRVerifierColonne(uiNumero, uiColonne) && CGRControleur.CGRVerifierZone(uiNumero, pGRIGrille->GRIRecupererZone(uiLigne, uiColonne))) {
			pGRIGrille->GRIModifierValeur(uiLigne, uiColonne, uiNumero);
			pGRIGrille->GRIAfficherGrille();
			if (SLVEstValide(uiPosition + 1))
				return true;
		}
	}
	pGRIGrille->GRIModifierValeur(uiLigne, uiColonne, 0);

	return false;
}

void CSolveur::SLVResoudre() {
	time_t tDebut;
	time_t tFin;
	struct tm tmReference = {0};
	long unsigned int luiDebut;
	long unsigned int luiFin;

	tmReference.tm_hour = 0;   tmReference.tm_min = 0; tmReference.tm_sec = 0;
	tmReference.tm_year = 100; tmReference.tm_mon = 0; tmReference.tm_mday = 1;

	time(&tDebut);
	luiDebut = difftime(tDebut ,mktime(&tmReference));

	SLVEstValide(0);

	time(&tFin);
	luiFin = difftime(tFin ,mktime(&tmReference));

	luiSLVTempsResolution = luiFin - luiDebut;
}