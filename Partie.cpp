#include <stdlib.h>
#include <windows.h>
#include <iostream>

#include "Partie.h"
#include "ControleurGrille.h"
#include "Grille.h"

using namespace std;

CPartie::CPartie() {
	pGRIGrille = pGRIGrilleOrigine = NULL;
	uiGRITaille = 0;
	uiGRICasesRemplies = uiGRINbCoups = 0;
}

CPartie::CPartie(CPartie & PARUnePartie) {
	pGRIGrille = new CGrille(*PARUnePartie.pGRIGrille);
	pGRIGrilleOrigine = new CGrille(*PARUnePartie.pGRIGrilleOrigine);
	uiGRITaille = PARUnePartie.uiGRITaille;
	uiGRICasesRemplies = PARUnePartie.uiGRICasesRemplies;
	uiGRINbCoups = 0;
}

CPartie::CPartie(CGrille * pGRIUneGrille) {
	pGRIGrille = new CGrille(*pGRIUneGrille);
	pGRIGrilleOrigine = new CGrille(*pGRIUneGrille);
	uiGRITaille = pGRIUneGrille->GRILireTaille();
	uiGRICasesRemplies = PARCompterCasesOrigine();
	uiGRINbCoups = 0;
}

unsigned int * CPartie::PARDemanderCoordonnees() {
	unsigned int uiCoord[2];
	bool bContinuerX = 0;
	bool bContinuerY = 0;

	cout << "Veuillez entrer les coordonnees de la case a modifier :" << endl;
	while (bContinuerX == 0 || bContinuerY == 0) {
		cout << "Ligne : ";
		cin >> uiCoord[0];
		uiCoord[0] -= 1;
		if (uiCoord[0] >= 0 && uiCoord[0] < uiGRITaille) 
			bContinuerX = 1;
		cout << "Colonne : ";
		cin >> uiCoord[1];
		uiCoord[1] -= 1;
		if (uiCoord[1] >= 0 && uiCoord[1] < uiGRITaille) 
			bContinuerY = 1;
		if (bContinuerX != 0 && bContinuerY != 0) {
			if (PARVerifierCoordonneesGrilleOrigine(uiCoord[0], uiCoord[1]) == 0) {
				cout << "Coordonnees de la grille d'origine !" << endl;
				bContinuerX = bContinuerY = 0;
			}
		}
		if (bContinuerX == 0 || bContinuerY == 0)
			cout << "Erreur, veuillez recommencer !" << endl << endl;
	}

	return uiCoord;
}

unsigned int CPartie::PARDemanderValeur() {
	unsigned int uiValeur;
	bool bContinuer = 0;

	while (bContinuer == 0) {
	cout << "Valeur a ajouter : ";
	cin >> uiValeur;
	if (uiValeur > 0 && uiValeur <= uiGRITaille)
		bContinuer = 1;
	else
		cout << "Erreur, veuillez recommencer !" << endl << endl;
	}

	return uiValeur;
}

bool CPartie::PARVerifierCoordonneesGrilleOrigine(unsigned int uiLigne, unsigned int uiColonne) {
	if (pGRIGrilleOrigine->GRILireValeur(uiLigne, uiColonne) == 0)
		return true;
	return false;
}

bool CPartie::PARVerifierAvancement() {
	if (uiGRICasesRemplies == uiGRITaille * uiGRITaille)
		return false;
	return true;
}

void CPartie::PARReinitialiserGrille() {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2)
			pGRIGrille->GRIModifierValeur(uiBoucle, uiBoucle2, pGRIGrilleOrigine->GRILireValeur(uiBoucle, uiBoucle2));
}

void CPartie::PARAfficherStatistiques() {
	cout << endl;
	cout << "Voici les statistiques de la partie en cours :" << endl;
	cout << "Cases remplies : " << uiGRICasesRemplies << "/" << uiGRITaille * uiGRITaille << endl;
	cout << "Nombre de coups : " << uiGRINbCoups << endl;
	cout << endl;
}

