#pragma once
#include "Grille.h"

class CPartie {

	private :
		CGrille * pGRIGrille;
		CGrille * pGRIGrilleOrigine;
		unsigned int uiGRITaille;
		unsigned int uiGRICasesRemplies;
		unsigned int uiGRINbCoups;

	public:
		CPartie();
		CPartie(CPartie & PARUnePartie);
		CPartie(CGrille * pGRIUneGrille);

		// Fonctions nécessaires à une partie
		unsigned int * PARDemanderCoordonnees();
		unsigned int PARDemanderValeur();
		bool PARVerifierCoordonneesGrilleOrigine(unsigned int uiLigne, unsigned int uiColonne);
		bool PARVerifierAvancement();
		void PARReinitialiserGrille();

		// Pour les statistiques
		void PARAfficherStatistiques();
		unsigned int PARCompterCasesOrigine();

		// La fonction "principale"
		void PARJouer();
		
		// Gestion des parties
		void PARChargerPartie();
		void PARSauvegarderPartie();

		void PARAfficherGrilleAvecCouleurs();
};

