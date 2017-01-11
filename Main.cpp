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

	CChargeurPartie CHPChargeurPartie1;
	CPartie * PARPartie = CHPChargeurPartie1.CHPMenuPrincipal();
	PARPartie->PARJouer();

	int a;
	cin >> a;
}