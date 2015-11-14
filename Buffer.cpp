#include "Buffer.h"


Buffer::Buffer()
{
	//Recuperation du handle pour l'output
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	COORD size = COORD{ SCREEN_WIDTH|SCREEN_HEIGHT };
	SetConsoleScreenBufferSize(hOutput, size);

	SMALL_RECT rect = SMALL_RECT{ 0, 0, SCREEN_WIDTH-1, SCREEN_HEIGHT-1 };
	SetConsoleWindowInfo(hOutput, true, &rect);

	dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	reset();

	//Suppression du curseur � l'affichage
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hOutput, &cursorInfo);

	//Titre de la fenetre
	TCHAR title[MAX_PATH];
	StringCchPrintf(title, MAX_PATH, TEXT("ASCII WARS"));
	SetConsoleTitle(title);
}

void Buffer::reset()
{
	for (size_t i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (size_t j = 0; j < SCREEN_WIDTH; j++)
		{
			buffer[i][j].Char.AsciiChar = ' ';
			buffer[i][j].Attributes = 0x0F;
		}
	}
}

void Buffer::display()
{
	//Affichage du buffer
	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}

// Affiche la map
void Buffer::editMap(Map m) {
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			// L'affichage du buffer est invers� X/Y
			buffer[j][i].Char.AsciiChar = ' ';
			buffer[j][i].Attributes = m.getCase(i, j).getAttribute();
		}
	}
}

// G�re l'affichage des joueurs et de leurs QG
void Buffer::editCar(Player p)
{
	for (size_t i = 0; i < p.getCar().size(); i++)
	{
		Caractere c = *p.getCar()[i];
		buffer[c.getY()][c.getX()].Char.AsciiChar = c.getCaractere();

		int playerOneColor = p.getColor(); // Bleu

		// R�cup�ration du background de la case sous laquelle le joueur va
		int backgroundActuel = buffer[c.getY()][c.getX()].Attributes;
		// Extrait cette couleur (c'est le dernier bit � droite donc un "NON ET" permet de r�cup�rer le bit)
		backgroundActuel &= ~0x000f;
		// Combine les deux couleurs ensemble (ex: 0x0001|0x0010 = 0x0011)
		int nouvelleCouleur = playerOneColor|backgroundActuel;
		// Mettre � jour la couleur de la case
		buffer[c.getY()][c.getX()].Attributes = nouvelleCouleur;

		// Affichage du QG des personnages
		buffer[p.getQg().getY()][p.getQg().getX()].Attributes = nouvelleCouleur;
		buffer[p.getQg().getY()][p.getQg().getX()].Char.AsciiChar = p.getQg().getCaractere();
	}
}

// G�re l'affiche de l'interface
void Buffer::editHUD(string joueur, int pm)
{
	string s = joueur+" : mouvement restants "+ to_string(pm);
	int i;

	// Fond noir texte blanc + affichage du texte
	for (i = 0; i < size(s); i++)
	{
		buffer[0][i].Char.AsciiChar = s[i];
		buffer[0][i].Attributes = 0x000F;
	}

	// Affichage de la ligne jusqu'au bout de l'�cran
	for (i; i < SCREEN_WIDTH; i++)
	{
		buffer[0][i].Attributes = 0x000F;
	}
}

// Permet d'afficher un �cran de victoire quand un joueur atteint le QG de l'autre
void Buffer::win(int winner)
{
	char currentChar;
	fstream fin("end"+to_string(winner), fstream::in);
	int col = 0, line = SCREEN_HEIGHT/2-5;

	reset();
	
	// Lecture du fichier
	while (fin >> noskipws >> currentChar) {
		buffer[line][col].Char.AsciiChar = currentChar;

		// A la fin d'un caract�re on incr�mente la colonne
		col++;
		// Si on arrive en fin de ligne, on incr�mente la ligne et on remet la colonne � 0
		if (currentChar == '\n') {
			col = 0;
			line++;
		}
	}
}

Buffer::~Buffer()
{
}
