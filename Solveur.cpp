#include "Solveur.h"


CSolveur::CSolveur() {}

CSolveur::CSolveur(CSolveur & SLVUnSolveur) {
	luiSLVTempsResolution = SLVUnSolveur.luiSLVTempsResolution;
	luiSLVNbNumerosTestes = SLVUnSolveur.luiSLVNbNumerosTestes;
	uiSLVPourcentageResolution = SLVUnSolveur.uiSLVPourcentageResolution;
}

CSolveur::~CSolveur() {}

void CSolveur::SLVResoudre(CSudoku SDKSudoku) {

}