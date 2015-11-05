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
