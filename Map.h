#pragma once
#include "Case.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

// Dimensions de la map (doit tenir dans le buffer)
#define MAP_WIDTH 80
#define MAP_HEIGHT 40

// Couleurs utilisées sur la map
#define MAP_COLOR_GREEN 0x0020
#define MAP_COLOR_BLUE 0x0030

class Map
{
public:
	Map();
	Map(string filename);
	~Map();
	Case getCase(int x, int y);
	bool canMove(int x, int y);
	void triggerCase(int x, int y);

private:
	Case cases[MAP_WIDTH][MAP_HEIGHT];
};

