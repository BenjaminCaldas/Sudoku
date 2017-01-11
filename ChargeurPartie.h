/*!
* \file ChargeurPartie.h
* \author Benjamin Caldas
* \brief Le fichier d'en-tête de la classe CChargerPartie.
*/
#ifndef CCHARGEURPARTIE_H
#define CCHARGEURPARTIE_H

#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>

#include "dirent.h"
#include "Partie.h"
#include "Parseur.h"

#define NB_LIGNES_PARTIE 7
#define NB_LIGNES_GRILLE 3

using namespace std;

/*!
* \class CChargeurPartie
* \brief Cette classe permet de créer des objets qui pourront créer une nouvelle partie de Sudoku ou charger des parties existantes.
*/
class CChargeurPartie {
	private :
		string sCHPNomJoueur; /*!< Le nom du joueur de la partie. */

	public:
		/**
		* \brief Constructeur par défault de la classe CChargeurPartie.
		* \param void
		*/
		CChargeurPartie(void);

		/**
		* \brief Fonction permettant de récupérer le nom du joueur d'une partie de Sudoku.
		* \param void
		* \return Le nom du joueur.
		*/
		string CHPRecupererNomJoueur(void);

		/**
		* \brief Fonction affichant le menu principal et récupérant une nouvelle partie ou une partie chargée.
		* \param void
		* \return Un pointeur sur un objet de la classe CPartie.
		*/
		CPartie * CHPMenuPrincipal(void);

		/**
		* \brief Fonction permettant de créer une nouvelle partie et de créer un objet de la classe CPartie.
		* \param void
		* \return Un pointeur sur un objet de la classe CPartie.
		*/
		CPartie * CHPNouvellePartie(void);

		/**
		* \brief Fonction permettant de compter le nombre de fichiers présents dans un répertoire. Attention, les deux premiers seront toujours '.' et '..'.
		* \param dUnRepertoire Le répertoire à analyser.
		* \return le nombre de fichier présents dans ce répertoire.
		*/
		unsigned int CHPCompterNombreFichiers(DIR * dUnRepertoire);

		/**
		* \brief Fonction permettant de charger une partie existante et de créer un objet de la classe CPartie.
		* \param void
		* \return Un pointeur sur un objet de la classe CPartie.
		*/
		CPartie * CHPChargerPartie(void);

		/**
		* \brief Fonction permettant de lire un fichier contenant les informations d'une partie sauvegardées. Un objet de la classe CPartie et ensuite créé grâce à ces informations.
		* \param sChemin Le chemin du fichier de sauvegarde de la partie.
		* \return Un pointeur sur un objet de la classe CPartie.
		*/
		CPartie * CHPLireFichier(string sChemin);
};

#endif
