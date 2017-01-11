/*!
* \file Partie.h
* \author Benjamin Caldas
* \brief Le fichier d'en-tête de la classe CPartie.
*/
#ifndef CPARTIE_H
#define CPARTIE_H

#include <windows.h>
#include <string>
#include <fstream>

#include "ControleurGrille.h"
#include "Grille.h"
#include "Solveur.h"

using namespace std;

/*! 
* \class CPartie
* \brief Cette classe permet de créer des objets permettant de jouer une partie de Sudoku.
*/
class CPartie {

	private :
		CGrille * pGRIGrille; /*!< La grille de jeu du Sudoku. */
		CGrille * pGRIGrilleOrigine; /*!< La grille d'origine du Sudoku. */
		unsigned int uiPARTaille; /*!< La taille de la grille de Sudoku. */
		string sPARNomJoueur; /*!< Le nom du joueur jouant la partie. */
		unsigned int uiPARCasesRemplies; /*!< Le nombre de cases remplies dans la grille de Sudoku. */
		unsigned int uiPARNbCoups; /*!< Le nombre de coups effectués durant la partie de Sudoku. */
		bool bPARStatut; /*!< Le statut de la partie : 1 si terminée, 0 sinon. */

	public:
		/*!
		* \brief Constructeur par défault de la classe CPartie.
		* \param void
		*/
		CPartie(void);

		/*!
		* \brief Constructeur de recopie de la classe CPartie.
		* \param PARUnePartie Une référence vers l'objet de la classe CPartie qui est à recopier.
		*/
		CPartie(CPartie & PARUnePartie);

		/*!
		* \brief Constructeur de la classe CPartie.
		* \param pGRIUneGrille La grille de la partie.
		* \param sNomJoeur Le nom du joueur de la partie.
		*/
		CPartie(CGrille * pGRIUneGrille, string sNomJoueur);

		/*!
		* \brief Constructeur de la classe CPartie.
		* \param pGRIUneGrille La grille de Sudoku de la partie.
		* \param pGRIUneGrilleOrigine La grille de Sudoku d'origine de la partie.
		* \param uiUneTaille La taille de la grille de Sudoku de la partie.
		* \param sNomJoueur Le nom du joueur de la partie.
		* \param uiLesCasesRemplies Les cases remplies de la partie.
		* \param uiuNbCoups Le nombre de coups de la partie.
		* \param bUnStatut Le statut de la partie.
		*/
		CPartie(CGrille * pGRIUneGrille, CGrille * pGRIUneGrilleOrigine, unsigned int uiUneTaille, string sNomJoueur, unsigned int uiLesCasesRemplies, unsigned int uiUnNbCoups, bool bUnStatut);
		
		/*!
		* \brief Destructeur de la classe CPartie.
		* \param void
		*/
		~CPartie(void);

		/*!
		* \brief Fonction demandant les coordonnées de la case à modifier dans la grille de Sudoku.
		* \param void
		* \return Un tableau de 2 entiers avec en indice 0 la ligne et en indice 1 la colonne à modifier.
		*/
		unsigned int * PARDemanderCoordonnees(void);

		/*!
		* \brief Fonction demandant la valeur à insérer dans une case de la grille de Sudoku.
		* \param void
		* \return unsigned int La valeut qui sera insérer dans la grille de Sudoku.
		*/
		unsigned int PARDemanderValeur(void);

		/*!
		* \brief Fonction vérifiant si une case que l'on souhait modifier est une case de la grille d'origine.
		* \param uiLigne La ligne de la case à vérifier.
		* \param uiColonne La colonne de la case à vérifier.
		* \return Un boolean valant 0 si les coordonnées sont celle d'une case de la grille d'origine, 1 sinon.
		*/
		bool PARVerifierCoordonneesGrilleOrigine(unsigned int uiLigne, unsigned int uiColonne);

		/*!
		* \brief Fonction vérifiant si la grille est complètement résolue.
		* \param void
		* \return Un boolean qui vaut 0 si la grille a été résolue, 1 sinon.
		*/
		bool PARVerifierAvancement(void);

		/*!
		* \brief Fonction permettant de réinitialiser la grille, c'est à dire de la remttre à l'état de la grille d'origine.
		* \param void
		* \return void
		*/
		void PARReinitialiserGrille(void);

		/*!
		* \brief Fonction permettant d'afficher la grille en mettant en couleur les cases de la grille d'origine.
		* \param void
		* \return void
		*/
		void PARAfficherGrilleAvecCouleurs(void);

		/*!
		* \brief Fonction permettant d'afficher les statistiques de la partie : le nombre de cases remplies et le nombre de coups joués.
		* \param void
		* \return void
		*/
		void PARAfficherStatistiques(void);

		/*!
		* \brief Fonction comptant le nombre de cases étant remplies sur la grille d'origine.
		* \param void
		* \return Le nombre de cases remplies sur la grille d'origine.
		*/
		unsigned int PARCompterCasesOrigine(void);

		/*!
		* \brief Fonction permettant de jouer une partie de Sudoku.
		* \param void
		* \return void
		*/
		void PARJouer(void);

		/*!
		* \brief Fonction permettant de sauvegarder une partie en cours. Les parties sont sauvegardées dans le dossiers './Parties/' et portent le nom du joueur.
		* \param void
		* \return void
		*/
		void PARSauvegarderPartie(void);
};

#endif