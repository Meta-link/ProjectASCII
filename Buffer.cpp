#include "Buffer.h"

Buffer::Buffer()
{
	//Recuperation du handle pour l'output
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

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

void Buffer::edit(vector<Caractere> car)
{
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);

	for (size_t i = 0; i < car.size(); i++)
	{
		Caractere c = car[i];
		buffer[c.getY()][c.getX()].Char.AsciiChar = c.getCaractere();
	}
}

void Buffer::edit(Caractere c)
{
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);

	buffer[c.getY()][c.getX()].Char.AsciiChar = c.getCaractere();
}

Buffer::~Buffer()
{
}
