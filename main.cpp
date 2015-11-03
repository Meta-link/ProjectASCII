#include <iostream>

#include "Buffer.h"
#include "Input.h"
#include "Case.h"
#include "Map.h"

#include "NYTimer.cpp"

using namespace std;

Buffer buffer;
NYTimer timer;
Input input;

void init() {
	
	//Creation du buffer
	buffer = Buffer::Buffer();
	buffer.test();

	//Creation du manager d'input
	input = Input::Input();

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
			//buffer.display();
		}

		//Recuperation et traitement des inputs
		input.getInput();
	}
}

