#include <iostream>
#include <vector>

#include "Buffer.h"
#include "Input.h"
#include "Case.h"
#include "Map.h"
#include "Caractere.h"
#include "Player.h"

#include "NYTimer.cpp"

using namespace std;

Buffer buffer;
NYTimer timer;
Input input;
Map map;

void init() {
	//Creation de la map
	map = Map("map.map");
	
	//Creation du buffer
	//buffer = Buffer();
	buffer.editMap(map);

	//Creation du manager d'input
	input = Input();

	//Creation du timer
	timer = NYTimer();
	timer.start();
}

int main()
{
	//INITIALISATIONS
	init();

	Player j1("Joueur 1");
	Player j2("Jean-Luc");

	Caractere bob = Caractere('T',15,15,10);
	Caractere boby = Caractere('T', 15, 16, 5);

	j1.addUnit(&bob);
	j2.addUnit(&boby);

	j1.start();
	j2.start();
	Player &currentPlayer = j1;
	bool turn = true;


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

			if(map.canMove(currentPlayer.getUnitX() + x, currentPlayer.getUnitY() + y))
			{
				if(currentPlayer.moveUnit(x, y)) //Vrai si pm = 0 on passe au deplacement suivant
				{
					currentPlayer.nextUnit();

					//Passage au joueur suivant
					turn = !turn;
					if (turn)
					{
						currentPlayer = j1;
					}
					else
					{
						currentPlayer = j2;
					}
				}
			}

			//Rafraichissement de l'affichage
			buffer.editMap(map);
			buffer.editCar(j1.getCar());
			buffer.editCar(j2.getCar());
			buffer.editHUD(currentPlayer.getName(), currentPlayer.getPm());
			buffer.display();
		}

		
	}
}

