#pragma once
#include <vector>
#include "Caractere.h"

using namespace std;

class Player
{
public:
	Player();
	Player(string _name);
	void start();
	void addUnit(Caractere* c);
	bool moveUnit(int x, int y);
	void nextUnit();
	int getPm();
	string getName();
	vector<Caractere*> getCar();
	int getUnitX();
	int getUnitY();
	~Player();

private:
	string name;
	vector<Caractere*> units;
	vector<Caractere*>::iterator it;
};

