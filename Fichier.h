#pragma once

#include <fstream>

#include "Except.h"

using namespace std;

class CFichier
{
	private :
		char * pcFICChemin;
		ifstream fFICFichier;

	public:
		CFichier();
		CFichier(CFichier & FICUnFichier);
		CFichier(char * pcChemin);
		~CFichier();
		char * FICLireChemin();
		void FICModifierChemin(char * pcChemin);
		unsigned int ** FICLiregrille();
};

