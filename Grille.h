#pragma once
class CGrille
{
	private : 
		unsigned int ** ppuiGRIGrille;
		unsigned int uiGRITaille;

	public:
		CGrille();
		CGrille(CGrille & GRIUnSudoku);
		CGrille(unsigned int ** uiUneGrille, unsigned int uiUneTaille);
		~CGrille();

		unsigned int GRILireTaille();
		unsigned int GRILireValeur(unsigned int uiLigne, unsigned int uiColonne);
		void GRIModifierValeur(unsigned int uiLigne, unsigned int uiColonne, unsigned int uiValeur);

		unsigned int GRIRecupererZone(unsigned int uiLigne, unsigned int uiColonne);
		
		void GRIAfficherGrille();

};

