#include "Case.h"


Case::Case(char caractere, int attributs, bool caseBloquante)
{
	valeur.Char.UnicodeChar = caractere;
	valeur.Attributes = attributs;
	block = caseBloquante;
}

void Case::setCase(CHAR_INFO v) {
	valeur = v;
}

void Case::setCase(char caractere, int attributs, bool caseBloquante) {
	valeur.Char.UnicodeChar = caractere;
	valeur.Attributes = attributs;
	block = caseBloquante;
}

int Case::getAttribute() {
	return valeur.Attributes;
}

char Case::getCaractere() {
	return valeur.Char.UnicodeChar;
}


Case::~Case()
{
}
