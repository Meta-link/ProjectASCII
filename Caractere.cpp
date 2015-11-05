#include "Caractere.h"

Caractere::Caractere()
{
}

Caractere::Caractere(char c, int posX, int posY, int moves)
{
	caractere = c;
	x = posX;
	y = posY;
	pmMax = moves;
	pm = pmMax;
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

int Caractere::getPm()
{
	return pm;
}

bool Caractere::move(int mX, int mY)
{
	x += mX;
	y += mY;
	pm -= 1;
	if(pm <= 0)
	{
		pm = pmMax;
		return true;
	}
	return false;
}

Caractere::~Caractere()
{
}
