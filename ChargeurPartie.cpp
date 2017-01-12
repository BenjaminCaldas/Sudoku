/**
* \file ChargeurPartie.cpp
* \author Benjamin Caldas
* \brief Le fichier source de la classe CChargeurPartie.
*/
#include "ChargeurPartie.h"

CChargeurPartie::CChargeurPartie(void) {
}

string CChargeurPartie::CHPRecupererNomJoueur(void) {
	return sCHPNomJoueur;
}

CPartie * CChargeurPartie::CHPMenuPrincipal(void) {
	unsigned int uiChoice = 0;
	CPartie * PARPartie = NULL;
	string sNomJoueur;

	cout << "Bienvenue sur notre jeu du Sudoku" << endl;
	while (uiChoice == 0) {
		cout << "### MENU PRINCIPAL ###" << endl;
		cout << "Que souhaitez-vous faire ?" << endl;
		cout << "1 - Jouer une nouvelle partie" << endl;
		cout << "2 - Charger une partie existante" << endl;
		// Cette condition permet de sécuriser la saisie et évite au programme de planter en cas de mauvaise saisie
		if (!(cin >> uiChoice)) {
			cin.clear();
			cin.ignore();
		}
		switch (uiChoice) {
			case 1 :
				PARPartie = CHPNouvellePartie();
				break;
			case 2 :
				PARPartie = CHPChargerPartie();
				break;
			default :
				uiChoice = 0; // Tant que l'utilisateur n'a pas rentre 1 ou 2, on boucle
				break;
		}
	}
	return PARPartie;
}

CPartie * CChargeurPartie::CHPNouvellePartie(void) {
	char pseudo[64];
	cout << "Quel est votre nom de joueur ?" << endl;
	cin.ignore(1024, '\n'); // Vidage du buffer
    cin.getline(pseudo, sizeof(pseudo)); // On préfère getnline à cin pour sécuriser la saisie et éviter au programme de planter si l'on entre un espace
	sCHPNomJoueur = pseudo;
	cout << sCHPNomJoueur;

	// Generer une grille dans le dossier ./Grilles/
	DIR * dRep = opendir("./Grilles/");
	unsigned int uiNbFichiers = 0;
	if (dRep != NULL)
		uiNbFichiers = CHPCompterNombreFichiers(dRep);
	else {
		// Lever exception (erreur ouverture répertoire)
		throw CExcept(EXC_REP_OUV_ERR);
	}
	if (uiNbFichiers - 2 != 0) {
		cout << endl << "Generation d'un grille parmi les " << uiNbFichiers - 2 << " existantes ..." << endl;

		// Generation d'un nombre aleatoire
		srand(time(NULL));
		unsigned int uiNumGrilleAleatoire = rand() % (uiNbFichiers - 2) + 1;

		// Ouverture du fichier correspondant au numero de la grille
		string sNomFichier = "./Grilles/Grille";
		string sNumFichier = to_string(uiNumGrilleAleatoire);
		string sExtension = ".txt";
		string sChemin = sNomFichier + sNumFichier + sExtension;

		// On parse le fichier
		CParseur PARParseur(sChemin);
		string sProprietes[NB_LIGNES_GRILLE];
		unsigned int uiNbLigne;

		for (uiNbLigne = 0; uiNbLigne < NB_LIGNES_GRILLE; ++uiNbLigne) {
			PARParseur.PARLireLigne();
			sProprietes[uiNbLigne] = PARParseur.PARLireValeur();
		}

		// On recupere les valeurs dans le bon type
		unsigned int uiCasesRemplies = stoul(sProprietes[0], nullptr, 0); 
		unsigned int uiTailleGrille = stoul(sProprietes[1], nullptr, 0);

		// Recuperation de la grille
		unsigned int uiBoucle;
		unsigned int uiBoucle2;
		unsigned int uiNumCaractere = 0;
		unsigned int ** ppuiGrille = new unsigned int * [uiTailleGrille];

		for (uiBoucle = 0; uiBoucle < uiTailleGrille; ++uiBoucle)
			ppuiGrille[uiBoucle] = new unsigned int [uiTailleGrille];

		for (uiBoucle = 0; uiBoucle < uiTailleGrille; ++uiBoucle)
			for (uiBoucle2 = 0; uiBoucle2 < uiTailleGrille; ++uiBoucle2) {
				ppuiGrille[uiBoucle][uiBoucle2] = sProprietes[2][uiNumCaractere] - '0';
				++uiNumCaractere;
			}

		// Creation de l'objet de la classe Partie
		CGrille GRIGrille(ppuiGrille, uiTailleGrille);
		CPartie * PARNouvellePartie = new CPartie(&GRIGrille, sCHPNomJoueur);

		// On libere la memoire
		for (uiBoucle = 0; uiBoucle < uiTailleGrille; ++uiBoucle)
			delete [] ppuiGrille[uiBoucle];
		delete [] ppuiGrille;
		return PARNouvellePartie;
	}
	else {
		cout << endl << "Aucune grille dans le repertoire" << endl;
		return NULL;
	}
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

CPartie *  CChargeurPartie::CHPChargerPartie(void) {
	CPartie * PARPartie = NULL;
	DIR * dRep = opendir("./Parties/");
	unsigned int uiNbFichiers = 0;
	if (dRep != NULL)
		uiNbFichiers = CHPCompterNombreFichiers(dRep);
	else {
		// Lever exception (erreur ouverture répertoire)
		throw CExcept(EXC_REP_OUV_ERR);
	}
	
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
		else {
			// Lever exception (erreur ouverture répertoire)
			throw CExcept(EXC_REP_OUV_ERR);
		}

		// On affiche le contenu du tableau contenant le nom des parties
		unsigned int uiBoucle;
		for (uiBoucle = 0; uiBoucle < uiNbStrings; ++ uiBoucle)
			cout << uiBoucle + 1 << " : " << psParties[uiBoucle] << endl;

		// On recupere l'indice du fichier que l'utilisateur veut charger
		unsigned int uiNumFichier = 0;
		while (uiNumFichier == 0) {
			cout << endl << "Quel est le numero de la partie a charger ?" << endl;
			// Cette condition permet de sécuriser la saisie et évite au programme de planter en cas de mauvaise saisie
			if (!(cin >> uiNumFichier) || (uiNumFichier < 1) || (uiNumFichier > uiNbStrings)) { 
				cin.clear();
				cin.ignore();
				uiNumFichier = 0;
			}
		}
		cout << "Vous avez choisit de generer la partie : " << psParties[uiNumFichier - 1] << endl;
		PARPartie = CHPLireFichier("./Parties/" + psParties[uiNumFichier - 1]);
		delete [] psParties;
	}
	else {
		cout << endl << "Aucune partie sauvegardee !" << endl << endl;
		CHPMenuPrincipal();
	}
	return PARPartie;
}

