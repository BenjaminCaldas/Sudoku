/*!
* \file Solveur.h
* \author Benjamin Caldas
* \brief Le fichier d'en-tête de la classe CSolveur.
*/
#ifndef CSOLVEUR_H
#define CSOLVEUR_H

#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "Grille.h"
#include "ControleurGrille.h"

using namespace std;

/*!
* \class CSolveur
* \brief Cette classe permet de resoudre une grille de Sudoku en utilisant le backtracking, un algorithme de force brute.
*/
class CSolveur {
	private :
		CGrille * pGRIGrille; /*!< Un pointeur sur la grille à résoudre. */
		long unsigned int luiSLVTempsResolution; /*!< Le temps de résolution que va mettre le solveur. */
		long unsigned int luiSLVNbNumerosTestes; /*!< Le nombre de numéros testés par le solveur. */

	public:
		/*!
		* \brief Constructeur par défault de la classe CSolveur.
		* \param void
		*/
		CSolveur(void);

		/*!
		* \brief Constructeur de recopie de la classe CSolveur.
		* \param SLVSolveur Une référence vers un objet de la classe CSolveur.
		*/
		CSolveur(CSolveur & SLVSolveur);

		/*!
		* \brief Constructeur de la classe CSolveur.
		* \param GRIUneGrille Un objet de la classe CGrille qui sera la grille à résoudre.
		*/
		CSolveur(CGrille * GRIUneGrille);

		/*!
		* \brief Fonction récursive permettant de résoudre une grille de Sudoku par backtracking, un algorithme de force brute.
		* \param uiPosition La position du résolveur sur la grille de Sudoku.
		* \return Un boolean qui vaut 1 si le numéro placé est valide, 0 sinon.
		*/
		bool SLVEstValide(unsigned int uiPosition);

		/*!
		* \brief Fonction qui lance la résolution de la grille de Sudoku et qui stocke les statistiques de cette résolution.
		* \param void
		* \return void
		*/
		void SLVResoudre(void);

		/*!
		* \brief Fonction qui affiche les statistiques de la résolution.
		* \param void
		* \return void
		*/
		void SLVAfficherStatistiques(void);
};

#endif