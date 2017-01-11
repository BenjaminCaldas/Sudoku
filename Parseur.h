/*!
* \file Parseur.h
* \author Benjamin Caldas
* \brief Le fichier d'en-tête de la classe CParseur.
*/
#ifndef CPARSEUR_H
#define CPARSEUR_H

#include <iostream>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Except.h"

#define TAILLE_MAX_ATTRIBUT 100 /*!< La taille maximale d'un attribut dans le fichier .txt. */
#define TAILLE_MAX_VALEUR 100 /*!< La taille maximale de la valeur associee dans le fichier .txt. */

using namespace std;

/*!
* \class CParseur
* \brief Cette classe permet de créer des objets qui pourront parser des fichier .txt au format "attribut=valeur".
*/
class CParseur {
	private:
		ifstream fichier; /*!< Le flux représentant le fichier à parser. */
		char * pcPARAttribut; /*!< La chaîne de caractere stockant l'attribut. */
		char * pcPARValeur; /*!< La chaîne de caractère stockant la valeur associée à l'attribut. */

	public:
		/*!
		* \brief Constructeur de la classe CParseur.
		* \param sChemin Le chemin du fichier à parser.
		*/
		CParseur(string sChemin);

		/*!
		* \brief Destructeur de la classe CParseur.
		* \param void
		*/
		~CParseur(void);

		/*!
		* \brief Fonction permettant de lire la valeur d'une ligne du fichier.
		* \param void
		* \return La valeur d'une ligne du fichier.
		*/
		char * PARLireValeur(){return pcPARValeur;}

		/*!
		* \brief Fonction permettant de lire l'attribut d'une ligne du fichier.
		* \param void
		* \return L'attribut d'une ligne du fichier.
		*/
		char * PARLireAttribut(){return pcPARAttribut;}

		/*!
		* \brief Fonction permettant de modifier le chemin du fichier à parser.
		* \param pcChemin Le nouveau chemin du fichier à parser.
		* \return void
		*/
		void PARModifierFichier(char * pcChemin);

		/*!
		* \brief Fonction permettant de lire une ligne du fichier à parser.
		* \param void
		* \return void
		*/
		void PARLireLigne(void);

		/*!
		* \brief Fonction permettant de parser une valeur du fichier.
		* \param void
		* \return void
		*/
		void PARParseValeur(void);

		/*!
		* \brief Fonction permettant de parser un attribut du fichier.
		* \param void
		* \return void
		*/
		void PARParseAttribut(void);
};

#endif
