#ifndef CCHARGEURPARTIE_H
#define CCHARGEURPARTIE_H

#include "dirent.h"
#include "Partie.h"
#include "Parseur.h"

#define NB_LIGNES_PARTIE 7
#define NB_LIGNES_GRILLE 3

class CChargeurPartie
{
	private :
		std::string sCHPNomJoueur;
		bool bCHPNouvellePartie;

	public:
		CChargeurPartie();

		std::string CHPRecupererNomJoueur();
		bool CHPRecupererEtatPartie();
		CPartie * CHPMenuPrincipal();
		CPartie * CHPNouvellePartie();
		unsigned int CHPCompterNombreFichiers(DIR * dUnRepertoire);
		CPartie * CHPChargerPartie();
		CPartie * CHPLireFichier(std::string sChemin);
};

#endif
