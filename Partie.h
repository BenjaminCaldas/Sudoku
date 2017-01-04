#pragma once
#include "Grille.h"

class CPartie {

	private :
		CGrille * pGRIGrille;
		CGrille * pGRIGrilleOrigine;

	public:
		CPartie();
		CPartie(CPartie & PARUnePartie);
		CPartie(CGrille * pGRIUneGrille);

		void PARChargerPartie();
		void PARSauvegarderPartie();
		void PARReinitialiserGrille();
};

