#pragma once
#include "windows.h"

class Case
{
public:
	enum TYPE_CASE {
		TERRAIN,
		QG,
		BONUS
	};

	Case(char caractere = '.', int attributs = 0x0F, bool caseBloquante = false, TYPE_CASE t = TYPE_CASE::TERRAIN);
	~Case();

	void setCase(CHAR_INFO v);
	void setCase(char caractere, int attributs, bool caseBloquante);

	int getAttribute();
	char getCaractere();

	bool block = false;
	TYPE_CASE type;
private:
	CHAR_INFO valeur;
};

