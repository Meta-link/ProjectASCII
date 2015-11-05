#include "Input.h"
#include <iostream>

using namespace std;

Input::Input()
{
	//Recuperation du handle pour les inputs
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	repeat = false;
}

int Input::getInput()
{
	DWORD i;

	if(ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead))
	{
		for (i = 0; i < cNumRead; i++)
		{
			//Traitement des inputs
			if (irInBuf[i].EventType == KEY_EVENT && !repeat && irInBuf[i].Event.KeyEvent.bKeyDown)
			{
				repeat = true; //On empeche la repetition des inputs
				return (int)irInBuf[i].Event.KeyEvent.wVirtualScanCode; //On renvoie le code de la touche pressee
			}
			else if(repeat && !irInBuf[i].Event.KeyEvent.bKeyDown) //Si la touche est relachee on permet un nouvel input
			{
				repeat = false;
			}
				
		}
	}
	return 0;
}

Input::~Input()
{
}
