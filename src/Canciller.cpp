#include "Canciller.h"


Canciller::Canciller(tipo t, color c) :Pieza(t, c) {}

bool Canciller::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
	//Se mueve indistintamente como torre o caballo
	
	int movYC = abs(destino.y - origen.y);
	int movXC = abs(destino.x - origen.x);

	// Sentido del movimiento de las piezas 
	int movYT = (destino.y > origen.y) ? 1 : -1;		//+1 hacia la derecha, -1 hacia la izquierda
	int movXT = (destino.x > origen.x) ? 1 : -1;		//+1 hacia arriba, -1 hacia abajo

	//MOVIMIENTO TORRE
	if (origen.x == destino.x && origen.y == destino.y) {
		//Movimiento horizontal
		if (origen.x == destino.x) {
			
			if (tablero[destino.y][destino.x] != nullptr) {
				if (tablero[destino.y][destino.x]->getColor() != this->getColor()) {
					
					int movY = (destino.y > origen.y) ? 1 : -1;
					for (int i = origen.y + movYT; i != destino.y; i += movYT) {
						if (tablero[i][origen.x] != nullptr) {
							return false;	// Hay una pieza en el camino
						}
					}
				}
				else {
					return false;
				}
			}
		}

		//Movimiento vertical
		else if (origen.y == destino.y) {
			
			if (tablero[destino.y][destino.x] != nullptr) {
				if (tablero[destino.y][destino.x]->getColor() != this->getColor()) {
					
					int movX = (destino.x > origen.x) ? 1 : -1;
					for (int j = origen.x + movXT; j != destino.x; j += movXT) {
						if (tablero[origen.y][j] != nullptr) {
							return false;	// Hay una pieza en el camino
						}
					}
				}
				else {
					return false;
				}
			}
		}
	}
	//MOVIMIENTO CABALLO
	else if ((movYC == 1 && movXC == 2) || (movYC == 2 && movXC == 1)) {
		if (tablero[destino.y][destino.x] != nullptr) {
			if (tablero[destino.y][destino.x]->getColor() != this->getColor()) {
				return true;	// Puede comer
			}
			else
				return false;	// No puede comer, pieza del mismo color
		}
		else
			return true;
	}
	else {
		return false;
	}
}