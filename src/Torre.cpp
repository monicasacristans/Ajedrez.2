#include "Torre.h"
#include <iostream>

Torre::Torre(tipo t, color c) :Pieza(t, c) {}


bool Torre::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {
	int movY = (destino.y > origen.y) ? 1 : -1;
	int movX = (destino.x > origen.x) ? 1 : -1;

	if (origen.x != destino.x && origen.y != destino.y) {
		std::cout << "NO PUEDES" << std::endl;
		return false; // Las torres se mueven solo en línea recta.
	}
	//Movimiento horizontal
	if (origen.x == destino.x) {
		//Asegurarnos que no se puede comer una pieza del mismo color que el suyo
		if (tablero[destino.y][destino.x] != nullptr) {
			if(tablero[destino.y][destino.x]->getColor() != this->getColor()){
				// Verificar si hay una pieza en el destino y es del color opuesto
				for (int i = origen.y + movY; i != destino.y; i += movY) {
					if (tablero[i][origen.x] != nullptr) {
						return false;
					}
				}
			}
			else {
				return false;
			}
		}
	}//Movimiento vertical
	else if (origen.y == destino.y) {
		// Asegurarnos que no se puede comer una pieza del mismo color que el suyo
		if (tablero[destino.y][destino.x] != nullptr) {
			if (tablero[destino.y][destino.x]->getColor() != this->getColor()) {
				// Verificar si hay una pieza en el destino y es del color opuesto
				for (int j = origen.x + movX; j != destino.x; j += movX) {
					if (tablero[origen.y][j] != nullptr) {
						return false;
					}
				}
			}
			else {
				return false;
			}
		}
	}

	return true;
}