unsigned int CPartie::PARCompterCasesOrigine() {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;
	unsigned int uiNb = 0;

	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2)
			if (pGRIGrilleOrigine->GRILireValeur(uiBoucle, uiBoucle2) != 0)
				++uiNb;
	return uiNb;
}

void CPartie::PARJouer() {
	bool bContinuer = 1;
	unsigned int uiChoix = 1;
	
	cout << "Bienvenue sur notre jeu du Sudoku" << endl << "Vous allez jouer une partie" << endl;
	cout << endl << "Voici votre grille de jeu :" << endl;
	PARAfficherGrilleAvecCouleurs();
	cout << endl;
	while (uiChoix == 1 && bContinuer == 1) {
		cout << endl << "Que souhaitez-vous faire ?" << endl;
		cout << "1 : Placer un numero sur la grille" << endl;
		cout << "2 : Reinitialiser la grille" << endl;
		cout << "3 : Afficher les statistiques de la partie" << endl;
		cin >> uiChoix;
		if (uiChoix == 2) {
			PARReinitialiserGrille();
			cout << "La grille a ete reinitialisee !" << endl << endl;
			PARAfficherGrilleAvecCouleurs();
			cout << endl;
			uiChoix = 1;
		}
		else {
			if (uiChoix == 3)
				PARAfficherStatistiques();
			uiChoix = 1;
		}
		unsigned int * uiCoord = PARDemanderCoordonnees();
		unsigned int uiLigne = uiCoord[0];
		unsigned int uiColonne = uiCoord[1];
		cout << "Vous avez choisit les coordonnees (" << uiLigne + 1 << ", " << uiColonne + 1 << ")";
		cout << ", contenant la valeur : " << pGRIGrille->GRILireValeur(uiLigne, uiColonne) << "." << endl;
		CControleurGrille CGRControleur1(pGRIGrille);
		unsigned int uiValeur = PARDemanderValeur();
		cout << "Vous souhaitez inserer la valeur " << uiValeur << endl;
		if (CGRControleur1.CGRModifierCase(uiLigne, uiColonne, uiValeur) == 1) {
			pGRIGrille->GRIModifierValeur(uiLigne, uiColonne, uiValeur);
			++uiGRICasesRemplies;
			++uiGRINbCoups;
			cout << "Voici la nouvelle grille de jeu apres insertion de la valeur " << uiValeur;
			cout << " aux cordonnees (" << uiLigne + 1 << ", " << uiColonne + 1 << ")." << endl;
			PARAfficherGrilleAvecCouleurs();
			cout << endl;
			bContinuer = PARVerifierAvancement();
		}
		else {
			cout << "Vous defiez les regles du Sudoku !" << endl;
			cout<< "Impossible d'ajouter la valeur !" << endl;
		}
	}
	cout << endl << "Bravo, la grille a ete resolue !" << endl;
}

void CPartie::PARChargerPartie() {

}

void CPartie::PARSauvegarderPartie() {

}

void CPartie::PARAfficherGrilleAvecCouleurs() {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	// Change la couleur d'affichage dans la console
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int iCouleur;

	cout << endl;
	for (uiBoucle = 0; uiBoucle < uiGRITaille; ++uiBoucle) {
		if (uiBoucle == 3 || uiBoucle == 6)
			cout << "----------------------------" << endl;
		for (uiBoucle2 = 0; uiBoucle2 < uiGRITaille; ++uiBoucle2) {
			if (pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2) == pGRIGrilleOrigine->GRILireValeur(uiBoucle, uiBoucle2) && pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2)) {
				iCouleur = 12;
				SetConsoleTextAttribute(hConsole, iCouleur);
			}
			cout << pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2);
			iCouleur = 7;
			SetConsoleTextAttribute(hConsole, iCouleur);
			if (uiBoucle2 != uiGRITaille - 1)
				cout << " ";
			if (uiBoucle2 == 2 || uiBoucle2 == 5)
				cout << "|";
			if (uiBoucle2 != uiGRITaille - 1)
				cout << " ";
		}
		if (uiBoucle != uiGRITaille - 1)
			cout << endl;
	}
	cout << endl;
}