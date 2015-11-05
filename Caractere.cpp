#include "Caractere.h"

Caractere::Caractere()
{
}

Caractere::Caractere(char _caractere, int _x, int _y, int _pm)
{
	caractere = _caractere;
	x = _x;
	y = _y;
	pmMax = _pm;
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
	if(pm <= 0) //Si pm = 0 on passe retourne vrai pour passer a l'unite suivante
	{
		pm = pmMax;
		return true;
	}
	return false;
}

Caractere::~Caractere()
{
}
