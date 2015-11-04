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

bool Caractere::move(int mX, int mY)
{
	if(mX != 0 || mY != 0)
	{
		x += mX;
		y += mY;
		pm -= 1;
		if(pm <= 0)
		{
			pm = pmMax;
			return true;
		}
	}
	return false;
}

Caractere::~Caractere()
{
}
