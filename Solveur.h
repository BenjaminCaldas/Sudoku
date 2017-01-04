#pragma once

#include "Grille.h"

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
		void SLVResoudre();
};

