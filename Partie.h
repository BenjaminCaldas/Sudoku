#pragma once
#include "Grille.h"

class CPartie
{
public:

	CGrille * pGRIGrille;
	CGrille * pGRIGrilleOrigine;

	void PARChargerPartie();
	void PARSauvegarderPartie();
	void PARInitialiserGrille();

	CPartie(void);
	~CPartie(void);
};

