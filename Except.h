/*!
* \file Except.h
* \author Benjamin Caldas
* \brief Le fichier d'en-tête de la classe CExcept.
*/
#ifndef CEXCEPT_H
#define CEXCEPT_H

/* Définitions de quelques valeurs de CExcept utiles à notre programme */
#define EXC_DFLT 0 /*!< Valeur par defaut de l'exception */
#define EXC_IDX_ERR 1 /*!< Index hors de la grille de Sudoku */
#define EXC_VAL_INC 2 /*!< Valeur incorrecte pour un Sudoku */
#define EXC_ZONE_INC 3 /*!< Zone incorrecte */
#define EXC_REP_OUV_ERR 4 /*!< Erreur d'ouverture du répertoire */
#define EXC_OUV_FIC 5 /*!< Erreur d'ouverture du fichier */

/*!
* \class CExcept
* \brief Cette classe permet de créer des objets qui seront remontés lors de la levée d'exceptions dans un programme.
*/
class CExcept {
	private:
		unsigned int uiEXCValeur; /*!< Contient la valeur de l'exception CExcept */

	public:
		/*!
		* \brief Constructeur par défault de la classe CExcept.
		* \param void
		*/
		CExcept(void);

		/*!
		* \brief Constructeur de recopie de la classe CExcept.
		* \param EXCParam L'objet de la classe CExcept à recopier.
		*/
		CExcept(CExcept &EXCParam);

		/*!
		* \brief Constructeur de la classe CExcept.
		* \param uiValeurParam La valeur de l'exception.
		*/
		CExcept(unsigned int uiValeurParam);

		/*!
		* \brief Destructeur de la classe CExcept.
		* \param void
		*/
		~CExcept(void);

		/*!
		* \brief Fonction permettant de lire la valeur d'un objet d ela classe CExcept.
		* \param void
		* \return La valeur de l'exception.
		*/
		unsigned int EXCLireValeur(void);

		/*!
		* \brief Fonction permettant de modifier la valeur d'un objet de la classe CExcept.
		* \param uiValeurParam La nouvelle valeur de l'exception.
		* \return void
		*/
		void EXCModifierValeur(unsigned int uiValeurParam);
};

#endif