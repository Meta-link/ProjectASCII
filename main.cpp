#include <iostream>
#include <chrono>
#include <thread>

#include "Buffer.h"

#include "NYTimer.cpp"

using namespace std;

Buffer buffer;
NYTimer timer;


void init() {
	
	//Création du buffer
	buffer = Buffer::Buffer();
	buffer.test();

	//Création du timer
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

