#include "Torre.h"
#include <iostream>

Torre::Torre(tipo t, color c) :Pieza(t, c) {}


bool Torre::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

	if (origen.x != destino.x && origen.y != destino.y) {
		return false; // Las torres se mueven solo en línea recta.
		std::cout << "NO PUEDES" << std::endl;
	}
	//Movimiento horizontal
	if (origen.x == destino.x) {
		// Verificar si hay una pieza en el destino y es del color opuesto
		if (tablero[destino.y][destino.x] != nullptr) {
			if (tablero[destino.y][destino.x]->getColor() != getColor()) {
				int movY = (destino.y > origen.y) ? 1 : -1;
				for (int i = origen.y + movY; i != destino.y; i += movY) {
					if (tablero[i][origen.x] != nullptr) {
						return false;//No puede moverse, hay una pieza de por medio
					}
					else
						return true;//Si puede moverse
				}
			}
			else
				return false;
		}
	}//Movimiento vertical
	else if (origen.y == destino.y) {
		// Verificar si hay una pieza en el destino y es del color opuesto
		if (tablero[destino.y][destino.x] != nullptr) {
			if (tablero[destino.y][destino.x]->getColor() != getColor()) {
				int movX = (destino.x > origen.x) ? 1 : -1;
				for (int j = origen.x + movX; j != destino.x; j += movX) {
					if (tablero[origen.y][j] != nullptr) {
						return false;//No puede moverse, hay una pieza de por medio
					}
					else
						return true;//Si puede moverse
				}
			}
			else
				return false;
		}
	}
	return true;
}
