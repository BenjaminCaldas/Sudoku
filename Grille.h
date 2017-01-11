/**
* \file Grille.h
* \author Benjamin Caldas
* \brief Le fichier d'en-tête de la classe CGrille.
*/
#ifndef CGRILLE_H
#define CGRILLE_H

#include <stdlib.h>
#include <iostream>

using namespace std;

/*!
* \class CGrille
* \brief Cette classe permet de créer des objets qui seront les grilles de Sudoku.
*/
class CGrille {
	private : 
		unsigned int ** ppuiGRIGrille; /*!< Un tableau d'entier à 2 dimensions étant la grille de Sudoku. */
		unsigned int uiGRITaille; /*!< La taille de la grille. */

	public:
		/*!
		* \brief Constructeur par défault de la classe CGrille.
		* \param void
		*/
		CGrille(void);

		/*!
		* \brief Constructeur de recopie de la classe CGrille.
		* \param GRIUnSudoku L'objet de la classe CGrille à recopier.
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

		/*!
		* \brief Fonction permettant de lire la taille de la grille.
		* \param void
		* \return La taille de la grille.
		*/
		unsigned int GRILireTaille(void);

		/*!
		* \brief Fonction permettant de lire la valeur d'une case de la grille.
		* \param uiLigne La ligne de la case à lire.
		* \pram uiColonne La colonne de la ligne à lire.
		* \return La valeur se trouvant à la ligne uiLigne et à la colonne uiColonne.
		*/
		unsigned int GRILireValeur(unsigned int uiLigne, unsigned int uiColonne);

		/*!
		* \brief Fonction permettant de modifier une valeur d'une case de la grille.
		* \param uiLigne La ligne de la case à modifier.
		* \param uiColonne La colonne de la case à modifier.
		* \param uiValeur La valeur à insérer dans la case.
		* \return void
		*/
		void GRIModifierValeur(unsigned int uiLigne, unsigned int uiColonne, unsigned int uiValeur);

		/*!
		* \brief Fontion permettant de récupérer le numéro de la zone dans laquelle se trouve une case.
		* \param uiLigne La ligne de la case.
		* \param uiColonne La colonne de la casse.
		* \return Le numéro de la zone où se trouve la case.
		*/
		unsigned int GRIRecupererZone(unsigned int uiLigne, unsigned int uiColonne);

		/*!
		* \brief Fonction permettant d'afficher la grille à l'écran.
		* \param void
		* \return void
		*/
		void GRIAfficherGrille(void);

};

#endif