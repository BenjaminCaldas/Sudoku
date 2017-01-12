/**
* \file Main.cpp
* \author Benjamin Caldas
* \brief Le fichier contenant la fonction principale du projet.
*/
/*************************************************************
Titre : Main
**************************************************************
Ce fichier est la fonction principale du projet,
elle est executee en premier lorsque on lance le programme.
**************************************************************/


/**********************************************************
Le bloc de code suivant permet de detecter et de relever
les eventuelles fuites mémoires du programme en mode debug 
***********************************************************/
/* Début du bloc */
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <Crtdbg.h>

#ifdef _DEBUG 
#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 
#endif 
#endif  // _DEBUG
/* Fin du bloc */

#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "dirent.h"
#include "Grille.h"
#include "Except.h"
#include "ControleurGrille.h"
#include "Solveur.h"
#include "Partie.h"
#include "ChargeurPartie.h"
#include "Parseur.h"

using namespace std;

int main (unsigned int argc, char * argv[])
{
	// Pour les fuites memoires
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF ); // Permet d'appeler _CrtDumpMemoryLeaks() a chaque point de sortie du programme
	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_DEBUG ); // Permet d'afficher le rapport des fuites memoires dans la fenêtre "sortie" de Visual Studio
	
	// On charge une partie a l'aide du chargeur
	try {
		CChargeurPartie CHPChargeurPartie1;
		CPartie * PARPartie = CHPChargeurPartie1.CHPMenuPrincipal();
		if (PARPartie != NULL)	
			PARPartie->PARJouer();
		else
			cout << "Vous ne pouvez pas jouer :/" << endl;
		delete PARPartie;
	}
	catch(CExcept EXCParam) {
		switch(EXCParam.EXCLireValeur()) {
			case EXC_IDX_ERR :
				cerr << "Erreur " << EXC_IDX_ERR << " : Index hors de la grille de Sudoku." << endl;
				exit(EXC_IDX_ERR);
			case EXC_VAL_INC :
				cerr << "Erreur " << EXC_VAL_INC << " : Valeur incorrecte pour ce Sudoku." << endl;
				exit(EXC_VAL_INC);
			case EXC_ZONE_INC :
				cerr << "Erreur " << EXC_ZONE_INC << " : Zone incorrecte." << endl;
				exit(EXC_ZONE_INC);
			case EXC_REP_OUV_ERR :
				cerr << "Erreur " << EXC_REP_OUV_ERR << " : Ouverture du repertoire impossible." << endl;
				exit(EXC_REP_OUV_ERR);
			case EXC_OUV_FIC :
				cerr << "Erreur " << EXC_OUV_FIC << " : Ouverture du fichier impossible." << endl;
				exit(EXC_OUV_FIC);
			default :
				return 0;
		}
	}

	// Pour les fuites mémoires
	_CrtMemState s1;
	_CrtMemCheckpoint( &s1 ); // Permet de remplir s1 avec l'état de la mémoire à cet instant précis
	_CrtMemDumpStatistics( &s1 ); // Permet d'afficher l'état de la mémoire à cet instant précis dans la fenêtre "sortie" de Visual Studio
}