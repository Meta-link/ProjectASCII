#include "Case.h"


Case::Case(char caractere, int attributs)
{
	valeur.Char.UnicodeChar = caractere;
	valeur.Attributes = attributs;
}

void Case::setCase(CHAR_INFO v) {
	valeur = v;
}

void Case::setCase(char caractere, int attributs) {
	valeur.Char.UnicodeChar = caractere;
	valeur.Attributes = attributs;
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
