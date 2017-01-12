/**
* \file ControleurGrille.cpp
* \author Benjamin Caldas
* \brief Le fichier source de la classe CControleurGrille.
*/
#include "ControleurGrille.h"

CControleurGrille::CControleurGrille() {
	pGRIGrille = NULL;
}

CControleurGrille::CControleurGrille(CControleurGrille & CGRUnControleur) {
	pGRIGrille = CGRUnControleur.pGRIGrille;
}

CControleurGrille::CControleurGrille(CGrille * GRIUneGrille) {
	pGRIGrille = GRIUneGrille;
}

bool CControleurGrille::CGRVerifierLigne(unsigned int uiNo, unsigned int uiNoLigne) {
	unsigned int uiTaille = pGRIGrille->GRILireTaille();
	if (uiNoLigne < 0 || uiNoLigne >= uiTaille) {
		// Lever exception (index incorrect)
		throw CExcept(EXC_IDX_ERR);
	}
	if (uiNo < 0 || uiNo > uiTaille) {
		// Lever exception (valeur incorrecte)
		throw CExcept(EXC_VAL_INC);
	}
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiTaille; ++uiBoucle)
		if (pGRIGrille->GRILireValeur(uiNoLigne, uiBoucle) == uiNo)
			return false;

	return true;
}

bool CControleurGrille::CGRVerifierColonne(unsigned int uiNo, unsigned int uiNoColonne) {
	unsigned int uiTaille = pGRIGrille->GRILireTaille();
	if (uiNoColonne < 0 || uiNoColonne >= uiTaille) {
		// Lever exception (index incorrect)
		throw CExcept(EXC_IDX_ERR);
	}
	if (uiNo < 0 || uiNo > uiTaille) {
		// Lever exception (valeur incorrecte)
		throw CExcept(EXC_VAL_INC);
	}
	unsigned int uiBoucle;

	for (uiBoucle = 0; uiBoucle < uiTaille; ++uiBoucle)
		if (pGRIGrille->GRILireValeur(uiBoucle, uiNoColonne) == uiNo)
			return false;

	return true;
}

bool CControleurGrille::CGRVerifierZone(unsigned int uiNo, unsigned int uiNoZone) {
	unsigned int uiTaille = pGRIGrille->GRILireTaille();
	if (uiNoZone < 1 || uiNoZone > uiTaille) {
		// Lever exception (zone incorrect)
		throw CExcept(EXC_ZONE_INC);
	}
	if (uiNo < 0 || uiNo > uiTaille) {
		// Lever exception (valeur incorrecte)
		throw CExcept(EXC_VAL_INC);
	}
	unsigned int uiBoucle;
	unsigned int uiBoucle2;

	switch (uiNoZone) {
		case 1 :
			for (uiBoucle = 0; uiBoucle < 3; ++uiBoucle)
				for (uiBoucle2 = 0; uiBoucle2 < 3; ++uiBoucle2)
					if (pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2) == uiNo)
						return false;
			break;
		case 2 :
			for (uiBoucle = 0; uiBoucle < 3; ++uiBoucle)
				for (uiBoucle2 = 3; uiBoucle2 < 6; ++uiBoucle2)
					if (pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2) == uiNo)
						return false;
			break;
		case 3 :
			for (uiBoucle = 0; uiBoucle < 3; ++uiBoucle)
				for (uiBoucle2 = 6; uiBoucle2 < 9; ++uiBoucle2)
					if (pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2) == uiNo)
						return false;
			break;
		case 4 :
			for (uiBoucle = 3; uiBoucle < 6; ++uiBoucle)
				for (uiBoucle2 = 0; uiBoucle2 < 3; ++uiBoucle2)
					if (pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2) == uiNo)
						return false;
			break;
		case 5 :
			for (uiBoucle = 3; uiBoucle < 6; ++uiBoucle)
				for (uiBoucle2 = 3; uiBoucle2 < 6; ++uiBoucle2)
					if (pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2) == uiNo)
						return false;
			break;
		case 6 :
			for (uiBoucle = 3; uiBoucle < 6; ++uiBoucle)
				for (uiBoucle2 = 6; uiBoucle2 < 9; ++uiBoucle2)
					if (pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2) == uiNo)
						return false;
			break;
		case 7 :
			for (uiBoucle = 6; uiBoucle < 9; ++uiBoucle)
				for (uiBoucle2 = 0; uiBoucle2 < 3; ++uiBoucle2)
					if (pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2) == uiNo)
						return false;
			break;
		case 8 :
			for (uiBoucle = 6; uiBoucle < 9; ++uiBoucle)
				for (uiBoucle2 = 3; uiBoucle2 < 6; ++uiBoucle2)
					if (pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2) == uiNo)
						return false;
			break;
		case 9 :
			for (uiBoucle = 6; uiBoucle < 9; ++uiBoucle)
				for (uiBoucle2 = 6; uiBoucle2 < 9; ++uiBoucle2)
					if (pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2) == uiNo)
						return false;
			break;
	}
	return true;
}

bool CControleurGrille::CGRVerifierDisponibiliteCase(unsigned int uiNoLigne, unsigned int uiNoColonne) {
	unsigned int uiTaille = pGRIGrille->GRILireTaille();
	if (uiNoLigne < 0 || uiNoLigne >= uiTaille) {
		// Lever exception (index incorrect)
		throw CExcept(EXC_IDX_ERR);
	}
	if (uiNoColonne < 0 || uiNoColonne >= uiTaille) {
		// Lever exception (index incorrect)
		throw CExcept(EXC_IDX_ERR);
	}
	if (pGRIGrille->GRILireValeur(uiNoLigne, uiNoColonne) == 0)
		return true;
	return false;
}

bool CControleurGrille::CGRModifierCase(unsigned int uiLigne, unsigned int uiColonne, unsigned int uiValeur){
	unsigned int uiTaille = pGRIGrille->GRILireTaille();
	if (uiLigne < 0 || uiLigne >= uiTaille) {
		// Lever exception (index incorrect)
		throw CExcept(EXC_IDX_ERR);
	}
	if (uiColonne < 0 || uiColonne >= uiTaille) {
		// Lever exception (index incorrect)
		throw CExcept(EXC_IDX_ERR);
	}
	if (uiValeur < 0 || uiValeur > uiTaille) {
		// Lever exception (valeur incorrecte)
		throw CExcept(EXC_VAL_INC);
	}
	if (!CGRVerifierLigne(uiValeur, uiLigne) || !CGRVerifierColonne(uiValeur, uiColonne) ||
	!CGRVerifierZone(uiValeur, pGRIGrille->GRIRecupererZone(uiLigne, uiColonne)))
		return false;
	return true;
}

unsigned int CControleurGrille::CGRCompterCasesRemplies() {
	unsigned int uiBoucle;
	unsigned int uiBoucle2;
	unsigned int uiTaille = pGRIGrille->GRILireTaille();
	unsigned int uiNombre = 0;

	for (uiBoucle = 0; uiBoucle < uiTaille; ++uiBoucle)
		for (uiBoucle2 = 0; uiBoucle2 < uiTaille; ++uiBoucle2)
			if (pGRIGrille->GRILireValeur(uiBoucle, uiBoucle2) != 0)
				++uiNombre;

	return uiNombre;
}
