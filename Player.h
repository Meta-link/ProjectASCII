#pragma once
#include <vector>
#include "Caractere.h"
#include "windows.h"

using namespace std;

class Player
{
public:
	Player();
	Player(string _name, WORD _color);
	void start();
	void addUnit(Caractere* c);
	bool moveUnit(int x, int y);
	void nextUnit();
	int getPm();
	string getName();
	WORD getColor();
	vector<Caractere*> getCar();
	int getUnitX();
	int getUnitY();
	~Player();

private:
	string name;
	WORD color;
	vector<Caractere*> units;
	vector<Caractere*>::iterator it;
};