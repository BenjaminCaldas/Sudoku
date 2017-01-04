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

void CSolveur::SLVResoudre() {
	cout << "Grille de base : " << endl;
	pGRIGrille->GRIAfficherGrille();
	cout << endl;

	unsigned int uiBoucle1;
	unsigned int uiBoucle2;
	unsigned int uiValeur;
	unsigned int uiTaille = pGRIGrille->GRILireTaille();

	CControleurGrille CGRControleur1(pGRIGrille);

	for (uiBoucle1 = 0; uiBoucle1 < uiTaille; ++uiBoucle1) {
		for (uiBoucle2 = 0; uiBoucle2 < uiTaille; ++uiBoucle2) {
			if (pGRIGrille->GRILireValeur(uiBoucle1, uiBoucle2) == 0) {
				cout << "Ligne : " << uiBoucle1 << " | " << "Colonne : " << uiBoucle2 << endl;
				for (uiValeur = 1; uiValeur <= uiTaille; ++uiValeur) {
					cout << "Val : " << uiValeur;
					cout << " L : " << CGRControleur1.CGRVerifierLigne(uiValeur, uiBoucle1);
					cout << " C : " << CGRControleur1.CGRVerifierColonne(uiValeur, uiBoucle2);
					cout << " Z" << pGRIGrille->GRIRecupererZone(uiBoucle1, uiBoucle2) << " : " << CGRControleur1.CGRVerifierZone(uiValeur, pGRIGrille->GRIRecupererZone(uiBoucle1, uiBoucle2)) << endl;
					if ((CGRControleur1.CGRVerifierLigne(uiValeur, uiBoucle1)) &&
					(CGRControleur1.CGRVerifierColonne(uiValeur, uiBoucle2)) &&
					(CGRControleur1.CGRVerifierZone(uiValeur, pGRIGrille->GRIRecupererZone(uiBoucle1, uiBoucle2))))
					pGRIGrille->GRIModifierValeur(uiBoucle1, uiBoucle2, uiValeur);
				}
				cout << endl;
			}
		}
	}

	cout << "Nouvelle grille : " << endl;
	pGRIGrille->GRIAfficherGrille();
}