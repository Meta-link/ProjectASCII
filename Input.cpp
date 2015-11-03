#include "Input.h"
#include <iostream>

using namespace std;

Input::Input()
{
	//Recuperation du handle pour les inputs
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
}

void Input::getInput()
{
	DWORD i;

	if(ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead))
	{
		for (i = 0; i < cNumRead; i++)
		{
			//Traitement des inputs
			if (irInBuf[i].EventType == KEY_EVENT)
				cout << "touche pressee" << endl;
		}
	}
		
}

Input::~Input()
{
}
