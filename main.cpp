#include <iostream>
#include <chrono>
#include <thread>

#include "Buffer.h"
#include "Case.h"

#include "NYTimer.cpp"

using namespace std;

Buffer buffer;
NYTimer timer;


void init() {
	
	//Cr�ation du buffer
	buffer = Buffer::Buffer();
	buffer.test();

	//Cr�ation du timer
	timer = NYTimer::NYTimer();
	timer.start();
}

int main()
{
	init();

	//BOUCLE PRINCIPALE
	while (true) {

		//Refresh de l'�cran toutes les secondes
		if (timer.getElapsedSeconds(1))
		{
			buffer.display();
		}

	}
}

