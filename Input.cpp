#include "Input.h"
#include <iostream>

using namespace std;

Input::Input()
{
	//Recuperation du handle pour les inputs
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
}

int Input::getInput()
{
	DWORD i;

	if(ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead))
	{
		for (i = 0; i < cNumRead; i++)
		{
			//Traitement des inputs
			if (irInBuf[i].EventType == KEY_EVENT)
			{
				return (int)irInBuf[i].Event.KeyEvent.wVirtualScanCode;
			}
				
		}
	}
	return 0;
}

Input::~Input()
{
}
