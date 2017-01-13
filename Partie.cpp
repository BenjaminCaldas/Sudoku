/**
* \file Partie.cpp
* \author Benjamin Caldas
* \brief Le fichier source de la classe CPartie.
*/
#include "Partie.h"

CPartie::CPartie() {
	pGRIGrille = pGRIGrilleOrigine = NULL;
	uiPARTaille = 0;
	uiPARCasesRemplies = uiPARNbCoups = 0;
	bPARStatut = 0;
}

CPartie::CPartie(CPartie & PARUnePartie) {
	pGRIGrille = new CGrille(*PARUnePartie.pGRIGrille);
	pGRIGrilleOrigine = new CGrille(*PARUnePartie.pGRIGrilleOrigine);
	uiPARTaille = PARUnePartie.uiPARTaille;
	uiPARCasesRemplies = PARUnePartie.uiPARCasesRemplies;
	uiPARNbCoups = 0;
	bPARStatut = 0;
}

CPartie::CPartie(CGrille * pGRIUneGrille, string sNomJoueur) {
	pGRIGrille = new CGrille(*pGRIUneGrille);
	pGRIGrilleOrigine = new CGrille(*pGRIUneGrille);
	uiPARTaille = pGRIUneGrille->GRILireTaille();
	sPARNomJoueur = sNomJoueur;
	uiPARCasesRemplies = PARCompterCasesOrigine();
	uiPARNbCoups = 0;
	bPARStatut = 0;
}

CPartie::CPartie(CGrille * pGRIUneGrille, CGrille * pGRIUneGrilleOrigine, unsigned int uiUneTaille, string sNomJoueur, unsigned int uiLesCasesRemplies, unsigned int uiUnNbCoups, bool bUnStatut) {
	pGRIGrille = new CGrille(*pGRIUneGrille);
	pGRIGrilleOrigine = new CGrille(*pGRIUneGrilleOrigine);
	uiPARTaille = uiUneTaille;
	sPARNomJoueur = sNomJoueur;
	uiPARCasesRemplies = uiLesCasesRemplies;
	uiPARNbCoups = uiUnNbCoups;
	bPARStatut = bUnStatut;
}

CPartie::~CPartie() {
	if (pGRIGrille != NULL)
		delete pGRIGrille;
	if (pGRIGrilleOrigine != NULL)
		delete pGRIGrilleOrigine;
}

unsigned int * CPartie::PARDemanderCoordonnees() {
	unsigned int uiCoord[2];
	uiCoord[0] = 0;
	uiCoord[1] = 0;
	bool bContinuerX = 0;
	bool bContinuerY = 0;

	while ((uiCoord[0] == 0) || (uiCoord[1] == 0)) {
		cout << "Veuillez entrer les coordonnees de la case a modifier :" << endl;
		// On récupère la ligne
		while (uiCoord[0] == 0) {
			cout << "Ligne : ";
			// Cette condition permet de sécuriser la saisie et évite au programme de planter en cas de mauvaise saisie
			if (!(cin >> uiCoord[0]) || (uiCoord[0] < 1) || (uiCoord[0] > uiPARTaille)) { // On force l'utilisateur a entrer un entier compris entre 1 et uiPARTaille.
				cin.clear();
				cin.ignore();
				uiCoord[0] = 0;
			}
		}
		// On récupère la colonne
		while (uiCoord[1] == 0) {
			cout << "Colonne : ";
			// Cette condition permet de sécuriser la saisie et évite au programme de planter en cas de mauvaise saisie
			if (!(cin >> uiCoord[1]) || (uiCoord[1] < 1) || (uiCoord[1] > uiPARTaille)) { // On force l'utilisateur a entrer un entier compris entre 1 et uiPARTaille.
				cin.clear();
				cin.ignore();
				uiCoord[1] = 0;
			}
		}
		if (PARVerifierCoordonneesGrilleOrigine(uiCoord[0] - 1, uiCoord[1] - 1) == 0) {
				cout << "Coordonnees de la grille d'origine !" << endl;
				uiCoord[0] = 0;
				uiCoord[1] = 0;
		}
	}
	uiCoord[0] -= 1;
	uiCoord[1] -= 1;
	cout << uiCoord[0] << ", " << uiCoord[1] << endl;
	return uiCoord;
}

unsigned int CPartie::PARDemanderValeur() {
	unsigned int uiValeur = 0;

	while (uiValeur == 0) {
		cout << "Valeur a ajouter : ";
		// Cette condition permet de sécuriser la saisie et évite au programme de planter en cas de mauvaise saisie
		if (!(cin >> uiValeur) || (uiValeur < 1) || (uiValeur > uiPARTaille)) { // On force l'utilisateur a entrer un entier compris entre 1 et uiPARTaille.
				cin.clear();
				cin.ignore();
				uiValeur = 0;
			}
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
	if (uiPARCasesRemplies == uiPARTaille * uiPARTaille)
		return false;
	return true;
}

void CPartie::PARReinitialiserGrille() {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	for (uiBoucle = 0; uiBoucle < uiPARTaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiPARTaille; ++uiBoucle2)
			pGRIGrille->GRIModifierValeur(uiBoucle, uiBoucle2, pGRIGrilleOrigine->GRILireValeur(uiBoucle, uiBoucle2));

	uiPARCasesRemplies = PARCompterCasesOrigine();
	uiPARNbCoups = 0;
}

void CPartie::PARAfficherGrilleAvecCouleurs() {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	// Change la couleur d'affichage dans la console
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int iCouleur;

	cout << endl;
	for (uiBoucle = 0; uiBoucle < uiPARTaille; ++uiBoucle) {
		if (uiBoucle == 3 || uiBoucle == 6)
			cout << "----------------------------" << endl;
		for (uiBoucle2 = 0; uiBoucle2 < uiPARTaille; ++uiBoucle2) {
			if (pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2) == pGRIGrilleOrigine->GRILireValeur(uiBoucle, uiBoucle2) && pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2)) {
				iCouleur = 12;
				SetConsoleTextAttribute(hConsole, iCouleur);
			}
			cout << pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2);
			iCouleur = 7;
			SetConsoleTextAttribute(hConsole, iCouleur);
			if (uiBoucle2 != uiPARTaille - 1)
				cout << " ";
			if (uiBoucle2 == 2 || uiBoucle2 == 5)
				cout << "|";
			if (uiBoucle2 != uiPARTaille - 1)
				cout << " ";
		}
		if (uiBoucle != uiPARTaille - 1)
			cout << endl;
	}
	cout << endl;
}

