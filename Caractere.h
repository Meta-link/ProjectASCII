#pragma once
#include <iostream>

class Caractere
{
public:
	Caractere();
	Caractere(char c, int x, int y);
	char getCaractere();
	int getX();
	int getY();
	void move(int x, int y);
	~Caractere();

private:
	char caractere;
	int x, y;
};

