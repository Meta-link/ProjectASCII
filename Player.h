#pragma once
#include <vector>
#include "Caractere.h"
#include "windows.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Player
{
public:
	Player();
	Player(string _name, WORD _color);
	Player(string _name, WORD _color, int posQgX, int posQgY);
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
	Caractere getQg();
	void loadUnitsFromFile(string filename);

private:
	string name;
	WORD color;
	vector<Caractere*> units;
	vector<Caractere*>::iterator it;
	Caractere qg;
};