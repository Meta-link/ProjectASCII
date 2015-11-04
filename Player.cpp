#include "Player.h"


Player::Player(string _name)
{
	name = _name;
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
	if(it == units.end()-1) //Si c'est le dernier Caractere d'un joueur on passe au suivant
	{
		it = units.begin();
	}
	else
	{
		++it;
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
