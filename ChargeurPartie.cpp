#include "ChargeurPartie.h"
#include "dirent.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

CChargeurPartie::CChargeurPartie(void) {
	bCHPNouvellePartie = 1;
}

string CChargeurPartie::CHPRecupererNomJoueur() {
	return sCHPNomJoueur;
}

bool CChargeurPartie::CHPRecupererEtatPartie() {
	return bCHPNouvellePartie;
}

void CChargeurPartie::CHPMenuPrincipal() {
	unsigned int uiChoice = 0;
	string sNomJoueur;

	cout << "Bienvenue sur notre jeu du Sudoku" << endl;
	while (uiChoice == 0) {
		cout << "### MENU PRINCIPAL ###" << endl;
		cout << "Que souhaitez-vous faire ?" << endl;
		cout << "1 - Jouer une nouvelle partie" << endl;
		cout << "2 - Charger une partie existante" << endl;
		cin >> uiChoice;
		switch (uiChoice) {
			case 1 :
				CHPNouvellePartie();
				break;
			case 2 :
				bCHPNouvellePartie = 0;
				CHPChargerPartie();
				break;
			default :
				uiChoice = 0;
				break;
		}
	}
}

void CChargeurPartie::CHPNouvellePartie() {
	cout << "Quel est votre nom de joueur ?" << endl;
	cin >> sCHPNomJoueur;
	cout << sCHPNomJoueur;
	cin.ignore(); // On vide le buffer au cas ou l'utilisateur a entre un pseudo avec espace.
}

unsigned int CChargeurPartie::CHPCompterNombreFichiers(DIR * dUnRepertoire) {
	unsigned int uiNbFichiers = 0;

	// On compte le nombre de fichier présent dans le répertoire de sauvegarde de parties
	if (dUnRepertoire != NULL) {
		struct dirent * ent;
		while ((ent = readdir(dUnRepertoire)) != NULL)
			++uiNbFichiers;
		closedir(dUnRepertoire);
	}

	return uiNbFichiers;
}

void CChargeurPartie::CHPChargerPartie() {
	DIR * dRep = opendir("./Parties/");
	unsigned int uiNbFichiers = CHPCompterNombreFichiers(dRep);
	
	// On ignore les deux premiers fichiers : '.' et '..'
	if (uiNbFichiers > 2) {
		unsigned int uiNbStrings = uiNbFichiers - 2;
		string * psParties;
		psParties = new string[uiNbStrings];
		
		cout << endl << "Il y a " << uiNbStrings << " parties sauvegardees : " << endl << endl;
		uiNbFichiers = 0;
		uiNbStrings = 0;
		dRep = opendir("./Parties/");
		if (dRep != NULL) {
			struct dirent * ent;
			while ((ent = readdir(dRep)) != NULL) {
				if (uiNbFichiers > 1) {
					psParties[uiNbStrings] = ent->d_name;
					++uiNbStrings;
				}
				++uiNbFichiers;
			}
			closedir(dRep);
		}

		// On affiche le contenu du tableau contenant le nom des parties
		unsigned int uiBoucle;
		for (uiBoucle = 0; uiBoucle < uiNbStrings; ++ uiBoucle)
			cout << uiBoucle + 1 << " : " << psParties[uiBoucle] << endl;

		// On recupere l'indice du fichier que l'utilisateur veut charger
		unsigned int uiNumFichier = 0;
		cout << endl << "Quel est le numero de la partie a charger ?" << endl;
		cin >> uiNumFichier;
		cin.clear();
		cout << "Vous avez choisit de generer la partie : " << psParties[uiNumFichier - 1] << endl;
		// Generer la partie a l'aide du parseur
	}
	else {
		cout << endl << "Aucune partie sauvegardee !" << endl << endl;
		CHPMenuPrincipal();
	}
}

// Utile ?
CPartie * CChargeurPartie::CHPLireFichier(char * pcChemin) {
	return NULL;
}