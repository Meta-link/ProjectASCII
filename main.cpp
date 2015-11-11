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

	// Cr�ation des joueurs
	Player j1("Jean-Ascii", FOREGROUND_BLUE, 63, 30);
	Player j2("Jean-Luc", FOREGROUND_RED, 60, 32);

	// Cr�ation des unit�s du joueur
	Caractere t1 = Caractere('T', 15, 8, 5);
	Caractere t2 = Caractere('T', 64, 30, 5);

	Caractere s1 = Caractere('S', 11, 6, 10);
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
	while(winner == 0 || !GetAsyncKeyState(VK_ESCAPE)) {

		int x = 0;
		int y = 0;

		//Refresh de l'�cran toutes les 300 millisecondes
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
				// R�cup�ration de la destination du joueur (avant de se d�placer)
				int destX = players[indice]->getUnitX() + x, destY = players[indice]->getUnitY() + y;
				// Pour chaque joueur on v�rifie si on n'est pas sur son QG (� changer, pas tr�s propre)
				for (int i = 0; i < playerCount; i++) {
					// Sauf pour le joueur en train de jouer
					if (i != indice) {
						int qgX = players[i]->getQg().getX();
						int qgY = players[i]->getQg().getY();

						// Si on est sur le QG d'un autre
						if (destX == qgX && destY == qgY) {
							winner = indice+1;
						}
					}
				}

				if (map.canMove(destX, destY)) //On verifie qu'on peut aller sur la case (collisions avec le decor)
				{
					if(players[indice]->moveUnit(x, y)) //Vrai si pm = 0 on passe au deplacement suivant
					{
						players[indice]->nextUnit(); //On passe � l'unite et au joueur suivant
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

	while(!GetAsyncKeyState(VK_ESCAPE))
	{
			/*buffer.yolo();
			buffer.display();*/
		cout << "mdr" << endl;
	}
}

