#pragma once
#include "Grille.h"
#include <iostream>

class CPartie {

	private :
		CGrille * pGRIGrille;
		CGrille * pGRIGrilleOrigine;
		unsigned int uiPARTaille;
		std::string sPARNomJoueur;
		unsigned int uiPARCasesRemplies;
		unsigned int uiPARNbCoups;
		bool bPARStatut;

	public:
		CPartie();
		CPartie(CPartie & PARUnePartie);
		CPartie(CGrille * pGRIUneGrille, std::string sNomJoueur);
		~CPartie();

		// Fonctions nécessaires à une partie
		unsigned int * PARDemanderCoordonnees();
		unsigned int PARDemanderValeur();
		bool PARVerifierCoordonneesGrilleOrigine(unsigned int uiLigne, unsigned int uiColonne);
		bool PARVerifierAvancement();
		void PARReinitialiserGrille();
		void PARAfficherGrilleAvecCouleurs();

		// Pour les statistiques
		void PARAfficherStatistiques();
		unsigned int PARCompterCasesOrigine();

		// La fonction "principale"
		void PARJouer();
		
		// Gestion des parties
		void PARChargerPartie(); // Utile ?
		void PARSauvegarderPartie();

		
};

