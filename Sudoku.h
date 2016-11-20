#pragma once
class CSudoku
{
	private : 
		unsigned int ** uiSDKGrille;
		unsigned int ** uiSDKGrilleBase;
		unsigned int uiSDKTaille;

	public:
		CSudoku();
		CSudoku(CSudoku & SDKUnSudoku);
		CSudoku(unsigned int ** uiUneGrille, unsigned int uiUneTaille);
		~CSudoku();
		void SDKReinitialiserGrille();
		bool SDKVerifierLigne(unsigned int uiNo, unsigned int uiNoLigne);
		bool SDKVerifierColonne(unsigned int uiNo, unsigned int uiNoColonne);
		unsigned int SDKRecupererZone(unsigned int uiLigne, unsigned int uiColonne);
		bool SDKVerifierZone(unsigned int uiNo, unsigned int uiNoZone);
		void SDKInsererNo(unsigned int uiNo, unsigned int uiLigne, unsigned int uiColonne);
		void SDKSupprimerNo(unsigned int uiNo, unsigned int uiLigne, unsigned int uiColonne);
		void SDKAfficherGrille();

};

