/**
* \file Parseur.cpp
* \author Benjamin Caldas
* \brief Le fichier source de la classe CParseur.
*/
#include "Parseur.h"

CParseur::CParseur(std::string sChemin){

	pcPARValeur = new char [TAILLE_MAX_VALEUR];
	pcPARAttribut = new char [TAILLE_MAX_ATTRIBUT];

	fichier.open(sChemin);
	if(!fichier){
		throw CExcept(EXC_OUV_FIC);
	}
}

CParseur::~CParseur(){
	if(fichier){
		fichier.close();
	}

	delete[] pcPARAttribut;
	delete[] pcPARValeur;
}

void CParseur::PARModifierFichier(char* pcChemin){
	if(fichier){
		fichier.close();
	}

	fichier.open(pcChemin);
	if(!fichier){
		throw CExcept(EXC_OUV_FIC);
	}
}

void CParseur::PARLireLigne(){
	if(!fichier.eof()){
		PARParseAttribut();
		PARParseValeur();
	}
}

void CParseur::PARParseAttribut(){
	unsigned int uiBoucle=0;

	fichier.get(pcPARAttribut[0]);
	while (pcPARAttribut[uiBoucle] != '=' && pcPARAttribut[uiBoucle] != '\n'){
		uiBoucle++;
		fichier.get(pcPARAttribut[uiBoucle]);
	}
	pcPARAttribut[uiBoucle]='\0';
}

void CParseur::PARParseValeur(){
	unsigned int uiBoucle=0;

	fichier.get(pcPARValeur[0]);
	while (pcPARValeur[uiBoucle] != '\n' && pcPARValeur[uiBoucle] != ','){
		uiBoucle++;
		fichier.get(pcPARValeur[uiBoucle]);
	}
	pcPARValeur[uiBoucle]='\0';
}