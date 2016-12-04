#include "ControleurGrille.h"


CControleurGrille::CControleurGrille(void)
{
}


CControleurGrille::~CControleurGrille(void)
{
}


bool CControleurGrille::CGRVerifierLigne(unsigned int uiNo, unsigned int uiNoLigne) {
	unsigned int uiBoucle;
	unsigned int uiTaille=pGRIGrille->GRILireTaille();

	for (uiBoucle = 0; uiBoucle < uiTaille; ++uiBoucle)
		if (pGRIGrille->GRILireValeur(uiNoLigne,uiBoucle) == uiNo)
			return false;

	return true;
}

bool CControleurGrille::CGRVerifierColonne(unsigned int uiNo, unsigned int uiNoColonne) {
	unsigned int uiBoucle;
	unsigned int uiTaille=pGRIGrille->GRILireTaille();

	for (uiBoucle = 0; uiBoucle < uiTaille; ++uiBoucle)
		if (pGRIGrille->GRILireValeur[uiBoucle][uiNoColonne] == uiNo)
			return false;

	return true;
}

void CControleurGrille::CGRModifierCase(unsigned int uiLigne, unsigned int uiColonne, unsigned int uiValeur){
	if (
	!CGRVerifierLigne(uiValeur, uiLigne) ||
	!CGRVerifierColonne(uiValeur,uiColonne) ||
	!CGRVerifierZone(uiValeur,pGRIGrille->GRIRecupererZone(uiLigne,uiColonne)))
	{
		throw CExcept();
	}
}

//Généraliser la récuparation de zone

bool CControleurGrille::CGRVerifierZone(unsigned int uiNo,unsigned int * piZone) {
	return true;}
//	unsigned int uiBoucle;
//	unsigned int uiBoucle2;
//
//	switch (uiNoZone) {
//		case 1 :
//			for (uiBoucle = 0; uiBoucle < 3; ++uiBoucle)
//				for (uiBoucle2 = 0; uiBoucle2 < 3; ++uiBoucle2)
//					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
//						return false;
//			break;
//		case 2 :
//			for (uiBoucle = 3; uiBoucle < 6; ++uiBoucle)
//				for (uiBoucle2 = 0; uiBoucle2 < 3; ++uiBoucle2)
//					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
//						return false;
//			break;
//		case 3 :
//			for (uiBoucle = 6; uiBoucle < 9; ++uiBoucle)
//				for (uiBoucle2 = 0; uiBoucle2 < 3; ++uiBoucle2)
//					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
//						return false;
//			break;
//		case 4 :
//			for (uiBoucle = 0; uiBoucle < 3; ++uiBoucle)
//				for (uiBoucle2 = 3; uiBoucle2 < 6; ++uiBoucle2)
//					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
//						return false;
//			break;
//		case 5 :
//			for (uiBoucle = 3; uiBoucle < 6; ++uiBoucle)
//				for (uiBoucle2 = 3; uiBoucle2 < 6; ++uiBoucle2)
//					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
//						return false;
//			break;
//		case 6 :
//			for (uiBoucle = 6; uiBoucle < 9; ++uiBoucle)
//				for (uiBoucle2 = 3; uiBoucle2 < 6; ++uiBoucle2)
//					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
//						return false;
//			break;
//		case 7 :
//			for (uiBoucle = 0; uiBoucle < 3; ++uiBoucle)
//				for (uiBoucle2 = 6; uiBoucle2 < 9; ++uiBoucle2)
//					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
//						return false;
//			break;
//		case 8 :
//			for (uiBoucle = 3; uiBoucle < 6; ++uiBoucle)
//				for (uiBoucle2 = 6; uiBoucle2 < 9; ++uiBoucle2)
//					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
//						return false;
//			break;
//		case 9 :
//			for (uiBoucle = 6; uiBoucle < 9; ++uiBoucle)
//				for (uiBoucle2 = 6; uiBoucle2 < 9; ++uiBoucle2)
//					if (ppuiGRIGrille[uiBoucle][uiBoucle2] == uiNo)
//						return false;
//			break;
//	}
//	return true;


