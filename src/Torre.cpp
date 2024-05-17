#include "Torre.h"

Torre::Torre(tipo t, color c) :Pieza(t, c) {}


bool Torre::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

	// Sentido del movimiento de las piezas 
	int movY = (destino.y > origen.y) ? 1 : -1;		//+1 hacia la derecha, -1 hacia la izquierda
	int movX = (destino.x > origen.x) ? 1 : -1;		//+1 hacia arriba, -1 hacia abajo

	if (origen.x != destino.x && origen.y != destino.y) {
		return false; // Las torres se mueven solo en línea recta.
	}

	//Movimiento horizontal
	if (origen.x == destino.x) {
		
		if (tablero[destino.y][destino.x] != nullptr) {
			if(tablero[destino.y][destino.x]->getColor() != this->getColor()){
				
				for (int i = origen.y + movY; i != destino.y; i += movY) {
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
				
				for (int j = origen.x + movX; j != destino.x; j += movX) {
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
