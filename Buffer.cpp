#include "Buffer.h"


Buffer::Buffer()
{
	//Recuperation du handle pour l'output
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	COORD size = COORD{ SCREEN_WIDTH | SCREEN_HEIGHT };
	SetConsoleScreenBufferSize(hOutput, size);

	SMALL_RECT rect = SMALL_RECT{ 0, 0, SCREEN_WIDTH-1, SCREEN_HEIGHT-1 };
	SetConsoleWindowInfo(hOutput, true, &rect);

	dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	for (size_t i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (size_t j = 0; j < SCREEN_WIDTH; j++)
		{
			buffer[i][j].Char.AsciiChar = ' ';
			buffer[i][j].Attributes = 0x0F;
		}
	}

	//Suppression du curseur à l'affichage
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hOutput, &cursorInfo);

	//Titre de la fenetre
	TCHAR title[MAX_PATH];
	StringCchPrintf(title, MAX_PATH, TEXT("ASCII WARS"));
	SetConsoleTitle(title);
}

void Buffer::test()
{
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);

	buffer[5][10].Char.AsciiChar = 'H';
	buffer[5][10].Attributes = 0x0E;
	buffer[5][11].Char.AsciiChar = 'i';
	buffer[5][11].Attributes = 0x0B;
	buffer[5][12].Char.AsciiChar = '!';
	buffer[5][12].Attributes = 0x0A;
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
			// L'affichage du buffer est inversé X/Y
			buffer[j][i].Char.AsciiChar = ' ';
			buffer[j][i].Attributes = m.getCase(i, j).getAttribute();
		}
	}
}

void Buffer::editCar(Player p)
{
	for (size_t i = 0; i < p.getCar().size(); i++)
	{
		Caractere c = *p.getCar()[i];
		buffer[c.getY()][c.getX()].Char.AsciiChar = c.getCaractere();

		// TODO: récupérer la couleur du player
		int playerOneColor = p.getColor(); // Bleu

		// Récupération du background de la case sous laquelle le joueur va
		int backgroundActuel = buffer[c.getY()][c.getX()].Attributes;
		// Extrait cette couleur (c'est le dernier bit à droite donc un "NON ET" permet de récupérer le bit)
		backgroundActuel &= ~0x000f;
		// Combine les deux couleurs ensemble (ex: 0x0001 | 0x0010 = 0x0011)
		int nouvelleCouleur = playerOneColor | backgroundActuel;
		// Mettre à jour la couleur de la case
		buffer[c.getY()][c.getX()].Attributes = nouvelleCouleur;
	}
}

void Buffer::editHUD(string joueur, int pm)
{
	string s = joueur+" : mouvement restants "+ to_string(pm);
	int i;
	for (i = 0; i < size(s); i++)
	{
		buffer[0][i].Char.AsciiChar = s[i];
		buffer[0][i].Attributes = 0x000F;
	}
	for (i; i < SCREEN_WIDTH; i++)
	{
		buffer[0][i].Attributes = 0x000F;
	}
}

Buffer::~Buffer()
{
}
