/*************************************************************
Titre : Classe CExcept
**************************************************************
Cette classe permet de créer des objets qui sont remontés lors
de la levée d'exceptions dans un programme.
**************************************************************/
#pragma once
// Définitions de quelques valeurs de CExcept utiles à notre programme
#define EXC_DFLT 0 // Valeur par défaut
//...

class CExcept
{
private:
	unsigned int uiEXCValeur; // Contient la valeur de l'excpetion CExcept

public:
	/********************************************
	Nom : CExcept()
	*********************************************
	Rôle : Constructeur par défaut
	*********************************************
	Entrée : Rien
	Pré-Conditions : Aucunes
	Sortie : Rien
	Post-Conditions : uiEXCValeur initialisée à 0
	*********************************************/
	CExcept(void);

	/***************************************************
	Nom : CExcept(CExcept &EXCParam)
	****************************************************
	Rôle : Constructeur de copie
	****************************************************
	Entrée : CExcept &EXCParam
	Pré-Conditions : Aucunes
	Sortie : Rien
	Post-Conditions : uiEXCValeur = EXCParam.uiEXCValeur
	****************************************************/
	CExcept(CExcept &EXCParam);

	/********************************************
	Nom : CExcept(unsigned int uiValeurParam)
	*********************************************
	Rôle : Constructeur prenant un unsigned int
	en paramètre
	*********************************************
	Entrée : unsigned int uiValeurParam
	Pré-Conditions : Aucunes
	Sortie : Rien
	Post-Conditions : uiEXCValeur = uiValeurParam
	*********************************************/
	CExcept(unsigned int uiValeurParam);

	/********************************************
	Nom : ~CExcept()
	*********************************************
	Rôle : Destructeur
	*********************************************
	Entrée : Rien
	Pré-Conditions : Aucunes
	Sortie : Rien
	Post-Conditions : Objet CExcept détruit
	*********************************************/
	~CExcept(void);

	/********************************************
	Nom : EXCLireValeur()
	*********************************************
	Rôle : Lis la valeur de l'exception
	*********************************************
	Entrée : Rien
	Pré-Conditions : Aucunes
	Sortie : uiEXCValeur
	Post-Conditions : uiEXCValeur retourné
	*********************************************/
	unsigned int EXCLireValeur(void);

	/**************************************************
	Nom : EXCModifierValeur(unsigned int uiValeurParam)
	***************************************************
	Rôle : Modifie la valeur de l'exception
	***************************************************
	Entrée : unsigned int uiValeurParam
	Pré-Conditions : Aucunes
	Sortie : Rien
	Post-Conditions : uiEXCValeur = uiValeurParam
	***************************************************/
	void EXCModifierValeur(unsigned int uiValeurParam);
};
