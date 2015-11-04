#include "Case.h"

// Construit une case
Case::Case(char caractere, int attributs, bool caseBloquante, TYPE_CASE t)
{
	valeur.Char.UnicodeChar = caractere;
	valeur.Attributes = attributs;
	block = caseBloquante;
	type = t;
}

// Change la valeur d'une case
void Case::setCase(CHAR_INFO v) {
	valeur = v;
}

// Change la valeur d'une case
void Case::setCase(char caractere, int attributs, bool caseBloquante) {
	valeur.Char.UnicodeChar = caractere;
	valeur.Attributes = attributs;
	block = caseBloquante;
}

// Retourne les attributs d'une case
int Case::getAttribute() {
	return valeur.Attributes;
}

// Retourne le caract�re d'une case
char Case::getCaractere() {
	return valeur.Char.UnicodeChar;
}


Case::~Case()
{
}
