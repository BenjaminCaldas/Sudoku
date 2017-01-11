/**
* \file Except.cpp
* \author Benjamin Caldas
* \brief Le fichier source de la classe CExcept.
*/
#include "Except.h"

CExcept::CExcept(void) {
	uiEXCValeur = EXC_DFLT;
}

CExcept::CExcept(CExcept &EXCParam) {
	uiEXCValeur = EXCParam.uiEXCValeur;
}

CExcept::CExcept(unsigned int uiValeur) {
	uiEXCValeur = uiValeur;
}

CExcept::~CExcept(void) {

}

unsigned int CExcept::EXCLireValeur() {
	return uiEXCValeur;
}

void CExcept::EXCModifierValeur(unsigned int uiValeur) {
	uiEXCValeur = uiValeur;
}
