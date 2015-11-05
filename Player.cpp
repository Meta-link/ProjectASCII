#include "Player.h"


Player::Player()
{
}

Player::Player(string _name, WORD _color)
{
	name = _name;
	color = _color;
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
	//++it;
	////it = units.begin();
	//vector<Caractere*>::iterator tmp = units.end()-1;
	//int a = 0;
	////if ((it == units.end()-1))// && (it + 1 == units.end()))
	///*if (it != tmp)
	//	cout << "mdr" << endl;*/
	////if (it != units.end()-1)
	//	cout << "1" << endl;
	
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