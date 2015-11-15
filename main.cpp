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

	// Création des joueurs
	Player j1("Jean-Ascii", FOREGROUND_BLUE, 63, 30);
	Player j2("Jean-Luc", FOREGROUND_RED, 60, 32);

	// Création des unités du joueur
	Caractere t1 = Caractere('T', 67, 28, 25);
	Caractere t2 = Caractere('T', 64, 30, 25);

	Caractere s1 = Caractere('S', 62, 31, 10);
	Caractere s2 = Caractere('S', 60, 33, 10);

	j1.addUnit(&t1);
	j1.addUnit(&s1);

	j2.addUnit(&t2);
	j2.addUnit(&s2);

	j1.start();
	j2.start();

	int playerCount = 2;
	Player** players = new Player*[playerCount];
	players[0] = &j1; 
	players[1] = &j2;
	int indice = 0;

	int winner = 0;

	//BOUCLE PRINCIPALE
	while(!GetAsyncKeyState(VK_ESCAPE) && winner == 0) {

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

				// On verifie qu'on peut aller sur la case (collisions avec le decor)
				if (map.canMove(destX, destY)) 
				{
					int qgX = players[(indice + 1) % 2]->getQg().getX();
					int qgY = players[(indice + 1) % 2]->getQg().getY();
					if (destX == qgX && destY == qgY) {
						winner = indice + 1; //VICTOIRE
					}

					// Variable contenant l'index de l'unité sur laquelle on tombe (si elle existe)
					int index = 0;
					// Si l'adversaire a une unité sur le point de destination, retourne son index
					if (players[(indice + 1) % 2]->hasUnitAtPos(destX, destY, &index)) {
						// COLLISION, on tue l'unité
						players[(indice + 1) % 2]->removeUnitByIndex(index);
					}

					// Si il s'agit simplement de décors, tester la quantité de PM restants
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
		}
		//Fin du refresh
	}

	//Affichage du gagnant puis fin du programme
	buffer.win(winner);
	buffer.display();
	while (!GetAsyncKeyState(VK_ESCAPE));
}

