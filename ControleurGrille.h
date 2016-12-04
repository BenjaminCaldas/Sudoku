#include "Except.h"
#include "Grille.h"

class CControleurGrille
{
public:

	CGrille * pGRIGrille;

	CControleurGrille(void);
	~CControleurGrille(void);
	
	bool CGRVerifierLigne(unsigned int uiNo, unsigned int uiNoLigne);
	bool CGRVerifierColonne(unsigned int uiNo, unsigned int uiNoColonne);
	bool CGRVerifierZone(unsigned int uiNo, unsigned int * piZone);

	void CGRModifierCase(unsigned int uiLigne, unsigned int uiColonne, unsigned int uiValeur);
};

