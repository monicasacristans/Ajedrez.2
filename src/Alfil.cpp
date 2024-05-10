#include "Alfil.h"
#include <iostream>

Alfil::Alfil(tipo t, color c) :Pieza(t, c) {}

bool Alfil::movimientoValido(casilla origen, casilla destino, Pieza* tablero[max_y][max_x]) {

	// Sentido del movimiento de las piezas 
	int movX = (destino.x > origen.x) ? 1 : -1;		//+1 hacia arriba, -1 hacia abajo
	int movY = (destino.y > origen.y) ? 1 : -1;		//+1 hacia la derecha, -1 hacia la izquierda

	int x = origen.x + movX;
	int y = origen.y + movY;


	if (abs(destino.x - origen.x) != abs(destino.y - origen.y)) {
		return false; // El movimiento no es en diagonal
	}

	// Movimiento en diagonal mientras no haya una pieza en medio
	if (tablero[destino.y][destino.x] != nullptr) {	
		if (tablero[destino.y][destino.x]->getColor() != this->getColor()) {	// No comerse una ficha del mismo color
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