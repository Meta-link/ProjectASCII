#include <iostream>
#include <vector>

#include "Buffer.h"
#include "Input.h"
#include "Case.h"
#include "Map.h"
#include "Caractere.h"

#include "NYTimer.cpp"

using namespace std;

Buffer buffer;
NYTimer timer;
Input input;
vector<Caractere> car;

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

	Caractere bob = Caractere::Caractere('O',5,5);
	car.push_back(bob);

	//BOUCLE PRINCIPALE
	while(!GetAsyncKeyState(VK_ESCAPE)) {

		int x = 0;
		int y = 0;

		//Refresh de l'écran toutes les secondes
		if(timer.getElapsedMs(300))
		{
			//Recuperation et traitement des inputs
			switch(input.getInput())
			{
				//HAUT
			case 72:
				y = -1;
				break;
				//DROITE
			case 77:
				x = 1;
				break;
				//BAS
			case 80:
				y = 1;
				break;
				//GAUCHE
			case 75:
				x = -1;
				break;
				//ESPACE
			case 57:
				break;
			case 0:
				break;
			default:
				break;
			}
			bob.move(x, y);

			//Rafraichissement de l'affichage
			buffer.edit(bob);
			buffer.display();
		}

		
	}
}

