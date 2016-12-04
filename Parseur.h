#include <iostream>
#include <fstream>
#include <iostream>
#include <stdlib.h>

#include "Except.h"

#ifndef CPARSEUR_H
#define CPARSEUR_H

#define TAILLE_MAX_ATTRIBUT 100
#define TAILLE_MAX_VALEUR 100

#define ERREUR_OUVERTURE_FICHIER 7
#define FICHIER_NON_OUVERT 8

class CParseur
{
private:
	
	std::ifstream fichier;
	char * pcPARValeur;
	char * pcPARAttribut;
	//unsigned int uiPARLigneCurseur;

public:

	CParseur(char * pcChemin);
	~CParseur(void);

	char*PARLireValeur(){return pcPARValeur;}
	char*PARLireAttribut(){return pcPARAttribut;}
	void PARModifierFichier(char * pcChemin);

	void PARLireLigne();
	void PARParseValeur();
	void PARParseAttribut();
};

#endif
