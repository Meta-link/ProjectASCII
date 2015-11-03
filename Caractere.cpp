#include "Caractere.h"

Caractere::Caractere()
{
}

Caractere::Caractere(char c, int posX, int posY)
{
	caractere = c;
	x = posX;
	y = posY;
}

char Caractere::getCaractere()
{
	return caractere;
}

int Caractere::getX()
{
	return x;
}

int Caractere::getY()
{
	return y;
}

void Caractere::move(int mX, int mY)
{
	x += mX;
	y += mY;
}

Caractere::~Caractere()
{
}
