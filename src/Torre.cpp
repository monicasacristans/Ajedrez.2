#include "Torre.h"

Torre::Torre(tipo t, color c) :Pieza(t, c) {}


bool Torre::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

	//MOVIMIENTO TORRE
	if (origen.x == destino.x || origen.y == destino.y) {
		if (origen.x == destino.x) {
			// Movimiento vertical
			int movY = (destino.y > origen.y) ? 1 : -1;
			for (int i = origen.y + movY; i != destino.y; i += movY) {
				if (tablero[i][origen.x] != nullptr) {
					return false; // Hay una pieza en el camino
				}
			}
		}
		else {
			// Movimiento horizontal
			int movX = (destino.x > origen.x) ? 1 : -1;
			for (int j = origen.x + movX; j != destino.x; j += movX) {
				if (tablero[origen.y][j] != nullptr) {
					return false; // Hay una pieza en el camino
				}
			}
		}

		if (tablero[destino.y][destino.x] != nullptr) {
			if (tablero[destino.y][destino.x]->getColor() == this->getColor()) {
				return false; // No puede capturar una pieza del mismo color
			}
		}
		return true; // Movimiento válido de torre
	}
	else {
		return false;
	}
	
}
