#include "Alfil.h"
#include <iostream>

Alfil::Alfil(tipo t, color c) :Pieza(t, c) {}

bool Alfil::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

	int movX = (destino.x > origen.x) ? 1 : -1;
	int movY = (destino.y > origen.y) ? 1 : -1;

	int x = origen.x + movX;
	int y = origen.y + movY;

	if (abs(destino.x - origen.x) != abs(destino.y - origen.y)) {
		return false; // El movimiento no es en diagonal
	}

	if (tablero[destino.y][destino.x] != nullptr) {
		if (tablero[destino.y][destino.x]->getColor() != this->getColor()) {
			while (x != destino.x && y != destino.y) {
				if (tablero[y][x] != nullptr) {
					return false; // Hay una pieza en el camino
				}
				x += movX;
				y += movY;
			}
		}
	}

	return true;
}