void CPartie::PARAfficherStatistiques() {
	cout << endl;
	cout << "Voici les statistiques de la partie en cours :" << endl;
	cout << "Cases remplies : " << uiPARCasesRemplies << "/" << uiPARTaille * uiPARTaille << endl;
	cout << "Nombre de coups : " << uiPARNbCoups << endl;
	cout << endl;
}

unsigned int CPartie::PARCompterCasesOrigine() {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;
	unsigned int uiNb = 0;

	for (uiBoucle = 0; uiBoucle < uiPARTaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiPARTaille; ++uiBoucle2)
			if (pGRIGrilleOrigine->GRILireValeur(uiBoucle, uiBoucle2) != 0)
				++uiNb;
	return uiNb;
}

void CPartie::PARJouer() {
	bool bContinuer = 1;
	unsigned int uiChoix = 0;
	
	cout << endl << "Bonjour " << sPARNomJoueur << ", vous allez jouer une partie." << endl;
	cout << endl << "Voici votre grille de jeu :" << endl;
	PARAfficherGrilleAvecCouleurs();
	cout << endl;
	while (uiChoix == 0 && bContinuer == 1) {
		cout << endl << "Que souhaitez-vous faire ?" << endl;
		cout << "1 : Placer un numero sur la grille" << endl;
		cout << "2 : Reinitialiser la grille" << endl;
		cout << "3 : Afficher les statistiques de la partie" << endl;
		cout << "4 : Afficher la grille" << endl;
		cout << "5 : Sauvegarder la partie" << endl;
		cout << "6 : Lancer la resolution automatique" << endl;
		cout << "7 : Quitter le jeu" << endl;
		// Cette condition permet de sécuriser la saisie et évite au programme de planter en cas de mauvaise saisie
		if (!(cin >> uiChoix) || (uiChoix < 1) || (uiChoix > 7)) {
			cin.clear();
			cin.ignore();
		}
		if (uiChoix == 1) {
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
				++uiPARCasesRemplies;
				++uiPARNbCoups;
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
			uiChoix = 0;
		}
		else {
			if (uiChoix == 2) {
				PARReinitialiserGrille();
				cout << "La grille a ete reinitialisee !" << endl << endl;
				PARAfficherGrilleAvecCouleurs();
				cout << endl;
				uiChoix = 0;
			}
			else {
				if (uiChoix == 3)
					PARAfficherStatistiques();
				if (uiChoix == 4) {
					PARAfficherGrilleAvecCouleurs();
					cout << endl;
				}
				if (uiChoix == 5)
					PARSauvegarderPartie();
				if (uiChoix == 6) {
					CSolveur SLVSolveur(pGRIGrille);
					SLVSolveur.SLVResoudre();
					SLVSolveur.SLVAfficherStatistiques();
					PARAfficherGrilleAvecCouleurs();
					uiPARCasesRemplies = uiPARTaille * uiPARTaille;
					uiPARNbCoups = 0;
					bPARStatut = 1;
				}
				if (uiChoix == 7) {
					cout << endl << "A BIENTOT !" << endl;
					break;
				}
				uiChoix = 0;
			}
		}
	}
	if (PARVerifierAvancement() == 0) {
		cout << "Bravo, la grille a ete resolue !" << endl;
		bPARStatut = 1;
	}
}

void CPartie::PARSauvegarderPartie() {
	string sNomFichier = "./Parties/" + sPARNomJoueur + ".txt";
	ofstream oFichier(sNomFichier.c_str());

	if (oFichier) {
		oFichier << "Nom_Joueur=" << sPARNomJoueur << endl;
		oFichier << "Cases_Remplies=" << uiPARCasesRemplies << endl;
		oFichier << "Nb_Coups=" << uiPARNbCoups << endl;
		oFichier << "Taille_Grille=" << uiPARTaille << endl;
		oFichier << "Statut=";
		if (bPARStatut == 0)
			oFichier << "En_Cours";
		else
			oFichier << "Resolue";
		oFichier << endl;

		unsigned int uiBoucle;
		unsigned int uiBoucle2;

		oFichier << "Grille_Origine=";
		for (uiBoucle = 0; uiBoucle < uiPARTaille; ++ uiBoucle)
			for (uiBoucle2 = 0; uiBoucle2 < uiPARTaille; ++uiBoucle2)
				oFichier<< pGRIGrilleOrigine->GRILireValeur(uiBoucle, uiBoucle2);
		oFichier << endl;
		oFichier << "Grille=";
		for (uiBoucle = 0; uiBoucle < uiPARTaille; ++ uiBoucle)
			for (uiBoucle2 = 0; uiBoucle2 < uiPARTaille; ++uiBoucle2)
				oFichier << pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2);
		oFichier << endl;
		
		cout << sNomFichier << " a ete sauvegarde ! " << endl;
	}
	else {
		// Lever Exception
		cout << "Erreur d'ouverture !" << endl;
	}
}