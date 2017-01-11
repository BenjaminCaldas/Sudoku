/*!
* \file ControleurGrille.h
* \author Benjamin Caldas
* \brief Le fichier d'en-tête de la classe CControleurGrille.
*/
#ifndef CCONTROLEURGRILLE_H
#define CCONTROLEURGRILLE_H

#include <stdlib.h>
#include <iostream>

#include "Except.h"
#include "Grille.h"

using namespace std;

/*!
* \class CControleurGrille
* \brief Cette classe permet de créer des objets qui permettent de vérifier que les règles du Sudoku sont bien respectées.
*/
class CControleurGrille {
	private :
		CGrille * pGRIGrille; /*!< Un pointeur sur l'objet de la classe CGrille à vérifier. */

	public :
		/*!
		* \brief Constructeur par défault de la classe CControleurGrille.
		* \param void
		*/
		CControleurGrille(void);

		/*!
		* \brief Constructeur de recopie de la classe CControleurGrille.
		* \param CGRUnControleur L'objet de la classe CControleurGrille à recopier.
		*/
		CControleurGrille(CControleurGrille & CGRUnControleur);

		/*!
		* \brief Constructeur de la classe CControleurGrille.
		* \param GRIUneGrille L'objet de la classe CGrille à contrôler.
		*/
		CControleurGrille(CGrille * GRIUneGrille);

		/*!
		* \brief Fonction permettant de vérifier si une valeur peut ou non être insérée sur une ligne de la grille de Sudoku.
		* \param uiNo La valeur à insérer.
		* \param uiNoLigne La ligne sur laquelle l'on souhaite insérer la valeur.
		* \return Un boolean valant 1 si l'on peut insérer la valeur, 0 sinon.
		*/
		bool CGRVerifierLigne(unsigned int uiNo, unsigned int uiNoLigne);

		/*!
		* \brief Fonction permettant de vérifier si une valeur peut ou non être insérée sur une colonne de la grille de Sudoku.
		* \param uiNo La valeur à insérer.
		* \param uiNoColonne La colonne sur laquelle l'on souhaite insérer la valeur.
		* \return Un boolean valant 1 si l'on peut insérer la valeur, 0 sinon.
		*/
		bool CGRVerifierColonne(unsigned int uiNo, unsigned int uiNoColonne);

		/*!
		* \brief Fonction permettant de vérifier si une valeur peut ou non être insérée dans une zone de la grille de Sudoku.
		* \param uiNo La valeur à insérer.
		* \param uiNoZone La zone dans laquelle l'on souhaite insérer la valeur.
		* \return Un boolean valant 1 si l'on peut insérer la valeur, 0 sinon.
		*/
		bool CGRVerifierZone(unsigned int uiNo, unsigned int uiNoZone);

		/*!
		* \brief Fonction permettant de savoir si une case est disponible ou non.
		* \param uiNoLigne La ligne où se trouve de cette case.
		* \param uiNoColonne La colonne où se trouve cette case
		* \return Un boolean valant 1 si la case est vide (la case contient un 0), 0 si elle est occupée (la cas contient une autre valeur).
		*/
		bool CGRVerifierDisponibiliteCase(unsigned int uiNoLigne, unsigned int uiNoColonne);

		/*!
		* \brief Cette fonction permet de vérifier si les 3 contraintes des trois dernières fonctions sont respectées en même temps, afin d'insérer une valeur dans la grille.
		* \param uiLigne Le numéro de la ligne où l'on souhaite insérer la valeur.
		* \param uiColonne Le numéro de la colonne où l'on souhaite insérer la valeur.
		* \param uiValeur La valeur à insérer.
		* \return Un boolean valant 1 si les 3 contraintes sont respectées, 0 si une ou plusieurs des 3 contraintes ne l'est pas.
		*/
		bool CGRModifierCase(unsigned int uiLigne, unsigned int uiColonne, unsigned int uiValeur);

		/*!
		* \brief Cette fonction permet de compter le nombre de cases étant remplies dans la grille, c'est à dire possédant une valeur autre que 0.
		* \param void
		* \return Le nombre de cases étant remplies.
		*/
		unsigned int CGRCompterCasesRemplies(void);
};

#endif
