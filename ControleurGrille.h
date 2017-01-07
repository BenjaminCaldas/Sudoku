#include "Except.h"
#include "Grille.h"

class CControleurGrille
{
	private :
		CGrille * pGRIGrille;

	public :
		CControleurGrille();
		CControleurGrille(CControleurGrille & CGRUnControleur);
		CControleurGrille(CGrille * GRIUneGrille);
	
		bool CGRVerifierLigne(unsigned int uiNo, unsigned int uiNoLigne);
		bool CGRVerifierColonne(unsigned int uiNo, unsigned int uiNoColonne);
		bool CGRVerifierZone(unsigned int uiNo, unsigned int uiNoZone);
		bool CGRVerifierDisponibiliteCase(unsigned int uiNoLigne, unsigned int uiNoColonne);

		bool CGRModifierCase(unsigned int uiLigne, unsigned int uiColonne, unsigned int uiValeur);
		unsigned int CGRCompterCasesRemplies();
};

