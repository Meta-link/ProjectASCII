#pragma once
#include "windows.h"

// Taille de la console en caract�res
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

class Buffer
{
public:
	Buffer();
	void test();
	void display();
	~Buffer();

	HANDLE hOutput;
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
};
