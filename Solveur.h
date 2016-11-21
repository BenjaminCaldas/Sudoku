#pragma once

#include "Sudoku.h"

class CSolveur
{
	private :
		long unsigned int luiSLVTempsResolution;
		long unsigned int luiSLVNbNumerosTestes;
		unsigned int uiSLVPourcentageResolution;

	public:
		CSolveur();
		CSolveur(CSolveur & SLVUnSolveur);
		~CSolveur();
		void SLVResoudre(CSudoku SDKSudoku);
};

