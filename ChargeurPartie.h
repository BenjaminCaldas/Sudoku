#ifndef CCHARGEURPARTIE_H
#define CCHARGEURPARTIE_H

#include "dirent.h"
#include "Partie.h"
#include "Parseur.h"

#define NB_LIGNES 7

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
		void CHPNouvellePartie(); // Doit renvoyer un objet Partie
		unsigned int CHPCompterNombreFichiers(DIR * dUnRepertoire);
		void CHPChargerPartie();
		CPartie * CHPLireFichier(std::string sChemin);
};

#endif
