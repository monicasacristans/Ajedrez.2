#include "Arzobispo.h"

Arzobispo::Arzobispo(tipo t, color c) :Pieza(t, c) {}

bool Arzobispo::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
	//Se mueve indistintamente como torre o alfil

	int movXAlfil = (destino.x > origen.x) ? 1 : -1;
	int movYAlfil = (destino.y > origen.y) ? 1 : -1;

	int movXCaballo = abs(destino.x - origen.x); 
	int movYCaballo = abs(destino.y - origen.y);

	int x = origen.x + movXAlfil;
	int y = origen.y + movYAlfil;

	//MOVIMIENTO CABALLO
	if ((movXCaballo == 2 && movYCaballo == 1) || (movXCaballo == 1 && movYCaballo == 2)) {
		if (tablero[destino.y][destino.x] != nullptr) {
			if (tablero[destino.y][destino.x]->getColor() != this->getColor()) {
				return true;	// Puede comer
			}
			else
				return false;	// No puede comer, pieza del mismo color
		}
		else {
			return true;
		}
	}

	//MOVIMIENTO ALFIL
	else if (abs(destino.x - origen.x) == abs(destino.y - origen.y)) {
			if (tablero[destino.y][destino.x] != nullptr) {
				if (tablero[destino.y][destino.x]->getColor() != this->getColor()) {
					while (x != destino.x && y != destino.y) {
						if (tablero[y][x] != nullptr) {
							return false; // Hay una pieza en el camino
					}
						x += movXAlfil;
						y += movYAlfil;
					}
				}
				else
					return false;
			}else 
				return true;
	}
	else {
		return false;
	}
}