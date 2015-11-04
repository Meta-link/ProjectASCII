#include "Map.h"

// Création d'une map vide
Map::Map()
{
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			cases[i][j] = Case();
		}
	}
}

// Création d'une map à partir d'un fichier
Map::Map(string filename) {
	char currentChar;
	fstream fin(filename, fstream::in);

	int col = 0, line = 0;
	// Lecture du fichier
	while (fin >> noskipws >> currentChar) {

		// . => fond vert
		if (currentChar == '.') {
			cases[col][line] = Case('.', 0x0021, true);
		}

		// X => fond bleu
		else if (currentChar == 'X') {
			cases[col][line] = Case('X', 0x0030, false);
		}

		// Caractère non spécifique => on l'affiche telquel
		else if (currentChar != '\n') {
			cases[col][line] = Case(currentChar, 0x0F);
		}

		// DEBUG
		//cout << currentChar;

		// A la fin d'un caractère on incrémente la colonne
		col++;
		// Si on arrive en fin de ligne, on incrémente la ligne et on remet la colonne à 0
		if (currentChar == '\n') {
			col = 0;
			line++;
		}
	}
}

// Retourne la case indiquée en [X,Y]
Case Map::getCase(int x, int y) {
	return cases[x][y];
}

bool Map::canMove(int x, int y) {
	return cases[x][y].block;
}

Map::~Map()
{
}
