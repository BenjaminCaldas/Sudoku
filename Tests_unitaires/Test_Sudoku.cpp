#include "stdafx.h"
#include "CppUnitTest.h"

#include "Grille.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests_Unitaires_Sudoku {	
	TEST_CLASS(Test_CExcept) {
	public:

		/* ### TESTS CONSTRUCTEURS CEXCEPT ### */

		TEST_METHOD(TestConstructeurDefaultCExcept) {
			CExcept EXCExcept;
			Assert::AreEqual((int) EXCExcept.EXCLireValeur(), EXC_DFLT);
			Assert::AreEqual((int) EXCExcept.EXCLireValeur(), 0);
		}

		TEST_METHOD(TestConstructeurRecopieCExcept) {
			CExcept EXCExcept(5);
			CExcept EXCExcept2(EXCExcept);
			Assert::AreEqual((int) EXCExcept.EXCLireValeur(), 5);
			Assert::AreNotEqual((int) EXCExcept.EXCLireValeur(), 0);
		}

		TEST_METHOD(TestConstructeurCExcept) {
			CExcept EXCExcept(10);
			Assert::AreEqual((int) EXCExcept.EXCLireValeur(), 10);
			Assert::AreNotEqual((int) EXCExcept.EXCLireValeur(), 0);
		}

		TEST_METHOD(TestDestructeurCExcept) {

		}

		/* ### TESTS GETTERS ET SETTERS ### */

		TEST_METHOD(TestGetSetValeur) {
			CExcept EXCExcept(5);
			Assert::AreEqual((int) EXCExcept.EXCLireValeur(), 5);
			EXCExcept.EXCModifierValeur(10);
			Assert::AreEqual((int) EXCExcept.EXCLireValeur(), 10);
			Assert::AreNotEqual((int) EXCExcept.EXCLireValeur(), 5);
		}

	};

	TEST_CLASS(Test_CGrille) {
	public:
		
		/*!
		* \brief Cette fonction crée une grille.
		* \param uiTaille La taille de la grille.
		* \return La grille.
		*/
		unsigned int ** CreerGrille(unsigned int uiTaille) {
			unsigned int ** ppuiGrille = new unsigned int * [uiTaille];
			unsigned int uiBoucle;
			for (uiBoucle = 0; uiBoucle < uiTaille; ++uiBoucle)
				ppuiGrille[uiBoucle] = new unsigned int [uiTaille];
			unsigned int uiGrille[9][9] ={{9,0,0,1,0,0,0,0,5},
										{0,0,5,0,9,0,2,0,1},
										{8,0,0,0,4,0,0,0,0},
										{0,0,0,0,8,0,0,0,0},
										{0,0,0,7,0,0,0,0,0},
										{0,0,0,0,2,6,0,0,9},
										{2,0,0,3,0,0,0,0,6},
										{0,0,0,2,0,0,9,0,0},
										{0,0,1,9,0,4,5,7,0}};
			unsigned int uiBoucle2;
			for (uiBoucle = 0; uiBoucle < uiTaille; ++uiBoucle)
				for (uiBoucle2 = 0; uiBoucle2 < uiTaille; ++uiBoucle2)
					ppuiGrille[uiBoucle][uiBoucle2] = uiGrille[uiBoucle][uiBoucle2];
			return ppuiGrille;
		}

		/*!
		* \brief Cette fonction désalloue une grille.
		* \param ppuiGrille La grille a désallouer.
		* \param uiTaille La taille de la grille.
		* \return void
		*/
		void DesallouerGrille(unsigned int ** ppuiGrille, unsigned int uiTaille) {
			unsigned int uiBoucle;
			for (uiBoucle = 0; uiBoucle < uiTaille; ++uiBoucle)
				delete [] ppuiGrille[uiBoucle];
			delete [] ppuiGrille;
		}

		/* ### TESTS CONSTRUCTEURS CGRILLE ### */

		TEST_METHOD(TestConstructeurDefaultCGrille) {
			CGrille GRIGrille;
			Assert::AreEqual((int) GRIGrille.GRILireTaille(), 0);
		}

		TEST_METHOD(TestConstructeurRecopieCGrille) {
			CGrille GRIGrille;
			CGrille GRIGrille2(GRIGrille);
			Assert::AreEqual(GRIGrille.GRILireTaille(), GRIGrille2.GRILireTaille());
		}

		TEST_METHOD(TestConstructeurCGrille) {
			CGrille GRIGrille(NULL, 0);
			Assert::AreEqual((int) GRIGrille.GRILireTaille(), 0);
			unsigned int uiTaille = 9;
			unsigned int ** ppuiGrille = CreerGrille(uiTaille);
			CGrille GRIGrille2(ppuiGrille, uiTaille);
			Assert::AreEqual((int) GRIGrille2.GRILireTaille(), 9);
			DesallouerGrille(ppuiGrille, uiTaille);
		}

		TEST_METHOD(testDestructeurCGrille) {

		}

		/* ### TESTS GETTERS ET SETTERS ### */

		TEST_METHOD(TestGetSetTaille) {
			CGrille GRIGrille(NULL, 5);
			Assert::AreEqual((int) GRIGrille.GRILireTaille(), 0);
			GRIGrille.GRIModifierTaille(10);
			Assert::AreEqual((int) GRIGrille.GRILireTaille(), 10);
			Assert::AreNotEqual((int) GRIGrille.GRILireTaille(), 5);
		}

		/* ### TESTS AUTRES METHODES ### */

		TEST_METHOD(TestLireValeur) {
			unsigned int uiTaille = 9;
			unsigned int ** ppuiGrille = CreerGrille(uiTaille);
			CGrille GRIGrille(ppuiGrille, uiTaille);
			Assert::AreEqual((int) GRIGrille.GRILireValeur(0, 0), 9);
			Assert::AreNotEqual((int) GRIGrille.GRILireValeur(1,2), 0);
			DesallouerGrille(ppuiGrille, uiTaille);
		}

		TEST_METHOD(TestModifierValeur) {
			unsigned int uiTaille = 9;
			unsigned int ** ppuiGrille = CreerGrille(uiTaille);
			CGrille GRIGrille(ppuiGrille, uiTaille);
			GRIGrille.GRIModifierValeur(1, 2, 1);
			Assert::AreEqual((int) GRIGrille.GRILireValeur(1, 2), 1);
			Assert::AreNotEqual((int) GRIGrille.GRILireValeur(1, 2), 5);
			DesallouerGrille(ppuiGrille, uiTaille);
		}

		TEST_METHOD(testRecupererZone) {
			unsigned int uiTaille = 9;
			unsigned int ** ppuiGrille = CreerGrille(uiTaille);
			CGrille GRIGrille(ppuiGrille, uiTaille);
			Assert::AreEqual((int) GRIGrille.GRIRecupererZone(8, 8), 9);
			Assert::AreNotEqual((int) GRIGrille.GRILireValeur(3, 3), 1);
			DesallouerGrille(ppuiGrille, uiTaille);
		}

	};
}