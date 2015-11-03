#include "Map.h"


Map::Map()
{
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			cases[i][j] = Case();
		}
	}
}

Case Map::getCase(int x, int y) {
	return cases[x][y];
}

Map::~Map()
{
}
