#pragma once
#include <iostream>

class Caractere
{
public:
	Caractere();
	Caractere(char c, int x, int y, int pm);
	char getCaractere();
	int getX();
	int getY();
	int getPm();
	bool move(int x, int y);
	~Caractere();

private:
	char caractere;
	int x, y;
	int pmMax, pm;
};

