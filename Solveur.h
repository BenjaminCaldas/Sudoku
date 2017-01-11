#ifndef CSOLVEUR_H
#define CSOLVEUR_H

#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "Grille.h"
#include "ControleurGrille.h"

using namespace std;

class CSolveur
{
	private :
		CGrille * pGRIGrille;
		long unsigned int luiSLVTempsResolution;
		long unsigned int luiSLVNbNumerosTestes;
		unsigned int uiSLVPourcentageResolution;

	public:
		CSolveur();
		CSolveur(CSolveur & SLVUnSolveur);
		CSolveur(CGrille * GRIUneGrille);

		unsigned int SLVRecupererTempsResolution();

		bool SLVEstValide(unsigned int uiPosition);
		void SLVResoudre();
};

#endif