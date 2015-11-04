#pragma once
#include "windows.h"
#include <vector>
#include "Caractere.h"
#include "Map.h"
#include <conio.h>
#include <strsafe.h>

//Taille de la console en caracteres
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 40

#define FOREGROUND 0x000F

using namespace std;

class Buffer
{
public:
	Buffer();
	void test();
	void display();
	void editMap(Map m);
	void editCar(vector<Caractere*> caracteres);
	void editHUD(string joueur, int pm);
	~Buffer();

private:
	HANDLE hOutput;
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
};