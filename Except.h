/*************************************************************
Titre : Classe CExcept
**************************************************************
Cette classe permet de cr�er des objets qui sont remont�s lors
de la lev�e d'exceptions dans un programme.
**************************************************************/
#pragma once
// D�finitions de quelques valeurs de CExcept utiles � notre programme
#define EXC_DFLT 0 // Valeur par d�faut
//...

class CExcept
{
private:
	unsigned int uiEXCValeur; // Contient la valeur de l'excpetion CExcept

public:
	/********************************************
	Nom : CExcept()
	*********************************************
	R�le : Constructeur par d�faut
	*********************************************
	Entr�e : Rien
	Pr�-Conditions : Aucunes
	Sortie : Rien
	Post-Conditions : uiEXCValeur initialis�e � 0
	*********************************************/
	CExcept(void);

	/***************************************************
	Nom : CExcept(CExcept &EXCParam)
	****************************************************
	R�le : Constructeur de copie
	****************************************************
	Entr�e : CExcept &EXCParam
	Pr�-Conditions : Aucunes
	Sortie : Rien
	Post-Conditions : uiEXCValeur = EXCParam.uiEXCValeur
	****************************************************/
	CExcept(CExcept &EXCParam);

	/********************************************
	Nom : CExcept(unsigned int uiValeurParam)
	*********************************************
	R�le : Constructeur prenant un unsigned int
	en param�tre
	*********************************************
	Entr�e : unsigned int uiValeurParam
	Pr�-Conditions : Aucunes
	Sortie : Rien
	Post-Conditions : uiEXCValeur = uiValeurParam
	*********************************************/
	CExcept(unsigned int uiValeurParam);

	/********************************************
	Nom : ~CExcept()
	*********************************************
	R�le : Destructeur
	*********************************************
	Entr�e : Rien
	Pr�-Conditions : Aucunes
	Sortie : Rien
	Post-Conditions : Objet CExcept d�truit
	*********************************************/
	~CExcept(void);

	/********************************************
	Nom : EXCLireValeur()
	*********************************************
	R�le : Lis la valeur de l'exception
	*********************************************
	Entr�e : Rien
	Pr�-Conditions : Aucunes
	Sortie : uiEXCValeur
	Post-Conditions : uiEXCValeur retourn�
	*********************************************/
	unsigned int EXCLireValeur(void);

	/**************************************************
	Nom : EXCModifierValeur(unsigned int uiValeurParam)
	***************************************************
	R�le : Modifie la valeur de l'exception
	***************************************************
	Entr�e : unsigned int uiValeurParam
	Pr�-Conditions : Aucunes
	Sortie : Rien
	Post-Conditions : uiEXCValeur = uiValeurParam
	***************************************************/
	void EXCModifierValeur(unsigned int uiValeurParam);
};
