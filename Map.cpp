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
			cases[col][line] = Case('.', MAP_COLOR_GREEN, true);
		}

		// X => fond bleu
		else if (currentChar == 'X') {
			cases[col][line] = Case('X', MAP_COLOR_BLUE, false);
		}

		// M => fond rouge
		else if (currentChar == 'M') {
			cases[col][line] = Case('M', BACKGROUND_RED | BACKGROUND_GREEN, false);
		}

		else if (currentChar == 'Q') {
			cases[col][line] = Case('Q', BACKGROUND_RED, true, Case::TYPE_CASE::QG);
		}

		// Caractère non spécifique => on l'affiche telquel
		else if (currentChar != '\n') {
			cases[col][line] = Case(currentChar, 0x0F);
		}

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

// Retourne vrai si le joueur peut se déplacer sur la case [x,y]
bool Map::canMove(int x, int y) {
	return cases[x][y].block;
}

// Code appelé à chaque fois qu'un joueur se déplace sur une case
void Map::triggerCase(int x, int y) {
	switch (cases[x][y].type)
	{
		case Case::TYPE_CASE::QG :
			break;
		case Case::TYPE_CASE::BONUS:
			break;
		case Case::TYPE_CASE::TERRAIN:
			break;
		default:
			break;
	}
}

Map::~Map()
{
}
