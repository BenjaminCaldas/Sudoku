/**
* \file Grille.h
* \author Benjamin Caldas
* \brief Le fichier d'en-t�te de la classe CGrille.
*/
#ifndef CGRILLE_H
#define CGRILLE_H

#include <stdlib.h>
#include <iostream>

#include "Except.h"

using namespace std;

/*!
* \class CGrille
* \brief Cette classe permet de cr�er des objets qui seront les grilles de Sudoku.
*/
class CGrille {
	private : 
		unsigned int ** ppuiGRIGrille; /*!< Un tableau d'entier � 2 dimensions �tant la grille de Sudoku. */
		unsigned int uiGRITaille; /*!< La taille de la grille. */

	public:
		/*!
		* \brief Constructeur par d�fault de la classe CGrille.
		* \param void
		*/
		CGrille(void);

		/*!
		* \brief Constructeur de recopie de la classe CGrille.
		* \param GRIUnSudoku L'objet de la classe CGrille � recopier.
		*/
		CGrille(CGrille & GRIUnSudoku);

		/*!
		* \brief Constructeur de la classe CGrille.
		* \param ppuiUneGrille Une grille de Sudoku.
		* \param uiUneTaille La taille de la grille.
		*/
		CGrille(unsigned int ** uiUneGrille, unsigned int uiUneTaille);

		/*!
		* \brief Destructeur de la classe CGrille.
		* \param void
		*/
		~CGrille(void);

		/* Ajout des getters et setters manquants pour les tests */
		unsigned int ** GRILireGrille(void) { return ppuiGRIGrille; }

		void GRIModifierGrille(unsigned int ** ppuiGrille) { ppuiGRIGrille = ppuiGrille; }

		void GRIModifierTaille(unsigned int uiTaille) { uiGRITaille = uiTaille; }

		/*!
		* \brief Fonction permettant de lire la taille de la grille.
		* \param void
		* \return La taille de la grille.
		*/
		unsigned int GRILireTaille(void);

		/*!
		* \brief Fonction permettant de lire la valeur d'une case de la grille.
		* \param uiLigne La ligne de la case � lire.
		* \pram uiColonne La colonne de la ligne � lire.
		* \return La valeur se trouvant � la ligne uiLigne et � la colonne uiColonne.
		*/
		unsigned int GRILireValeur(unsigned int uiLigne, unsigned int uiColonne);

		/*!
		* \brief Fonction permettant de modifier une valeur d'une case de la grille.
		* \param uiLigne La ligne de la case � modifier.
		* \param uiColonne La colonne de la case � modifier.
		* \param uiValeur La valeur � ins�rer dans la case.
		* \return void
		*/
		void GRIModifierValeur(unsigned int uiLigne, unsigned int uiColonne, unsigned int uiValeur);

		/*!
		* \brief Fontion permettant de r�cup�rer le num�ro de la zone dans laquelle se trouve une case.
		* \param uiLigne La ligne de la case.
		* \param uiColonne La colonne de la casse.
		* \return Le num�ro de la zone o� se trouve la case.
		*/
		unsigned int GRIRecupererZone(unsigned int uiLigne, unsigned int uiColonne);

		/*!
		* \brief Fonction permettant d'afficher la grille � l'�cran.
		* \param void
		* \return void
		*/
		void GRIAfficherGrille(void);

};

#endif