#include "Buffer.h"

Buffer::Buffer()
{
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
}

HANDLE Buffer::getHandle()
{
	return hOutput;
}

void Buffer::test()
{
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);

	buffer[5][10].Char.AsciiChar = 'H';
	buffer[5][10].Attributes = 0x0E;
	buffer[5][11].Char.AsciiChar = 'i';
	buffer[5][11].Attributes = 0x0B;
	buffer[5][12].Char.AsciiChar = '!';
	buffer[5][12].Attributes = 0x0A;
}

void Buffer::display()
{
	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}

Buffer::~Buffer()
{
}
