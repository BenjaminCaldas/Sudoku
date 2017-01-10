#ifndef CCHARGEURPARTIE_H
#define CCHARGEURPARTIE_H

#include "dirent.h"
#include "Partie.h"
#include "Parseur.h"


class CChargeurPartie
{
	private :
		std::string sCHPNomJoueur;
		bool bCHPNouvellePartie;

	public:
		CChargeurPartie();

		std::string CHPRecupererNomJoueur();
		bool CHPRecupererEtatPartie();
		void CHPMenuPrincipal();
		void CHPNouvellePartie();
		unsigned int CHPCompterNombreFichiers(DIR * dUnRepertoire);
		void CHPChargerPartie();
		// Utile ?
		CPartie * CHPLireFichier(char * pcChemin);
};

#endif
