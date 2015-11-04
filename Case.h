#pragma once
#include "windows.h"

class Case
{
public:
	Case(char caractere = '.', int attributs = 0x0F, bool caseBloquante = false);
	~Case();

	void setCase(CHAR_INFO v);
	void setCase(char caractere, int attributs, bool caseBloquante);

	int getAttribute();
	char getCaractere();

	bool block = false;
private:
	CHAR_INFO valeur;
};

