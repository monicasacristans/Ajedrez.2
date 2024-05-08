#include "Torre.h"
#include <iostream>

Torre::Torre(tipo t, color c) :Pieza(t, c) {}


bool Torre::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

	if (origen.x != destino.x && origen.y != destino.y) {
		return false; // Las torres se mueven solo en línea recta.
		std::cout << "NO PUEDES" << std::endl;
	}

	if (origen.x == destino.x) {
		int movY = (destino.y > origen.y) ? 1 : -1;
		for (int y = origen.y + movY; y != destino.y; y += movY) {
			if (tablero[origen.x][y] != nullptr) {
				return false;
			}
		}
	}
	else if (origen.y == destino.y) {
		int movX = (destino.x > origen.x) ? 1 : -1;
		for (int x = origen.x + movX; x != destino.x; x += movX) {
			if (tablero[x][origen.y] != nullptr) {
				return false;
			}
		}
	}
	return true;
}
