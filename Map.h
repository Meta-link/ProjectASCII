#pragma once
#include "Case.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

#define MAP_WIDTH 80
#define MAP_HEIGHT 25

class Map
{
public:
	Map();
	Map(string filename);
	~Map();
	Case getCase(int x, int y);

private:
	Case cases[MAP_WIDTH][MAP_HEIGHT];
};

