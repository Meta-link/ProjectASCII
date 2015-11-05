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

	Player j1("Jean-Ascii", FOREGROUND_BLUE, 11, 5);
	Player j2("Jean-Luc", FOREGROUND_RED, 60, 32);

	Caractere bob = Caractere('T',15,15,5);
	Caractere boby = Caractere('T', 15, 16, 5);
	Caractere bobette = Caractere('I', 20, 20, 5);

	j1.addUnit(&bob);
	j1.addUnit(&bobette);
	j2.addUnit(&boby);

	j1.start();
	j2.start();

	int playerCount = 2;
	Player** players = new Player*[playerCount];
	players[0] = &j1; 
	players[1] = &j2;
	int indice = 0;

	bool yolo = false;

	//BOUCLE PRINCIPALE
	while (!GetAsyncKeyState(VK_ESCAPE) || yolo) {

		int x = 0;
		int y = 0;

		//Refresh de l'écran toutes les 300 millisecondes
		if(timer.getElapsedMs(300) != 0)
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

			if (x != 0 || y != 0)
			{
				// Récupération de la destination du joueur (avant de se déplacer)
				int destX = players[indice]->getUnitX() + x, destY = players[indice]->getUnitY() + y;
				// Pour chaque joueur on vérifie si on n'est pas sur son QG (à changer, pas très propre)
				for (int i = 0; i < playerCount; i++) {
					// Sauf pour le joueur en train de jouer
					if (i != indice) {
						int qgX = players[i]->getQg().getX();
						int qgY = players[i]->getQg().getY();

						// Si on est sur le QG d'un autre
						if (destX == qgX && destY == qgY) {
							int a = 0;
							// TODO: Faire quelque chose
							yolo = true;
						}
					}
				}

				if (map.canMove(destX, destY)) //On verifie qu'on peut aller sur la case (collisions avec le decor)
				{
					if(players[indice]->moveUnit(x, y)) //Vrai si pm = 0 on passe au deplacement suivant
					{
						players[indice]->nextUnit(); //On passe à l'unite et au joueur suivant
						indice = (indice + 1) % 2;
					}
				}
			}

			//Rafraichissement de l'affichage
			buffer.editMap(map);
			buffer.editCar(j1);
			buffer.editCar(j2);
			buffer.editHUD(players[indice]->getName(), players[indice]->getPm());
			buffer.display();

			if (yolo) buffer.yolo();
		}

		
	}
}