CPartie * CChargeurPartie::CHPLireFichier(string sChemin) {
	CParseur PARParseur(sChemin);
	string sProprietes[NB_LIGNES_PARTIE];
	unsigned int uiNbLigne;

	for (uiNbLigne = 0; uiNbLigne < NB_LIGNES_PARTIE; ++uiNbLigne) {
		PARParseur.PARLireLigne();
		sProprietes[uiNbLigne] = PARParseur.PARLireValeur();
	}

	// On convertie les attributs dans le bon type afin de creer un objet Partie
	string sNomJoueur = sProprietes[0];
	unsigned int uiCasesRemplies = stoul(sProprietes[1], nullptr, 0);
	unsigned int uiNbCoups = stoul(sProprietes[2], nullptr, 0);
	unsigned int uiTailleGrille = stoul(sProprietes[3], nullptr, 0);
	bool bStatut = 1;
	if (sProprietes[4] == "En_Cours")
		bStatut = 0;

	// Recuperation des grilles
	unsigned int uiBoucle;
	unsigned int uiBoucle2;
	unsigned int uiNumCaractere = 0;
	unsigned int ** ppuiGrilleOrigine = new unsigned int * [uiTailleGrille];
	unsigned int ** ppuiGrille = new unsigned int * [uiTailleGrille];

	for (uiBoucle = 0; uiBoucle < uiTailleGrille; ++uiBoucle) {
		ppuiGrilleOrigine[uiBoucle] = new unsigned int [uiTailleGrille];
		ppuiGrille[uiBoucle] = new unsigned int [uiTailleGrille];
	}

	for (uiBoucle = 0; uiBoucle < uiTailleGrille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiTailleGrille; ++uiBoucle2) {
			ppuiGrilleOrigine[uiBoucle][uiBoucle2] = sProprietes[5][uiNumCaractere] - '0';
			ppuiGrille[uiBoucle][uiBoucle2] = sProprietes[6][uiNumCaractere] - '0';
			++uiNumCaractere;
		}

	// Creation de l'objet Partie
	CGrille GRIGrille(ppuiGrille, uiTailleGrille);
	CGrille GRIGrilleOrigine(ppuiGrilleOrigine, uiTailleGrille);
	CPartie * PARPartieChargee = new CPartie(&GRIGrille, &GRIGrilleOrigine, uiTailleGrille, sNomJoueur, uiCasesRemplies, uiNbCoups, bStatut);

	// On libere la memoire
	for (uiBoucle = 0; uiBoucle < uiTailleGrille; ++uiBoucle) {
		delete [] ppuiGrille[uiBoucle];
		delete [] ppuiGrilleOrigine[uiBoucle];
	}
	delete [] ppuiGrille;
	delete [] ppuiGrilleOrigine;

	return PARPartieChargee;
}