#pragma once
#include <stdio.h>
#include <windows.h>

class Input
{
public:
	Input();
	void getInput();
	~Input();

private:
	HANDLE hStdin;
	DWORD cNumRead, fdwMode;
	INPUT_RECORD irInBuf[128];
};

