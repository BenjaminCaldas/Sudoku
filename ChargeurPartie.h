#ifndef CCHARGEURPARTIE_H
#define CCHARGEURPARTIE_H

#include "Partie.h"
#include "Parseur.h"


class CChargeurPartie
{
public:
	CChargeurPartie(void);
	CPartie * CHPLireFichier(char * pcChemin);
};

#endif
