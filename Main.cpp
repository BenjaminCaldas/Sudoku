#include <stdlib.h>
#include <iostream>

#include "Sudoku.h"

using namespace std;

int main (unsigned int argc, char * argv[])
{
	unsigned int uiBoucle;
	unsigned int ** ppuiGrille;

	ppuiGrille = new unsigned int * [9];
	for (uiBoucle = 0; uiBoucle < 9; ++uiBoucle)
		ppuiGrille[uiBoucle] = new unsigned int [9];
	ppuiGrille[0][1] = 7;ppuiGrille[0][3] = 5;ppuiGrille[0][4] = 6;ppuiGrille[0][7] = 2;ppuiGrille[0][8] = 9;
	ppuiGrille[1][2] = 6;ppuiGrille[1][8] = 7;
	ppuiGrille[2][0] = 9;ppuiGrille[2][3] = 4;ppuiGrille[2][4] = 7;
	ppuiGrille[3][1] = 8;ppuiGrille[3][2] = 3;ppuiGrille[3][3] = 1;ppuiGrille[3][7] = 9;ppuiGrille[3][8] = 4;
	ppuiGrille[4][1] = 9;ppuiGrille[4][2] = 2;ppuiGrille[4][3] = 6;ppuiGrille[4][5] = 8;ppuiGrille[4][6] = 7;ppuiGrille[4][7] = 3;
	ppuiGrille[5][0] = 1;ppuiGrille[5][1] = 5;ppuiGrille[5][5] = 4;ppuiGrille[5][6] = 2;ppuiGrille[5][7] = 6;
	ppuiGrille[6][4] = 1;ppuiGrille[6][5] = 6;ppuiGrille[6][8] = 5;
	ppuiGrille[7][0] = 8;ppuiGrille[7][6] = 9;
	ppuiGrille[8][0] = 7;ppuiGrille[8][1] = 6;ppuiGrille[8][4] = 8;ppuiGrille[8][5] = 9;ppuiGrille[8][7] = 4;
	CGrille GRISudoku1(ppuiGrille, 9);
	GRISudoku1.GRIAfficherGrille();

	int a;
	cin >> a;
}