#pragma once
#include "windows.h"

class Case
{
public:
	Case(char caractere = '.', int attributs = 0x0F);
	~Case();

	void setCase(CHAR_INFO v);
	void setCase(char caractere, int attributs);

	int getAttribute();
	char getCaractere();
private:
	CHAR_INFO valeur;
};

