#include <stdlib.h>
#include <iostream>

#include "Solveur.h"
#include "ControleurGrille.h"

using namespace std;

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

bool CSolveur::SLVResoudre(unsigned int uiPosition) {
	CControleurGrille CGRControleur(pGRIGrille);
	unsigned int uiTailleGrille = pGRIGrille->GRILireTaille();

	if (uiPosition == uiTailleGrille * uiTailleGrille)
		return true;

	unsigned int uiLigne = uiPosition / 9;
	unsigned int uiColonne = uiPosition % 9;

	if (pGRIGrille->GRILireValeur(uiLigne, uiColonne) != 0)
		return SLVResoudre(uiPosition + 1);

	unsigned int uiNumero;

	for (uiNumero = 1; uiNumero <= uiTailleGrille; ++uiNumero) {
		if (CGRControleur.CGRVerifierLigne(uiNumero, uiLigne) && CGRControleur.CGRVerifierColonne(uiNumero, uiColonne) && CGRControleur.CGRVerifierZone(uiNumero, pGRIGrille->GRIRecupererZone(uiLigne, uiColonne))) {
			pGRIGrille->GRIModifierValeur(uiLigne, uiColonne, uiNumero);
			pGRIGrille->GRIAfficherGrille();
			if (SLVResoudre(uiPosition + 1))
				return true;
		}
	}
	pGRIGrille->GRIModifierValeur(uiLigne, uiColonne, 0);

	return false;
}