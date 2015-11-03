#include <iostream>

#include "Buffer.h"
#include "Case.h"

#include "NYTimer.cpp"

using namespace std;

Buffer buffer;
NYTimer timer;

void init() {
	
	//Creation du buffer
	buffer = Buffer::Buffer();
	buffer.test();

	//Creation du timer
	timer = NYTimer::NYTimer();
	timer.start();
}

int main()
{
	init();

	//BOUCLE PRINCIPALE
	while (true) {

		//Refresh de l'écran toutes les secondes
		if (timer.getElapsedSeconds(1))
		{
			buffer.display();
		}
	}
}

