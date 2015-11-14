#include "Player.h"


Player::Player()
{
}

Player::Player(string _name, WORD _color)
{
	name = _name;
	color = _color;

	qg = Caractere('Q', 10, 20, 0);
}

Player::Player(string _name, WORD _color, int posQgX, int posQgY)
{
	name = _name;
	color = _color;

	qg = Caractere('Q', posQgX, posQgY, 0);
}

void Player::start()
{
	it = units.begin();
}

void Player::addUnit(Caractere* c)
{
	units.push_back(c);
}

bool Player::moveUnit(int x, int y)
{
	return (*it)->move(x, y);
}

void Player::nextUnit()
{	
	if((it != units.end()) && (it+1 == units.end())) //Si c'est le dernier Caractere d'un joueur on passe au suivant
	{
		it = units.begin();
	}
	else
	{
		it++;
	}
}

int Player::getPm()
{
	return (*it)->getPm();
}

string Player::getName()
{
	return name;
}

WORD Player::getColor()
{
	return color;
}

vector<Caractere*> Player::getCar()
{
	return units;
}

int Player::getUnitX()
{
	return (*it)->getX();
}

int Player::getUnitY()
{
	return (*it)->getY();
}

Player::~Player()
{
}

Caractere Player::getQg()
{
	return qg;
}

void Player::loadUnitsFromFile(string filename)
{
	ifstream file(filename);
	string str, sub;
	

	// Lecture ligne par ligne
	while (std::getline(file, str)) {
		int counter = 0;
		char c;
		int posX, posY, pm;

		// Split
		istringstream iss(str);
		do {
			iss >> sub;

			switch (counter) {
			case 0:
				c = sub[0];
				break;
			case 1:
				posX = stoi(sub);
				break;
			case 2:
				posY = stoi(sub);
				break;
			case 3:
				pm = stoi(sub);
				break;
			}

			counter++;

		} while (iss);

		Caractere carac = Caractere(c, posX, posY, pm);
		addUnit(&carac);
	}
}

bool Player::hasUnitAtPos(int x, int y)
{
	for (auto &u : units) {
		if (x == u->getX() && y == u->getY())
			return true;
	}

	return false;
}
