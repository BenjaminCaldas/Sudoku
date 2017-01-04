#include <stdlib.h>

#include "Partie.h"

CPartie::CPartie() {
	pGRIGrille = pGRIGrilleOrigine = NULL;
}

CPartie::CPartie(CPartie & PARUnePartie) {
	pGRIGrille = PARUnePartie.pGRIGrille;
	pGRIGrilleOrigine = PARUnePartie.pGRIGrilleOrigine;
}

CPartie::CPartie(CGrille * pGRIUneGrille) {
	pGRIGrille = pGRIGrilleOrigine = pGRIUneGrille;
}

void CPartie::PARChargerPartie() {

}

void CPartie::PARSauvegarderPartie() {

}

void CPartie::PARReinitialiserGrille() {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	for (uiBoucle = 0; uiBoucle < pGRIGrille->GRILireTaille(); ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < pGRIGrille->GRILireTaille(); ++uiBoucle2)
			pGRIGrille->GRIModifierValeur(uiBoucle, uiBoucle2, pGRIGrilleOrigine->GRILireValeur(uiBoucle, uiBoucle2));
}